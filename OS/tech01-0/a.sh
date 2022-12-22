#!/bin/bash
IFS=:
#MANPATH=/usr/share/man
while read -r func
do
    for mpath in $MANPATH
    do
        fpath=$(find $mpath/man3 -name "$func.3*" | head -n 1)
        if [ -n "$fpath" ]
        then
            break
        fi
    done

    if [ -n "$fpath" ]
    then
        if [ $(echo $fpath | tail -c 3) = ".3" ]
        then
            include_string=$(cat $fpath | grep '\#include' | head -n 1)
        else
            include_string=$(gunzip -c $fpath | grep '\#include' | head -n 1)
        fi

        include_file=$(echo $include_string | sed -r 's/.*include <(.*)>.*/\1/g')
        echo $include_file
    else
        echo "---"
    fi
done