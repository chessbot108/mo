
N=$1
D=$2

echo "N is ${N}, D is ${D}"

trial=1


#generic rand
generic_rand_trial_count=3
generic_rand_trial=1
g++ -std=c++20 -O2 generic_rand.cpp -o generic_rand
while [ $generic_rand_trial -le $generic_rand_trial_count ]
do
	./generic_rand $N $D $trial > ${trial}.in
	echo "${trial} test printed. used generic_rand as generator"
	trial=$((trial+1))
	generic_rand_trial=$((generic_rand_trial+1))
done
rm generic_rand

echo "'expr $trial -1'" > test_count.txt
