## Largest product in a series



The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.

73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450

Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?


## Understanding

This problem is pretty straightforward. The goal is to go through this 1000-digit number and for each consecutive 13 digits,
make the computation of the product of those digits and each time update the maximum of this computation.

To solve this, I proposed to use a string to store this 1000-digit number.
Once stored, I can use the string API to create an appropriate 13-digit substring.
As soon as we have the 13-digit substring, we can at this moment compute the product of the digits.

Since in ```C++``` we can convert a character to an integer by doing :
```c++
uint64_t integer = '4'-'0';
```

I can use this mechanism in a loop which goes through all the digits of the 13-digit substring.
And do the same operation over and over again, until the end.

And because we can compare the result of the product each time, we can each time update who is the 
maximum.

## Benchmarking

The benchmarked code using [nanobench](https://github.com/martinus/nanobench) takes 130,995.12 nanoseconds (~131.0 us)
to run on my machine.

|               ns/op |                op/s |    err% |          ins/op |         bra/op |   miss% |     total | benchmark
|--------------------:|--------------------:|--------:|----------------:|---------------:|--------:|----------:|:----------
|          130,995.12 |            7,633.87 |    1.1% |    1,218,273.25 |     221,435.25 |    0.5% |      0.01 | `some double ops`