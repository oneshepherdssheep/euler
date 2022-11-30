//
// Created by betzalel on 14/11/22.
//

#ifndef EULER_NUMERALS_H
#define EULER_NUMERALS_H

#include <cstdint>
#include <cmath>
#include <cassert>


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


namespace numerals
{
    template<std::size_t N>
    class VeryLargeInteger
    {
    public:

        VeryLargeInteger() :
                largeInteger{0}
        {
            for(std::size_t index = 0; index < N; index++)
            {
                largeInteger[index] = '0';
            }
        }

        void addDigit(const char digit)
        {
            addDigit(0,digit);
        }

        void addNumber(const std::string number){
            for(int index = number.length()-1; index >= 0;index--)
            {
                addDigit((number.length()-1)-index,number[index]);
            }
        }

        void print()
        {
            for(int index = N-1; index >= 0; index--)
            {
                if(index==0)
                    std::cout << largeInteger[index] << std::endl;
                else
                    std::cout << largeInteger[index];
            }
        }

    private:

        void addDigit(std::size_t index,const char digit)
        {
            assert(index < N); // make sure we don't go too far
            int temp = (largeInteger[index]-'0') + (digit - '0');
            if(temp > 9)
            {
                largeInteger[index] = '0'+(temp - ((temp/10)*10));
                addDigit(index+1,'0'+(temp/10));
            }
            else
            {
                largeInteger[index] = '0'+temp;
            }
        }

        char largeInteger[N];
    };
}

#endif //EULER_NUMERALS_H
