#!/bin/bash
if [ $# -ne 2 ];  then
    echo "Wrong number of paramethers"
    else 
    if [ -f $1 ]; then
        rm $1
    fi
    make
    ./program $1 $2
    cat $1
fi