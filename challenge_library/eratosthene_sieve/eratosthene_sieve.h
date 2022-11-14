//
// Created by oneshepherdssheep on 28/07/2022.
//

#ifndef ERATOSTHENE_SIEVE_H
#define ERATOSTHENE_SIEVE_H

#include <cstdint>
#include <iostream>
#include <cmath>

template<typename T>
struct Entry {
    T number_m;
    bool isPrime_m;
};

template<typename T,std::size_t N>
class EratosthenesSieve {
public:
    EratosthenesSieve();
    void PrintEratostheneTable();
    T GetPrimeNumber(T primeIndex);
    T GetPrimeCount();
    T GetLastPrime();
    T GetSumOfPrimesBelow(T limit) const;
private:
    void FillEratostheneTable();
    void CrossTable();
    bool entries_m[N];
    T primeCount_m;
};

template<typename T,std::size_t N>
EratosthenesSieve<T,N>::EratosthenesSieve() :
    entries_m{false},
    primeCount_m{0}
{
    FillEratostheneTable();
    CrossTable();
}

template<typename T,std::size_t N>
void EratosthenesSieve<T,N>::PrintEratostheneTable() {
    for(T i = 0; i < primeCount_m; i++){
        std::cout << unsigned(GetPrimeNumber(i)) << " is prime!" << std::endl;
    }
}

template<typename T,std::size_t N>
void EratosthenesSieve<T,N>::FillEratostheneTable() {
    for(T i = 0; i < N; i++){
        entries_m[i] = false;
    }
}

template<typename T,std::size_t N>
void EratosthenesSieve<T,N>::CrossTable() {
    for(T i = 2;i < N; i++){
        T sqrtI = sqrt(i);
        bool isPrime = true;
        for(T j = 2; j <= sqrtI; j++){
            if((i % j) == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            entries_m[i] = true;
            primeCount_m++;
        }
    }
}

template<typename T,std::size_t N>
T EratosthenesSieve<T,N>::GetPrimeNumber(T primeIndex) {
    T primeChecked = 0;
    T result = 1;    // <-- 1 is not prime so good candidate here
    if(primeIndex < primeCount_m){
        for(T i = 0; i < N; i++){
            if(entries_m[i]){
                if(primeIndex == primeChecked){
                    result = i;
                    break;
                }
                else {
                    primeChecked++;
                }
            }
        }
    }
    else{
        // Nothing to do
    }
    return result;
}

template<typename T,std::size_t N>
T EratosthenesSieve<T,N>::GetPrimeCount() {
    return primeCount_m;
}

template<typename T,std::size_t N>
T EratosthenesSieve<T,N>::GetLastPrime() {
    T lastPrime = 1; // <-- 1 is not prime so good candidate here
    for(T i = N-1; i >= 2;i--){
        if(entries_m[i]){
            lastPrime = i;
            break;
        }
    }
    return lastPrime;
}

template<typename T, std::size_t N>
T EratosthenesSieve<T,N>::GetSumOfPrimesBelow(T limit) const {
    T result = 0;
    for(std::size_t index = 0; index < N && index <= limit; index++){
        if(entries_m[index]){
            result+=index;
        }
    }
    return result;
}


#endif //ERATOSTHENE_SIEVE_H
