#define ANKERL_NANOBENCH_IMPLEMENT

#include <iostream>
#include "eratosthene_sieve.h"
#include "nanobench.h"

int main(){
    EratosthenesSieve<uint64_t,105000> eratosthenesSieve;
    // the line below allowed us to adjust the size of the sieve
    // std::cout << "There is : " << eratosthenesSieve.GetPrimeCount() << " prime numbers.\n";

    uint64_t solution = 0;
    ankerl::nanobench::Bench().run("some double ops", [&] {
        // decrementing by 1 because we start the index at 0 in the library
        solution = eratosthenesSieve.GetPrimeNumber(10001-1);
    });
    std::cout << "The 10001st prime number is : " << solution << "\n";
	return EXIT_SUCCESS;
}
