#!/bin/bash

if [ $# -ne 5 ]; then
    echo "Usage: $0 <from_size> <to_size> <step> <max_element_size> <output_dir>"
    exit 1
fi

from=$1
to=$2
step=$3
limit=$4
dir=$5

[ -d "$dir" ] || mkdir -p "$dir"

for ((size=from; size<=to; size+=step)); do
    for k in {1..5}; do 
        ./tests_generator $size $limit > "$dir/${size}_${k}.in"
        cat "$dir/${size}_${k}.in" | ./sorting $size > "$dir/${size}_${k}.out"
    done
done
