<a id="top"></a>
# Smallest multiple

## Description

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?

## Understanding

This problem seems straightforward: go through all numbers and for each one of them check if it is divisible by 1 to 20.
As soon as one is found it is indeed the smallest positive number to do that, hence it is the solution.

However, if we think like that, we have a BIG issue : how far shall we go ? 10000 ? 5,000,000 ? We don't know at all.
So this first approach doesn't work. For me what worked was the analysis of the problem.

First of all this is the list of number our solution shall divide : 
1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10
11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20

By carefully analyzing those numbers we can notice that :
4 = 2 x 2
6 = 2 x 3
8 = 2 x 2 x 2
9 = 3 x 3
10 = 2 x 5
12 = 2 x 2 x 3
14 = 2 x 7
16 = 2 x 2 x 2 x 2
18 = 2 x 3 x 3
20 = 2 x 2 x 5

Basically all numbers are product of prime factors (we've seen those in challenge 3).
So it reminds us that our solution has also another property as seen in challenge 3.
Our solution shall be result of product of prime factors.

So if our solution is a product of prime factor and our solution divid all numbers from 1 to 20, then 
our solution shall be the product of all the greatest prime factors seen in our range of numbers.

Let's determine those : 
For 2 we have 2⁴
For 3 we have 3²
For 5 we have 5
For 7 we have 7
For 11 we have 11
For 13 we have 13
For 17 we have 17
For 19 we have 19

So our solution S, shall be S = 2⁴ x 3² x 5 x 7 x 11 x 13 x 17 x 19.

Well we have determined the solution theoritically, now the rest of the task is to implement our solution 
in our program.
To do that, we will reuse our EratosthenesTable class to get the prime numbers.
And for each prime numbers in the range [1 ; 20]; we have to check what is the greatest prime factor
existing in the range [1; 20]. Once we have done that for all prime numbers in [1; 20];
all we have to do is to multiply those numbers to get our solution.

### Benchmarking

The benchmarked code using [nanobench](https://github.com/martinus/nanobench) takes 790.16 nanoseconds to run on my machine .

|               ns/op |                op/s |    err% |          ins/op |         bra/op |   miss% |     total | benchmark
|--------------------:|--------------------:|--------:|----------------:|---------------:|--------:|----------:|:----------
|              790.16 |        1,265,561.71 |    0.4% |        5,908.01 |       1,091.00 |    0.0% |      0.01 | `some double ops`

