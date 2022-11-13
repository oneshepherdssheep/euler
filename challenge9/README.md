# Special Pythagorean triplet
## Description

A Pythagorean triplet is a set of three natural numbers,

$$ a < b < c $$

for which,

$$ a^2 + b^2 = c^2 $$

For example, 

$$ 3^2 + 4^2 = 9 + 16 = 25 = 5^2 $$

There exists exactly one Pythagorean triplet for which 

$$ a + b + c = 1000 $$

Find the product abc.

## Understanding

This is an interesting problem because, as I saw it first, it will be tempting to go for a 
brute force method.

But, as for all problem, brute force is not the ideal.

So let's resume the situation we are asked to find the product :

$$ abc $$

for which :

$$ (1) a < b < c $$

$$ (2) a^2 + b^2 = c^2 $$

$$ (3) a + b + c = 1000 $$

So if we take the point (2) we have :

$$ a^2 + b^2 = c^2 $$

$$ a^2 = c^2 - b^2 $$

$$ a^2 = (c - b)*(c + b) $$

however we know that :

$$ (3) a + b + c = 1000 $$

then :

$$ a^2 = (c - b)*(1000 - a) $$

$$ a = (c - b)*(1000 - a)/a $$

so it means that either : 

$$ (A) c - b = k*a$$ 

or

$$ (B) 1000 - a = k*a$$

Let's assume that (A) is true then :

$$ (c-b)^2 = k^2*a^2 $$

$$ c^2 - 2bc + b^2 = k^2*a^2 $$

but we know that :

$$ c^2 = a^2 + b^2 $$

then:

$$ a^2 + b^2 - 2bc - b^2 = k^2*a^2 $$

$$ a^2 + 2b^2 - 2bc = k^2*a^2 $$

$$ 2b^2 - 2bc = k^2*a^2 - a^2 $$

$$ 2b*(b-c) = (k^2-1)*a^2 $$

however 

$$ b < c $$

, then  

$$ b - c < 0 $$ 

which means 

$$ 2b*(b-c) < 0 $$

so it would mean that 

$$ (k^2-1)*a^2 < 0 $$

then either 

$$ a^2 < 0 $$

which is impossible!

or 

$$ (k^2 - 1) < 0 $$

which is also impossible, because:

$$ k >= 1 $$

so (A) is impossible!

Which means only (B) is possible.

$$ (B) 1000 - a = k*a $$

$$ 1000 = a*(k+1) $$

$$ k+1 = 1000 / a $$

which means , 1000 is divisible by a.

This last sentence is key for the algorithm because we will take all the 'a' such as :

a <= 500

a divides 1000

It will help us have a number of iterations in our algorithm reduced to the minimum.

## Code snippet

Because this problem is not too long, I can post the code below :

```c++
#include <mutex>
#include <thread>
#include <stack>
#include <memory>
#include <iostream>
#include <cstdint>
#include <map>

bool pass_test_1(uint64_t a, uint64_t b, uint64_t c){
    return ((a*a + b*b) == c*c);
}

bool pass_test_2(uint64_t a,uint64_t b,uint64_t c){
    return (a+b+c)==1000;
}

int main()
{
    bool found = false;
    uint16_t iterationCount=0;
    for(uint64_t i=2; i<1000/2 && !found;i++){
        if(1000%i==0)
        {
            uint64_t a = 1000/i;
            for(uint64_t b=a+1;b<500;b++){
                for(uint64_t c=b+1;c<500;c++){
                    iterationCount++;
                    if(pass_test_1(a,b,c) && pass_test_2(a,b,c)){
                        found = true;
                        std::cout << "abc = " << a*b*c << '\n';
                        std::cout << "a=" << a << '\n';
                        std::cout << "b=" << b << '\n';
                        std::cout << "c=" << c << '\n';
                        std::cout << "iteration count = " << iterationCount << '\n';
                    }
                }
            }
        }
        else{ /* Nothing to do */ }
    }
}
```

## Benchmarking

