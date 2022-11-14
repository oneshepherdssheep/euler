#include <iostream>
#include <cstdint>
#include "eratosthene_sieve.h"

constexpr uint64_t SIZE = 2000000;
EratosthenesSieve<uint64_t,SIZE> eratosthenesSieve;

int main(){
    // the line below allowed us to adjust the size of the sieve
    std::cout << "There is : " << eratosthenesSieve.GetPrimeCount() << " prime numbers.\n";

    uint64_t lastPrime = eratosthenesSieve.GetLastPrime();
    uint64_t sumOfPrimes = eratosthenesSieve.GetSumOfPrimesBelow(2000000);
    std::cout << "The last prime number is : " << lastPrime << '\n';
    std::cout << "The sum of prime below " << 2000000 << " is " << sumOfPrimes << '\n';
    return EXIT_SUCCESS;
}