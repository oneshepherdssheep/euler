# Longest Collatz sequence

## Description

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

**NOTE**: Once the chain starts the terms are allowed to go above one million.


## Understanding

This problem has an interesting reward price...
Okay to solve this problem I first thought I could somehow have a way to store the size of each chain number when 
encountered. I do believe it is possible, but only in the limit of certain number because otherwise different storage 
means other than simple array to store them.

So I decided to have a simpler implementation.
First, we need to take into account that as soon as the computation of the collatz number reach 1 we have arrived.
So this is our limit.

Basically the algorithm will have to go throw all numbers from 1 to 1000000, compute the associated collatz 
sequence each time and increment the chain size until we finally reach 1.

After that we can compare this chain size with the maximum and if it is greater than the maximum, we can consider
that this number is the new maximum.

This is a pretty simple algorithm, but because I thought about storing the chain along the way it took some time
to solve it.

## Benchmarking