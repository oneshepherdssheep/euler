#define ANKERL_NANOBENCH_IMPLEMENT

#include "nanobench.h"
#include <iostream>
#include <cstdint>
#include "eratosthene_table.h"

static constexpr uint64_t TargetNumber = 600851475143;
static constexpr uint16_t EratostheneTableLength = 10000;

uint64_t ComputeChallenge3()
{
    uint64_t result = 0;
    uint64_t indexPrime = 0;
    uint64_t computedNumber = TargetNumber;
    EratostheneTable<EratostheneTableLength> eratostheneTable;

    // Processing
    uint16_t prime = eratostheneTable.GetPrimeNumber(indexPrime);
    do{
        if(computedNumber%prime == 0){
            computedNumber/=prime;
        }
        else{
            indexPrime++;
            prime = eratostheneTable.GetPrimeNumber(indexPrime);
            if(prime==1) {
                break; // <-- range of prime may be limited (increase if it is the case)
            }
        }
    } while(computedNumber > 1);
    result = prime;

    return result;
}
int main(){
    uint64_t result;
    ankerl::nanobench::Bench().run("some double ops", [&] {
        result = ComputeChallenge3();
        ankerl::nanobench::doNotOptimizeAway(result);
    });
    if(result == 1){
        std::cout << "Issue found! The value of EratostheneTableLength(" << EratostheneTableLength
        <<") might be too low" << std::endl;
    }
    else{
        std::cout << "[Result] The largest Prime Factor of " << TargetNumber <<" is "<< result << std::endl;
    }
	return EXIT_SUCCESS;
}
