#include <mutex>
#include <thread>
#include <stack>
#include <memory>
#include <iostream>
#include <cstdint>
#include <map>

bool pass_test_1(uint64_t a, uint64_t b, uint64_t c){
    return ((a*a + b*b) == c*c);
}

bool pass_test_2(uint64_t a,uint64_t b,uint64_t c){
    return (a+b+c)==1000;
}

int main()
{
    bool found = false;
    uint16_t iterationCount=0;
    for(uint64_t i=2; i<1000/2 && !found;i++){
        if(1000%i==0)
        {
            uint64_t a = 1000/i;
            for(uint64_t b=a+1;b<500;b++){
                for(uint64_t c=b+1;c<500;c++){
                    iterationCount++;
                    if(pass_test_1(a,b,c) && pass_test_2(a,b,c)){
                        found = true;
                        std::cout << "abc = " << a*b*c << '\n';
                        std::cout << "a=" << a << '\n';
                        std::cout << "b=" << b << '\n';
                        std::cout << "c=" << c << '\n';
                        std::cout << "iteration count = " << iterationCount << '\n';
                    }
                }
            }
        }
        else{ /* Nothing to do */ }
    }
}