
N=$1
D=$2

echo "N is ${N}, D is ${D}"

trial=1


#generic rand
generic_rand_trial_count=5
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

#lines

hori_line_trial_count=1
hori_line_trial=1
g++ -std=c++20 -O2 hori_line.cpp -o hori_line
while [ $hori_line_trial -le $hori_line_trial_count ]
do
	./hori_line $N $D $trial > ${trial}.in
	echo "${trial} test printed. used hori line as generator"
	trial=$((trial+1))
	hori_line_trial=$((hori_line_trial+1))
done
rm hori_line

vert_line_trial_count=1
vert_line_trial=1
g++ -std=c++20 -O2 vert_line.cpp -o vert_line
while [ $vert_line_trial -le $vert_line_trial_count ]
do
	./vert_line $N $D $trial > ${trial}.in
	echo "${trial} test printed. use vert line as generator"
	trial=$((trial+1))
	vert_line_trial=$((vert_line_trial+1))
done
rm vert_line


diag_line_trial_count=1
diag_line_trial=1
g++ -std=c++20 -O2 diag_line.cpp -o diag_line
while [ $diag_line_trial -le $diag_line_trial_count ]
do
	./diag_line $N $D $trial > ${trial}.in
	echo "${trial} test printed. use diag line as generator"
	trial=$((trial+1))
	diag_line_trial=$((diag_line_trial+1))
done
rm diag_line


evenly_spaced_trial_count=2
evenly_spaced_trial=1
g++ -std=c++20 -O2 evenly_spaced.cpp -o evenly_spaced
while [ $evenly_spaced_trial -le $evenly_spaced_trial_count ]
do
	./evenly_spaced $N $D $trial > ${trial}.in
	echo "${trial} test printed. use evenly spaced as generator"
	trial=$((trial+1))
	evenly_spaced_trial=$((evenly_spaced_trial+1))
done
rm evenly_spaced


odd_evenly_spaced_trial_count=2
odd_evenly_spaced_trial=1
g++ -std=c++20 -O2 odd_evenly_spaced.cpp -o odd_evenly_spaced
while [ $odd_evenly_spaced_trial -le $odd_evenly_spaced_trial_count ]
do
	./odd_evenly_spaced $N $D $trial > ${trial}.in
	echo "${trial} test printed. use oddly evenly spaced as generator"
	trial=$((trial+1))
	odd_evenly_spaced_trial=$((odd_evenly_spaced_trial+1))
done
rm odd_evenly_spaced






trial=$((trial-1))

echo "${trial}" > test_count.txt
