<a id="top"></a>
# Largest palindrome product

## Description

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.

## Understanding

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
