#!/bin/bash

cd ../
make clean
make


for filename in ./test/*
do
    ./ag < $filename > debug.log 2>/dev/null


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
