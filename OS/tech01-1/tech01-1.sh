csv=$(cat $1)
a=()
n=0
for w in $csv
{
    ((n++))
}

wi=0
for w in $csv
{
    ei=0
    IFS=','
    for e in $w
    {
        ((t=wi*(n+1)+ei))
        a[$t]=$e
        ((ei++))
    }
    ((wi++))
}


function _get(){
    ((t=$1*(n+1)+$2))
    echo ${a[$t]}
}
function _set(){
    ((t=$1*(n+1)+$2))
    a[$t]=$3
}

function _bool(){
    echo "
    t=$1
    if ((t!=0)){
        t=1
    }else{
        t=0
    }
    t
    "  | bc -l
}


function _math(){
    echo "
    q=$1
    w=$3
    q$2w
    "  | bc -l
}

for ((w=0;w<n;++w)){
    t=$(_get $w $w)
    y=$(_bool $t)
    if ((y==0)) ; then
        y=$(_math $w + 1)
        for ((e=y;e<n;++e)){
            t=$(_get $e $w)
            y=$(_bool $t)
            if ((y!=0)) ; then
                s=$w
                d=$e
                f=1
                y=$(_math $n + 1)
                for ((g=0;g<y;++g)){
                    t=$(_get $d $g)
                    t=$(_math $t \* $f)
                    _t=$(_get $w $w)
                    t=$(_math $t + $_t)
                    _set $s $g $t
                }
                break
            fi
        }
    fi
    t=$(_get $w $w)
    y=$(_bool $t)
    if ((y!=0)) ; then
        y=$(_math $w + 1)
        for ((e=y;e<n;++e)){
            s=$e
            d=$w
            f=$(_get $e $w)
            f=$(_math 0 - $f)
            _t=$(_get $w $w)
            f=$(_math $f / $_t)
            y=$(_math $n + 1)
            for ((g=0;g<y;++g)){
                t=$(_get $d $g)
                t=$(_math $t \* $f)
                _t=$(_get $s $g)
                t=$(_math $t + $_t)
                _set $s $g $t
            }
        }
    fi
}
for ((w=0;w<n;++w)){
    for ((e=0;e<w;++e)){
        s=$e
        d=$w
        f=$(_get $e $w)
        f=$(_math 0 - $f)
        _t=$(_get $w $w)
        f=$(_math $f / $_t)
        y=$(_math $n + 1)
        for ((g=0;g<y;++g)){
            t=$(_get $d $g)
            t=$(_math $t \* $f)
            _t=$(_get $s $g)
            t=$(_math $t + $_t)
            _set $s $g $t
        }
    }
}
for ((w=0;w<n;++w)){
    t=$(_get $w $n)
    f=$(_get $w $w)
    f=$(_math $t / $f)
    echo $f
}
