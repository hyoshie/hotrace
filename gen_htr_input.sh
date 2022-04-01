#!/bin/bash

if [ $# -ne 1 ]; then
	echo "usage: ./gen_htr_input.sh [num of key value pair]"
	exit
fi

value=1

### make first block
### print_key_and_value <arg1>times
### key is random string with base64 character
### value is integer from 1 to ...
for loop in $(seq 1 $1)
do
	cat /dev/urandom | base64 | fold -w 10 | head -n 1 | tee -a stored_key
	echo $value
	value=$((value+1))
done

### print line break for separating two blocks
echo

### print key to search
cat stored_key | awk '(NR % 5 == 0){print}'

### remove tmpfile
rm stored_key
