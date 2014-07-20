#!/bin/bash

make clean
make

mkdir log

for filename in ./tests/*
do
    ./parser < $filename > "./log/$( basename $filename).log" 2>/dev/null


    retval=$?


    if test $retval -eq ${filename:${#filename}-1}
    then
    	 echo "OK: $filename";
    else
    	 echo	"------------------";
    	 echo "FAILED: $filename";
    	 echo "Expected Output: ${filename:${#filename}-1}";
    	 echo "Current Output: $retval";
    	 echo	"------------------";
    fi
done
