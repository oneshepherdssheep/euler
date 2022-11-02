<a id="top"></a>
# Sum square difference

## Description
The sum of the squares of the first ten natural numbers is,

$$ 1^2+2^2+...+10^2 = 385 $$

The square of the sum of the first ten natural numbers is,

$$ (1+2+...+10)^2 = 55^2 = 3025 $$

Hence, the difference between the sum of the squares of the first ten natural numbers and the square of the sum is

$$ 3025 - 385 = 2640 $$

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

## Understanding

### First step

Here the problem seems difficult, but we can decompose it to make simpler.
First let's take a look at the following polynomial expansion:

$$ (1+2+...+100)^2 = 1^2 + (2+...+100)^2 + 2(1)(2+...+100) $$
$$ (1+2+...+100)^2 = 1^2 + 2^2 + (2+...+100)^2 + (3+...+100)^2 + 2(1)(2+...+100) + 2(2)(3+...+100) $$

If we continue, we will see that the more we expand the sum of number squared, the more two elements come out:

- a squared element
- a product with the form :

$$ 2(i)(j+...+100) with j=i+1 and j not exceeding 100 $$

Even the last sum squared will be like:

$$ (99+100)^2 = 99^2+100^2+2(99)(100) $$

So it seems that the sum of numbers squared is equal to:

$$ 	(\sum_{i = 1}^{100} i)^2 = \sum_{i = 1}^{100} i^2 + 2*\sum_{i = 1}^{99} i\sum_{j = i+1}^{100} j $$

Its general form will be :

$$ 	(\sum_{i = 1}^{N} i)^2 = \sum_{i = 1}^{N} i^2 + 2*\sum_{i = 1}^{N-1} i\sum_{j = i+1}^{N} j $$

### Proof by induction

To prove what we conclude above, we will use the mathematical induction.
Again this is what we want to prove:

$$ 	(\sum_{i = 1}^{N} i)^2 = \sum_{i = 1}^{N} i^2 + 2*\sum_{i = 1}^{N-1} i\sum_{j = i+1}^{N} j $$

$$ N \ge 2 $$

#### Initialization step

Let's take N=2, we then have:

$$ (\sum_{i = 1}^{2} i)^2 = (1+2)^2 = 3^2 = 9 $$

$$ \sum_{i = 1}^{2} i^2 + 2*\sum_{i = 1}^{1} i\sum_{j = i+1}^{2} j = 1^2 + 2^2 + 2(1)(2) = 1 + 4 + 4 = 9 $$

So for N=2, we have :

$$ (\sum_{i = 1}^{2} i)^2 = \sum_{i = 1}^{2} i^2 + 2*\sum_{i = 1}^{1} i\sum_{j = i+1}^{2} j $$

#### Induction step

Let's call our property F(N).
Let's assume that for P integer greater than 1, F(P) is true; which means that:

$$ 	(\sum_{i = 1}^{P} i)^2 = \sum_{i = 1}^{P} i^2 + 2*\sum_{i = 1}^{P-1} i\sum_{j = i+1}^{P} j $$

Let's demonstrate that if F(P) is true, then F(P+1) is also true.

$$ (\sum_{i = 1}^{P+1} i)^2 = (\sum_{i = 1}^{P} i + (P+1))^2 $$

$$ (\sum_{i = 1}^{P+1} i)^2 = (\sum_{i = 1}^{P} i)^2 + 2(P+1)(\sum_{i = 1}^{P} i) + (P+1)^2 $$

But since F(P) is true, we can replace the term:

$$ (\sum_{i = 1}^{P} i)^2 $$

$$ by $$

$$ \sum_{i = 1}^{P} i^2 + 2*\sum_{i = 1}^{P-1} i\sum_{j = i+1}^{P} j $$

With the replacement we have :

$$ (\sum_{i = 1}^{P+1} i)^2 = \sum_{i = 1}^{P} i^2 + 2*\sum_{i = 1}^{P-1} i\sum_{j = i+1}^{P} j + 2(P+1)(\sum_{i = 1}^{P} i) + (P+1)^2 $$

