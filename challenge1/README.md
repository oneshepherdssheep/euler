<a id="top"></a>
# Multiples of 3 or 5

## Description
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.<br>
The sum of these multiples is 23.<br>

Find the sum of all the multiples of 3 or 5 below 1000.

## Understanding 

The goal here is to compute the sum of all natural numbers below 1000 which are multiples of 3 or 5.
It is only mentionned 3 or 5 so it means that we should avoid numbers which are multiples of both like 15.

So if we compute the sum of numbers *only* multiple of 3 (S3), then those *only* multiple of 5(S5) and finally
the sum of numbers *only* multiple of 15 (S15) and then compute the *S = (S3+S5)-S15*, we should have the
expected value.

## Benchmarking

The benchmarked code using [nanobench](https://github.com/martinus/nanobench) takes 11,789.42 nanoseconds (~11.8 us) to run on my machine.

|               ns/op |                op/s |    err% |          ins/op |         bra/op |   miss% |     total | benchmark
|--------------------:|--------------------:|--------:|----------------:|---------------:|--------:|----------:|:----------
|           11,789.42 |           84,821.80 |    0.1% |       66,266.11 |      13,012.02 |    0.0% |      0.01 | `some double ops`
