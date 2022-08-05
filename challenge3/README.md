<a id="top"></a>
# Largest prime factor

## Description

The prime factors of 13195 are 5, 7, 13 and 29.<br>
What is the largest prime factor of the number 600851475143 ?<br>

## Understanding

This problem was quite interesting. So here the goal was to find out the largest prime number
which divided 600851475143. The first step for me was to find a method to have prime numbers
at my disposal. For that I was reminded about the [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes).

To implement it I decided to use a template class because I was sure that I needed a large Array but how large was the question.
So for me having a configurable Sieve was key. The algorithm to implement it was not so difficult. But the big question
remained how to find out which was the largest prime factor.

I had to go back to the last schoolbook I have today, it was the one I used during my latest high school year.
In here, I was reminded about the prime factor decomposition also called [integer factorization](https://en.wikipedia.org/wiki/Integer_factorization).

This theory is that all natural numbers greater than 2 can be decomposed into product of prime factors.
An example is : 4872 = 2^3 x 3 x 7 x 29.

With this method in mind and my configurable Sieve of Eratosthenes, I had all the tools to implement the solution for the challenge 3.
Taking the number indicated and dividing it by all the prime factor in the order in which they are in the Eratosthenes table allowed
me to obtain the solution in a rather good amount of compilation and execution time.

### Benchmarking 

The benchmarked code using [nanobench](https://github.com/martinus/nanobench) takes 26,334,719.00 nanoseconds (~26.3 ms) to run on my machine .


|               ns/op |                op/s |    err% |          ins/op |         bra/op |   miss% |     total | benchmark
|--------------------:|--------------------:|--------:|----------------:|---------------:|--------:|----------:|:----------
|       26,334,719.00 |               37.97 |    0.1% |  201,156,401.00 |  29,186,404.00 |    0.3% |      0.29 | `some double ops`