$$ (\sum_{i = 1}^{P+1} i)^2 = \sum_{i = 1}^{P} i^2 + (P+1)^2 + 2*\sum_{i = 1}^{P-1} i\sum_{j = i+1}^{P} j + 2(P+1)(\sum_{i = 1}^{P} i) $$

$$ (\sum_{i = 1}^{P+1} i)^2 = \sum_{i = 1}^{P+1} i^2 + 2*\sum_{i = 1}^{P-1} i\sum_{j = i+1}^{P} j + 2(P+1)(\sum_{i = 1}^{P} i) $$

$$ (\sum_{i = 1}^{P+1} i)^2 = \sum_{i = 1}^{P+1} i^2 + 2* (\sum_{i = 1}^{P-1} i\sum_{j = i+1}^{P} j + (P+1)(\sum_{i = 1}^{P} i)) $$

Let's now call P2 the following expression :

$$ P2 = \sum_{i = 1}^{P-1} i\sum_{j = i+1}^{P} j + (P+1)(\sum_{i = 1}^{P} i) $$

We now have :

$$ (\sum_{i = 1}^{P+1} i)^2 = \sum_{i = 1}^{P+1} i^2 + 2*P2 $$

Now the focus is on P2.

$$ P2 = \sum_{i = 1}^{P-1} i\sum_{j = i+1}^{P} j + (P+1)(\sum_{i = 1}^{P} i) $$

$$ \sum_{i = 1}^{P-1} i\sum_{j = i+1}^{P} j = (1)(2+...+P)+(2)(3+...+P)+(3)(4+...+P)+...+(P-1)(P) $$

and

$$ (P+1)(\sum_{i = 1}^{P} i) = (P+1)(1+2+...+P) = (1)(P+1) + (2)(P+1) + (3)(P+1) + ... + P(P+1) $$

So now :

$$ P2 = \sum_{i = 1}^{P-1} i\sum_{j = i+1}^{P} j + (P+1)(\sum_{i = 1}^{P} i) $$

$$ P2 = (1)(2+...+P)+(2)(3+...+P)+(3)(4+...+P)+...+(P-1)(P) + (1)(P+1) + (2)(P+1) + (3)(P+1) + ... + P(P+1) $$

$$ P2 = (1)(2+...+P+(P+1)) + (2)(3+...+P+(P+1)) + (3)(4+...+P+(P+1)) + ... + (P-1)(P) + (P)(P+1) $$

which means that :

$$ P2 = \sum_{i = 1}^{P-1} i\sum_{j = i+1}^{P} j $$

Then :

$$ (\sum_{i = 1}^{P+1} i)^2 = \sum_{i = 1}^{P+1} i^2 + 2*P2 $$

$$ (\sum_{i = 1}^{P+1} i)^2 = \sum_{i = 1}^{P+1} i^2 + 2*\sum_{i = 1}^{P} i\sum_{j = i+1}^{P+1} j $$

So if F(P) is true, F(P+1) is also true!

### Conclusion

Thanks to the proof above, we can conclude that :

$$ (\sum_{i = 1}^{N} i)^2 = \sum_{i = 1}^{N} i^2 + 2*\sum_{i = 1}^{N-1} i\sum_{j = i+1}^{N} j $$

is true.

### Source code

Since this problem is not too difficult to solve, allow me to paste the code here
```c++
#include <iostream>
#include <cstdint>

constexpr uint64_t sum_from_to(uint64_t i, uint64_t n){
    uint64_t result = 0;
    for(i;i<=n;i++){
        result+=i;
    }
    return result;
}


int main(){
    uint64_t result = 0;
    for(uint64_t i=1;i<=100;i++){
        result += 2*i*sum_from_to(i+1,100);
    }
    std::cout << "result : " << result << '\n';
}

```

## Benchmarking

The benchmarked code using [nanobench](https://github.com/martinus/nanobench) takes 5,401.03 nanoseconds (~5.4 us) to run on my machine .


|               ns/op |                op/s |    err% |          ins/op |         bra/op |   miss% |     total | benchmark
|--------------------:|--------------------:|--------:|----------------:|---------------:|--------:|----------:|:----------
|            5,401.03 |          185,149.89 |    3.2% |       32,618.05 |       5,454.01 |    1.5% |      0.01 | `some double ops`

