//
// Created by oneshepherdssheep on 28/07/2022.
//

#ifndef CHALLENGE3_ERATOSTHENE_TABLE_H
#define CHALLENGE3_ERATOSTHENE_TABLE_H

#include <cstdint>
#include <iostream>

struct EratostheneEntry {
    uint16_t number_m;
    bool isPrime_m;
};

template<uint16_t N>
class EratosthenesTable {
public:
    EratosthenesTable();
    void PrintEratostheneTable();
    uint16_t GetPrimeNumber(uint16_t primeIndex);
    uint16_t GetPrimeCount();
private:
    void FillEratostheneTable();
    void CrossTable();
    EratostheneEntry EratostheneEntries[N]{0,false};
    uint16_t primeCount_m{0};
};

template<uint16_t N>
EratosthenesTable<N>::EratosthenesTable() {
    FillEratostheneTable();
    CrossTable();
}

template<uint16_t N>
void EratosthenesTable<N>::PrintEratostheneTable() {
    for(uint16_t i = 0; i < N; i++){
        if(EratostheneEntries[i].isPrime_m){
            std::cout << unsigned(EratostheneEntries[i].number_m) << " is prime!" << std::endl;
        }
    }
}

template<uint16_t N>
void EratosthenesTable<N>::FillEratostheneTable() {
    for(uint16_t i = 0; i < N; i++){
        EratostheneEntries[i].isPrime_m = false;
        EratostheneEntries[i].number_m = i+1;
    }
}

template<uint16_t N>
void EratosthenesTable<N>::CrossTable() {
    for(uint16_t i = 0;i < N; i++){
        for(uint16_t j = 0; j <= i; j++){
            if(i == j){
                if(EratostheneEntries[i].number_m == 1){
                    EratostheneEntries[i].isPrime_m = false;
                }
                else{
                    EratostheneEntries[i].isPrime_m = true;
                    primeCount_m++;
                }
            }
            else{
                if((EratostheneEntries[j].number_m != 1) && (EratostheneEntries[i].number_m%EratostheneEntries[j].number_m == 0)){
                    break;
                }
            }
        }
    }
}

template<uint16_t N>
uint16_t EratosthenesTable<N>::GetPrimeNumber(uint16_t primeIndex) {
    uint16_t primeChecked = 0;
    uint16_t result = 1;    // <-- we shouldn't return 1
    if(primeIndex < primeCount_m){
        for(uint16_t i = 0; i < N; i++){
            if(EratostheneEntries[i].isPrime_m){
                if(primeIndex == primeChecked){
                    result = EratostheneEntries[i].number_m;
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

template<uint16_t N>
uint16_t EratosthenesTable<N>::GetPrimeCount() {
    return primeCount_m;
}


#endif //CHALLENGE3_ERATOSTHENE_TABLE_H
