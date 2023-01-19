#!/bin/bash
if [ $# -ne 1 ]; then
    echo "Wrong number of paramethers"
else
    if [ -f $1 ]; then
        for i in [ 1..4 ]; do
            echo "even line"
            echo & "odd line"
        done
    else
        echo "can't access the file"
    fi
fi
