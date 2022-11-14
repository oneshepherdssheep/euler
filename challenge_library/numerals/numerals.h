//
// Created by betzalel on 14/11/22.
//

#ifndef EULER_NUMERALS_H
#define EULER_NUMERALS_H

#include <cstdint>
#include <cmath>


namespace numerals {

    uint64_t SumFrom1ToN(uint64_t n)
    {
        return (n*(n+1))/2;
    }

    uint64_t GetNumberOfDivisor(uint64_t n)
    {
        uint64_t evenDivisorCount=0;
        // if n=a*b, either a or b is less than or equal to the square root of n
        uint64_t limit = sqrt(n);
        for(uint32_t index = 2; index <= limit;index++)
        {
            if(n%index==0)
            {
                evenDivisorCount+=2; // if one divides, the other too so 1+1
            }
        }
        return evenDivisorCount+2;
    }
};

#endif //EULER_NUMERALS_H
