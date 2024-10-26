#!/bin/bash

# Shell script to automate testing for proc_creation program

echo "Testing multiple children mode with 2, 4, and 8 children"
for num in 2 4 8; do
    echo "Running with $num children"
    ./proc_creation 1 $num > output_multiple_$num.txt
done

echo "Testing process chain mode with 2, 4, and 8 children"
for num in 2 4 8; do
    echo "Running with a chain of $num processes"
    ./proc_creation 2 $num > output_chain_$num.txt
done

echo "Testing complete. Check output files for results."
