# 10001st prime

## Description

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?

## Understanding

Here the problem can remind us of the [challenge 3](../challenge3/README.md).
In this challenge we used the [Sieve of Eratosthene](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) 
as a method to determine prime numbers.

Since this method has already been implemented, I will reuse the same library developed for challenge 3 here.
The library we developed allowed us to have a full list of prime numbers but also to go through all of them and
fine the 1st, 2nd, 345th and also the 10001st prime numbers we are looking for.

The only "difficulty" is to find the size of the sieve since, the library we are using is pretty static.
This is where we will make some assumption (trial/error), but other than that, the solution is pretty straightforward
thanks to the work we did in challenge 3.

## Code

Since the implementation is pretty simple (thanks to the eratosthene_sieve library we developed which does all the heavy lifting),
we can show the source code of the solution right here:

```c++
#include <iostream>
#include "eratosthene_sieve.h"

int main(){
    EratosthenesSieve<uint64_t,105000> eratosthenesSieve;
    // the line below allowed us to adjust the size of the sieve
    // std::cout << "There is : " << eratosthenesSieve.GetPrimeCount() << " prime numbers.\n";    // our library gives the first prime at index 0, so we need to adjust a little by decrementing by 1
    std::cout << "The 10001st prime number is : " << eratosthenesSieve.GetPrimeNumber(10001-1) << "\n";
	return EXIT_SUCCESS;
}
```

## Benchmarking

The benchmarked code using [nanobench](https://github.com/martinus/nanobench) takes 166,000.00 nanoseconds (~166.0 us) 
to run on my machine.


|               ns/op |                op/s |    err% |          ins/op |         bra/op |   miss% |     total | benchmark
|--------------------:|--------------------:|--------:|----------------:|---------------:|--------:|----------:|:----------
|          166,000.00 |            6,024.10 |    0.3% |    1,192,218.57 |     219,494.33 |    5.0% |      0.01 | `some double ops`