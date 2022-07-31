<a id="top"></a>
# Project Euler

My solutions to the euler project challenges (https://projecteuler.net) implemented in C++

### Table of Contents<br>
**[Challenge 1 : Multiples of 3 or 5](#multiples-of-3-or-5)**<br>
**[Challenge 2 : Even fibonacci numbers](#even-fibonacci-numbers)**<br>
**[Challenge 3 : Largest prime factor](#largest-prime-factor)**<br>
**[Challenge 4 : Largest palindrome product](#largest-palindrome-product)**<br>

## Multiples of 3 or 5

### Description
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.<br>
The sum of these multiples is 23.<br>

Find the sum of all the multiples of 3 or 5 below 1000.

### Understanding 

The goal here is to compute the sum of all natural numbers below 1000 which are multiples of 3 or 5.
It is only mentionned 3 or 5 so it means that we should avoid numbers which are multiples of both like 15.

So if we compute the sum of numbers *only* multiple of 3 (S3), then those *only* multiple of 5(S5) and finally
the sum of numbers *only* multiple of 15 (S15) and then compute the *S = (S3+S5)-S15*, we should have the
expected value.

### Benchmarking

The benchmarked code using [nanobench](https://github.com/martinus/nanobench) takes 11,789.42 nanoseconds (~11.8 us) to run on my machine.

|               ns/op |                op/s |    err% |          ins/op |         bra/op |   miss% |     total | benchmark
|--------------------:|--------------------:|--------:|----------------:|---------------:|--------:|----------:|:----------
|           11,789.42 |           84,821.80 |    0.1% |       66,266.11 |      13,012.02 |    0.0% |      0.01 | `some double ops`

## Even fibonacci numbers

### Description

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:<br>
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...<br>
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.<br>

### Understanding

For this one, we have to compute the Fibonacci numbers which are less than four million,<br>
for each one of them find out if they are even and if it is the case perform a summation.<br>

That's not so difficult, but the difficulty resides in the computation of Fibonacci numbers. <br>
Usually we use recursive function to do that. However, if we have to do that for all numbers, <br>
it will have a huge cost.

The first solution which came to my mind was to have a caching system so that as we are computing <br>
Fibonacci numbers, we may cache them along the way, so that the recursive function could use some <br>
cached values instead of always going to a recursive branch which may have been explored already <br>
for another computation. <br>

### Benchmarking

The benchmarked code using [nanobench](https://github.com/martinus/nanobench) takes 633.86 nanoseconds to run on my machine.

|               ns/op |                op/s |    err% |          ins/op |         bra/op |   miss% |     total | benchmark
|--------------------:|--------------------:|--------:|----------------:|---------------:|--------:|----------:|:----------
|              633.86 |        1,577,633.81 |    0.9% |        5,924.01 |       1,101.00 |    0.2% |      0.01 | `some double ops`

## Largest prime factor

### Description

The prime factors of 13195 are 5, 7, 13 and 29.<br>
What is the largest prime factor of the number 600851475143 ?<br>

### Understanding

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



## Largest palindrome product

### Description

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.

### Understanding

This problem is pretty straightforward:
- first, determine when a number is a palindrome
- second, use a double loop to loop through all numbers of 3 digits to perform all possible products
- third, while going through all the product, check the largest 

The first step is the most difficult because we have to find a mean to determine when a number is a palindrome.
I first try to use an homemade method using division and multiplication to take out the digit on left and right
but if this method worked for a lot of numbers, I encountered one issue regarding the number which contains 0
like 60606. 
Finally I simply used a method to convert the number into a string which helps to quickly check when a number is 
a palindrome.

There are probably rooms for improvement, but as it is it is good enough.

### Benchmarking 

The benchmarked code using [nanobench](https://github.com/martinus/nanobench) takes 31,671,128.00 nanoseconds (~31.7 ms) to run on my machine .

|               ns/op |                op/s |    err% |          ins/op |         bra/op |   miss% |     total | benchmark
|--------------------:|--------------------:|--------:|----------------:|---------------:|--------:|----------:|:----------
|       31,671,128.00 |               31.57 |    0.4% |  299,199,789.00 |  62,391,777.00 |    0.1% |      0.35 | `some double ops`

## <Problem Title>

### Description
<Insert Description Here>
### Understanding
<Insert Understanding Here>
