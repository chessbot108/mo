

#init

global_loc=$1
mkdir ${global_loc}
cd ${global_loc}

D_max=$2
D_inc=$3
N_max=$4
N_inc=$5


for ((D=$D_inc; D <= $D_max; D += $D_inc))
do
    for ((N=$N_inc; N <= $N_max; N += $N_inc)) 
    do
        trial_loc=test_${N}_${D}
        mkdir ${trial_loc}
        cd ${trial_loc}
        

        mv ../../../generators/* ./
        ./gen.sh ${N} ${D}
        mv ./*.cpp ../../../*generators
        mv ./*.sh ../../../generators
        
        
        mkdir testcases
        mv ./*.in ./testcases
        
        test_count=$(<test_count.txt)
        echo "test count is ${test_count}" 
        rm test_count.txt


        mkdir res
        cp ../../judger.cpp ./judger.cpp
        g++ -std=c++20 -O2 judger.cpp -o judger

        for ((alg=6; alg<=$#; alg++))
        do
            to_run=${!alg}
            mkdir ${to_run}
            cd ${to_run}
            g++ -std=c++20 -O2 -Wl,-stack_size,0x20000000 ../../../../prog/${to_run}.cpp -o ${to_run}
            for ((i=1; i<=${test_count}; i++))
            do
                ./${to_run} < ../testcases/${i}.in > ${i}.out
            done
            
            rm ${to_run}

            cd ..            
            ./judger ${to_run} ${test_count} > ./res/${to_run}.txt
            rm ./${to_run}/*
            rmdir ./${to_run}
        done
				rm ./testcases/*
				rmdir testcases
        mv ./res/* ./
        rmdir res
        rm judger.cpp
        rm judger
        cd ..
    done
    
done


cd ..
cd ..
