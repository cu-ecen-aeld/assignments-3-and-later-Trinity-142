#!/bin/sh

if [ $# -lt 2 ]
then
	echo "Wrong number of arguments"
	echo "Total number of arguments should be 2:"
	echo "	1) Directory path"
	echo "	2) String to be searched in the directory path"	
	exit 1
fi

if [ ! -d "$1" ]
then
	echo "$1 is not a directory"
	exit 1	
fi

X=$(find "$1" -type f | wc -l)
Y=$(grep -r "$2" "$1" | wc -l)
echo "The number of files are $X and the number of matching lines are $Y"
