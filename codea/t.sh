#!/bin/bash


function generateASM {

OUT=""
OUT="$OUT\n#define RET exit"
OUT="$OUT\nint main(){\n"
OUT="$OUT\n${1}\n"
OUT="$OUT\n}\n"


echo -e "###############################\n"
echo -e $OUT #> test_code.c
echo -e "###############################\n"
}

#make clean
#make

mkdir log_codea 2> /dev/null

POS=0
NEG=0
for filename in ./test_codea/*.0
do

    ./codea < $filename > asm.S

    FILE="./test_codea/$( basename $filename)"

    NAME="${FILE%?}call"

    generateASM "$(echo -e $(cat $NAME))"

    gcc asm.S test_code.c -o testme

    ./testme


    #"./log_codea/$( basename $filename).log" 2>/dev/null


    #retval=$?


    #if test $retval -eq ${filename:${#filename}-1}
    #then
    #	 echo "OK: $filename";
    #     ((POS++))
    #else
    #	 echo	"------------------";
    #	 echo "FAILED: $filename";
    #	 echo "Expected Output: ${filename:${#filename}-1}";
    #	 echo "Current Output: $retval";
    #	 echo	"------------------";
    #    ((NEG++))
    #fi
done

echo -e "positive: $POS\nnegative: $NEG"
