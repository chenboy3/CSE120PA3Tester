#!/bin/bash

echo "Starting Autorun..."
counter=0
while [ $counter -le 100 ]
do
	./massivetest $1
	((counter++))
	echo "**Script counter:  $counter**"
done

echo "**Script ran $counter times**"
