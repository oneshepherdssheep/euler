#include <iostream>
#include <cstdint>

static constexpr uint8_t FibonacciCacheLength = 100;
uint64_t fibonacciCacheTable[FibonacciCacheLength];

/**
 * @brief Initialize all field of the global variable fibonacciCacheTable to 0
 */
void InitFibonacciCacheTable()
{
    fibonacciCacheTable[0] = 1;
    fibonacciCacheTable[1] = 2;
    for(uint8_t i = 2; i < FibonacciCacheLength; i++)
    {
        fibonacciCacheTable[i] = 0;
    }
}

/**
 * @brief Check if the Fibonacci value at indexed position is cached
 * @param index : index of the Fibonacci value. E.g : 2 correspond to Fibonacci value 3
 * @return true if the value is cached, false otherwise
 */
bool IsFibonacciValueCached(const uint8_t index)
{
    if(index > FibonacciCacheLength) {
        return false;
    }
    else {
        return (fibonacciCacheTable[index]!=0);
    }
}

/**
 * @brief Put the Fibonacci value at the indicated index into the cache
 * @param index : index of the Fibonacci value. E.g : 2 correspond to Fibonacci value 3
 * @param value : computed Fibonacci value. E.g : 3 if index is 2
 * @return true if the operation is successful, false otherwise
 */
bool CacheFibonacciValue(const uint8_t index,const uint64_t value)
{
    if(index > FibonacciCacheLength) {
        return false;
    }
    else {
        std::cout << "Cached " << unsigned(value) << " at " << unsigned(index) << std::endl;
        fibonacciCacheTable[index] = value;
    }
    return true;
}

/**
 * @brief Compute the Fibonacci number for the index-th element.
 *        E.g : if index = 5, the computed value should be 13
 * @param index : index of the Fibonacci value. E.g : 2 correspond to Fibonacci value 3
 * @return the computed Fibonacci value
 */
uint64_t ComputeFibonacci(const uint64_t index)
{
    if(index == 0) {
        return 1;
    }
    else if(index == 1) {
        return 2;
    }
    else {
        uint64_t valueNminus1 = 0, valueNminus2 = 0;
        if(IsFibonacciValueCached(index-1)){
            valueNminus1 = fibonacciCacheTable[index-1];
        }
        else {
            valueNminus1 = ComputeFibonacci(index-1);
            CacheFibonacciValue(index-1,valueNminus1);
        }

        if(IsFibonacciValueCached(index-2)){
            valueNminus2 = fibonacciCacheTable[index-2];
        }
        else {
            valueNminus1 = ComputeFibonacci(index-2);
            CacheFibonacciValue(index-2,valueNminus2);
        }
        return valueNminus1 + valueNminus2;
    }
}

/**
 * @brief Compute the value expected for the challenge #2 of the Project Euler
 * @return the value expected by the challenge
 */
uint64_t ComputeChallenge2()
{
    uint64_t sum = 0;
    uint8_t index = 0;
    uint64_t value = 0;
    InitFibonacciCacheTable();

    do{
        if((value%2) == 0){
            sum += value;
        }
        value = ComputeFibonacci(index++);
    } while(value < 4000000);
    return sum;
}

int main()
{
    std::cout << "Challenge 2 answer = " << ComputeChallenge2() << std::endl;
    return EXIT_SUCCESS;
}

