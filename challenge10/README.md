# Summation of primes
## Description

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.

## Understanding

This problem is pretty straightforward. We need to find all primes below 2 000 000 and 
compute the summation of them all.

Even though it seems simple, this problem challenged me to refactor the Ératosthène library
I have developed so far for the challenge.

There was two important factor for improvement:
- speed
- size

So rather than explaining you how I solved the challenge, because it is obvious as soon as you have
the proper library or function to compute prime numbers, I would rather explain to you how I improved
my **erathosthene_sieve** library.

### Size

For the first aspect of the improvement, I did it thanks to a solution of the challenge I had done
2 years ago. 

In this solution, I implemented the size not using a very complex type such as
```c++
template<typename T>
struct Entry {
    T number_m;
    bool isPrime_m;
};
.
.
.
Etrny<T> entries_m[N]; // Entry is used here 
```

to describe each entry, but simply using and array of boolean.

Why ? Because the index of the element in the array, can be used as the number.

So :
```c++
entry_m[index] = true; // this means that number 'index' is prime
```

This way we save a lot of space, which is always welcomed.

At the same time, we needed to change a little the other algorithms, but this change was not
so difficult to implement.

### Speed

For this aspect, I also benefited from my past implementation but this time took time to 
document my understanding, so here it is.

If you have any integer (natural) number **n**, if this number is divisible, it can then be written
on the form of the product of two integers such as : 

$$ n = a*b $$

We would have either a or b equal to the square root of n.

So by checking only if n is divisible by all numbers less or equal to its square root, we can save
a lot of time and thus gain a lot in computation time.

This is the last change in the library and thanks to those changes, the computation of the solution
for this problem didn't take a lot of time (it was quite fast).

So I can thank the inspiration I had 2 years ago.

## Benchmarking
