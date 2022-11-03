//
// Created by oneshepherdssheep on 28/07/2022.
//

#ifndef ERATOSTHENE_SIEVE_H
#define ERATOSTHENE_SIEVE_H

#include <cstdint>
#include <iostream>

template<typename T>
struct Entry {
    T number_m;
    bool isPrime_m;
};

template<typename T,T N>
class EratosthenesSieve {
public:
    EratosthenesSieve();
    void PrintEratostheneTable();
    T GetPrimeNumber(T primeIndex);
    T GetPrimeCount();
private:
    void FillEratostheneTable();
    void CrossTable();
    Entry<T> entries_m[N];
    T primeCount_m{0};
};

template<typename T,T N>
EratosthenesSieve<T,N>::EratosthenesSieve() {
    FillEratostheneTable();
    CrossTable();
}

template<typename T,T N>
void EratosthenesSieve<T,N>::PrintEratostheneTable() {
    for(T i = 0; i < primeCount_m; i++){
        std::cout << unsigned(GetPrimeNumber(i)) << " is prime!" << std::endl;
    }
}

template<typename T,T N>
void EratosthenesSieve<T,N>::FillEratostheneTable() {
    for(T i = 0; i < N; i++){
        entries_m[i].isPrime_m = false;
        entries_m[i].number_m = i + 1;
    }
}

template<typename T,T N>
void EratosthenesSieve<T,N>::CrossTable() {
    for(T i = 0;i < N; i++){
        for(T j = 0; j <= i; j++){
            if(i == j){
                if(entries_m[i].number_m == 1){
                    entries_m[i].isPrime_m = false;
                }
                else{
                    entries_m[i].isPrime_m = true;
                    primeCount_m++;
                    //std::cout << "entry : " << unsigned(entries_m[i].number_m)  << std::endl;
                }
            }
            else{
                if((entries_m[j].number_m != 1) && (entries_m[i].number_m % entries_m[j].number_m == 0)){
                    break;
                }
            }
        }
    }
}

template<typename T,T N>
T EratosthenesSieve<T,N>::GetPrimeNumber(T primeIndex) {
    T primeChecked = 0;
    T result = 1;    // <-- 1 is not prime so good candidate here
    if(primeIndex < primeCount_m){
        for(T i = 0; i < N; i++){
            if(entries_m[i].isPrime_m){
                if(primeIndex == primeChecked){
                    result = entries_m[i].number_m;
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

template<typename T,T N>
T EratosthenesSieve<T,N>::GetPrimeCount() {
    return primeCount_m;
}


#endif //ERATOSTHENE_SIEVE_H
