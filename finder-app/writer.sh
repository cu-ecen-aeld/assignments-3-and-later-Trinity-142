#!/bin/bash

if [ $# -lt 2 ]
then
	echo "Wrong number of arguments"
	echo "Total number of arguments should be 2:"
	echo "	1) Full path to a file (including filename)"
	echo "	2) Text string which will be written within this file"	
	exit 1
fi

path=$(dirname "$1")
mkdir -p "$path"
if [ $? -ne 0 ]
then
	echo "Error: Failed to create directory $path" 
        exit 1
fi

echo $2 > $1
if [ $? -ne 0 ]
then
        echo "Error: Failed to write into the file"
        exit 1  
fi
