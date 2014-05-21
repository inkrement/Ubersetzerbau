#!/bin/bash

make clean
make

mkdir log 2> /dev/null

POS=0
NEG=0
for filename in ./test/*
do
    ./ag < $filename > "./log/$( basename $filename).log" 2>/dev/null


    retval=$?


    if test $retval -eq ${filename:${#filename}-1}
    then
    	 echo "OK: $filename";
         ((POS++))
    else
    	 echo	"------------------";
    	 echo "FAILED: $filename";
    	 echo "Expected Output: ${filename:${#filename}-1}";
    	 echo "Current Output: $retval";
    	 echo	"------------------";
         ((NEG++))
    fi
done

echo -e "positive: $POS\nnegative: $NEG"
