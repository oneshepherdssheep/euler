#include <iostream>
#include "eratosthene_sieve.h"

int main(){
    EratosthenesSieve<uint64_t,105000> eratosthenesSieve;
    std::cout << "There is : " << eratosthenesSieve.GetPrimeCount() << " prime numbers.\n"; // check to adjust the number of primes expected
    // our library gives the first prime at index 0, so we need to adjust a little by decrementing by 1
    std::cout << "The 10001st prime number is : " << eratosthenesSieve.GetPrimeNumber(10001-1) << "\n";
	return EXIT_SUCCESS;
}
