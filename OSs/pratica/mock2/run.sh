#!/bin/bash
if [ $# -le 1 ]; then
	echo "Wrong number of paramethers"
	elif [[ $1 != "client" && $1 != "server" ]]; then
        echo "Wrong mode argument"
    else
	    make
	    ./app $1 $2
fi