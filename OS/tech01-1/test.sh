a=-0.666
b=0.0001

function _math()
{
    echo "
    a=$1
    b=$3
    a$2b
    "  | bc -l
}

function _abs()
{
    if (( $(echo "$1<0" | bc) == 1 )); then
        echo "-1*$1" | bc
    else
        echo "1*$1" | bc
    fi
}

a=$(_abs $a)
b=$(_abs $b)
if (( $(echo "$a>$b" | bc -l) == 1 )) ; then
    i_max=101
    j_max=102
fi

t=$(_abs $a)
k=$(_abs $b)

echo "a=$i_max b=$j_max"