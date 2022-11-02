#define ANKERL_NANOBENCH_IMPLEMENT

#include "nanobench.h"
#include <iostream>
#include <cstdint>

uint64_t sum_from_to(uint64_t i, uint64_t n){
    uint64_t result = 0;
    for(i;i<=n;i++){
        result+=i;
    }
    return result;
}


int main(){
    uint64_t result;
    ankerl::nanobench::Bench().run("some double ops", [&] {
        result = 0;
        for(uint64_t i=1;i<=100;i++){
            result += 2*i*sum_from_to(i+1,100);
        }
    });
    std::cout << "result : " << result << '\n';
}