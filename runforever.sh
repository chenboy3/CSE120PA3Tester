#!/bin/bash

echo "Starting Autorun..."
counter=0
while $1
do
	((counter++))
	echo "**Script counter:  $counter**"
done

echo "**Script ran $counter times**"
