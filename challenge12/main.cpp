#include <iostream>
#include <cmath>
#include "numerals.h"

void challenge012()
{
    uint64_t number;
    uint64_t numberDivisorCount=0;
    uint64_t triangleNumber=0;
    uint64_t index = 1;
    do{
        uint64_t triangleN = numerals::SumFrom1ToN(index);
        uint64_t divisorCount = numerals::GetNumberOfDivisor(triangleN);
        if(divisorCount > numberDivisorCount)
        {
            number = index;
            numberDivisorCount = divisorCount;
            triangleNumber = triangleN;
        }
        index++;
    }while(numberDivisorCount < 500);

    std::cout << "triangle number : " << triangleNumber <<
              ", number : " << number <<
              ", divisors count : " << numberDivisorCount << '\n';

}

int main()
{
    challenge012();
}