#!/bin/bash

echo "Starting Tests Autorun..."
test_counter=1
while [ "$test_counter" -le 23 ]
do
	run_counter=0
	echo "**Running Test $test_counter**"
	while [ $run_counter -le 100 ]
	do
		./massivetest $test_counter
		((run_counter++))
		echo "**Script counter:  $run_counter**"
	done
	
	echo "**Script ran $run_counter times**"
	((test_counter++))
done
echo "Done."
