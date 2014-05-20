#!/bin/bash

make

testFolder=testFolder
targetFolder=tmp

mkdir -p $targetFolder 
#rm $targetFolder/*

let "i = 0"
lines=0

while read line
do
	if test -z "$line"
	then
		continue
	fi
	
	let "i += 1"
	
	IFS="#"
	parts=($line)

	name="$i"_${parts[0]}
	pars=${parts[1]}
	mycode=${parts[2]}
	ccode=${parts[3]}
	
	name=$(echo "${name}" | tr -d [:space:])
	pars=$(echo "${pars}" | tr -d [:space:])


	if test -n "$1"
	then
		if [[ $name =~ $1 ]];
		then
			echo > /dev/null
		else
			continue
		fi
	fi

	source=$testFolder/$pars
	target=$targetFolder/$name

	IFS=""

	ccode="${ccode//\//\\\\ESC}"
	ccode=$(sed -e "s/INSERT/$ccode/g" $source.c)
	ccode="${ccode//\\ESC//}"
	echo $ccode > $target.c

	ccode="${ccode//\//\\\\ESC}"
	mycode=$(sed -e "s/INSERT/$mycode/g" $source.my)
	ccode="${ccode//\\ESC//}"
	echo $mycode > $target.my

	./codea < $target.my > $target.s
	
    retval=$?

    if test $retval -eq 0
    then
        gcc -o $target $target.s $target.c
    	$target

        retval=$?
        
        if test $retval -eq 0
        then
            let "l = $(cat $target.s | wc -l) - 7"
            let "lines += l"
            printf "OK: %4d $target\n" $l
        else
            echo	"------------------";
            echo "FAILED: $target.s";
            echo "Expected Output: 0";
            echo "Current Output: $retval";
    	     echo	"------------------";
        fi
    else
    	 echo	"------------------";
	     echo "FAILED: $name";
    	 echo "Expected Output: ${filename:${#filename}-1}";
    	 echo "Current Output: $retval";
	     echo	"------------------";
    fi
done < $testFolder/a_testfile

printf "Sum: %3d\n" $lines

