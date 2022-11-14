#define ANKERL_NANOBENCH_IMPLEMENT


#include <iostream>
#include <cstdint>
#include "nanobench.h"
#include "eratosthene_sieve.h"

static constexpr uint8_t MAX_DIVISOR = 20;
EratosthenesSieve<uint8_t,MAX_DIVISOR> eratosthenesTable;

uint64_t GetResultOfChallenge5(){
    uint64_t result = 1;
    for(uint8_t i = 0; i < eratosthenesTable.GetPrimeCount(); i++){
        //std::cout << "Prime " << eratosthenesTable.GetPrimeNumber(i) << std::endl;
        uint32_t primeMultiple = eratosthenesTable.GetPrimeNumber(i);
        for(uint8_t j = 2; j<= MAX_DIVISOR; j++){
            if(j%primeMultiple==0){
                //std::cout << "Result = " << primeMultiple << "x" << eratosthenesTable.GetPrimeNumber(i)  << " (j=" << unsigned(j) << ") "<< std::endl;
                primeMultiple *= eratosthenesTable.GetPrimeNumber(i);
            }
        }
        result*=(primeMultiple/eratosthenesTable.GetPrimeNumber(i));
    }
    return result;
}

int main(){
    uint64_t result = 0;
    //eratosthenesTable.PrintEratostheneTable();
    ankerl::nanobench::Bench().run("some double ops", [&] {
        result = GetResultOfChallenge5();
        ankerl::nanobench::doNotOptimizeAway(result);
    });
    std::cout << "Smallest positive number that is evenly divisible by all of the numbers from 1 to 20 : " << result << std::endl;
    return EXIT_SUCCESS;
}
