#define ANKERL_NANOBENCH_IMPLEMENT

#include "nanobench.h"
#include <iostream>
#include <cstdint>

bool IsNumberDivisibleBy(uint32_t number, uint32_t divisor) {
    if (divisor == 0) {
        return false;
    }
    else {
        return (number%divisor == 0);
    }
}

uint32_t ComputeChallenge1(){
    uint32_t sumDivisibleBy3 = 0,sumDivisibleBy5 = 0,sumDivisibleBy15 = 0;
    for( uint16_t i = 0; i < 1000; i++){
        if(IsNumberDivisibleBy(i,3)){
            sumDivisibleBy3 += i;
        }
        if(IsNumberDivisibleBy(i,5)){
            sumDivisibleBy5 += i;
        }
        if(IsNumberDivisibleBy(i,15)){
            sumDivisibleBy15 += i;
        }
    }
    return (sumDivisibleBy3+sumDivisibleBy5)-sumDivisibleBy15;
}

int main(){
    uint64_t result;
    ankerl::nanobench::Bench().run("some double ops", [&] {
        result = ComputeChallenge1();
        ankerl::nanobench::doNotOptimizeAway(result);
    });
    std::cout << "Challenge 1 answer = " << result << std::endl;
    return EXIT_SUCCESS;
}
