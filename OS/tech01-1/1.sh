#!/bin/bash

inm=$(cat $1)
otv=()
array=()
x=()
n=0
for i in $inm
do
    ((n++))
done

for ((i=0;i<n+1;i++))
{
    ((otv[$i]=$i))
}

i=0
for row in $inm
do
    j=0
    IFS=,
    for val in $row
    do
        ((x=i*(n+1)+j))
        array[$x]=$val
        ((j++))
    done
    ((i++))
done

function _abs()
{
    if (( $(echo "$1<0" | bc) == 1 )); then
        echo "-1*$1" | bc
    else
        echo "1*$1" | bc
    fi
}

function _get()
{
    ((x=$1*(n+1)+$2))
    echo ${array[$x]}
}

function _math()
{
    echo "
    a=$1
    b=$3
    a$2b
    "  | bc -l
}

function _gelem() #1=k;2=n;
{
    i_max=$1
    j_max=$1
    for ((i=$1;i<$2;i++))
    {
        for ((j=$1;j<$2;j++))
        {
            a=$(_abs ${array[$i_max*(n+1)+$j_max]})
            b=$(_abs ${array[$i*(n+1)+$j]})
            if (( $(echo "$a < $b" | bc) == 1 )) ; then
                i_max=$i
                j_max=$j
            fi
        }
    }

    for ((j=$1;j<$2+1;j++))
    {
        t=${array[$1*(n+1)+$j]}
        array[$1*(n+1)+$j]=${array[$i_max*(n+1)+$j]}
        array[$i_max*(n+1)+$j]=$t
    }

    for ((i=0;i<$2;i++))
    {
        t=${array[$i*(n+1)+$1]}
        array[$i*(n+1)+$1]=${array[$i*(n+1)+$j_max]}
        array[$i*(n+1)+$j_max]=$t
    }

    i=${otv[$1]}
    otv[$1]=${otv[$j_max]}
    otv[$j_max]=$i
}

for ((k=0;k<n;k++))
{
    _gelem $k $n
    for ((j=n;j>=k;j--))
    {
        array[$k*(n+1)+$j]=$(echo "${array[$k*(n+1)+$j]}/${array[$k*(n+1)+$k]}" | bc -l)
    }
    for ((i=$k+1;i<n;++i))
    {
        for ((j=$n;j>=k;j--))
        {
            c=$(echo "${array[$k*(n+1)+$j]}*${array[$i*(n+1)+$k]}" | bc -l)
            array[$i*(n+1)+$j]=$(echo "${array[$i*(n+1)+$j]} - $c" | bc -l)
        }
    }
}

for ((i=0;i<n;i++))
{
    x[$i]=${array[$i*(n+1)+$n]}
}
for ((i=n-2;i>=0;i--))
{
    for ((j=i+1;j<n;j++))
    {
        c=$(echo "${x[$j]}*${array[$i*(n+1)+$j]}" | bc -l)
        x[$i]=$(echo "${x[$i]} - $c" | bc -l)
    }
}

for ((i=0;i<n;++i))
{
    for ((j=0;j<n;++j))
    {
        if (($i==${otv[$j]})); then
            echo "${x[$j]}"
            break
        fi
    }
}