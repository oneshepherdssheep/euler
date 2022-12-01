#include <iostream>
#include <cstdint>
#include <cassert>
#include <iostream>
#include <cmath>
#include <atomic>

const uint64_t LIMIT_NUMBER = 1000000;

uint64_t collatz(uint64_t n)
{
    if(n%2==0)
    {
        return n/2;
    }
    else
    {
        return 3*n+1;
    }
}

void challenge_014()
{
    uint64_t maxChainSize=1;
    uint64_t maxChainNumber=0;
    for(uint64_t index = 1; index < LIMIT_NUMBER; index++)
    {
        uint64_t cz;cz = 0;
        uint64_t chainSize;chainSize = 1;
        uint64_t subIndex;subIndex = index;
        do {
            chainSize++;
            cz = collatz(subIndex);
            subIndex = cz;
        } while (cz!=1);

        if(chainSize > maxChainSize)
        {
            maxChainSize = chainSize;
            maxChainNumber = index;
        }
    }

    std::cout << maxChainNumber << " has the longest chain " << maxChainSize << '\n';
}

int main()
{
    // /!\ We need a new implementation with precalculated value to speed things up a little bit.
    // /!\ 1 is particular, be cautious about it.
    challenge_014(); // takes too much time.
}

