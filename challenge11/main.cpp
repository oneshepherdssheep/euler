#include <iostream>
#include <cstdint>

constexpr std::size_t GRID_COLUMN_LENGTH = 20;
constexpr std::size_t GRID_COLUMN_HEIGHT = 20;
const uint8_t GRID[GRID_COLUMN_LENGTH][GRID_COLUMN_HEIGHT] =
{
{8,2,22,97,38,15,0,40,00,75,04,05,07,78,52,12,50,77,91,8},
{49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00},
{81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65},
{52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91},
{22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
{24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50},
{32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
{67,26,20,68,02,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21},
{24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
{21,36,23,9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95},
{78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14,9,53,56,92},
{16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57},
{86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58},
{19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40},
{04,52,8,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66},
{88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69},
{04,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36},
{20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,04,36,16},
{20,73,35,29,78,31,90,01,74,31,49,71,48,86,81,16,23,57,05,54},
{01,70,54,71,83,51,54,69,16,92,33,48,61,43,52,01,89,19,67,48}
};


static const int NUMBER_TO_COUNT = 4;

uint32_t computeProductDOWN(const uint8_t lineIndex, const uint8_t columnIndex)
{
    uint32_t product = 0;
    if ((lineIndex + NUMBER_TO_COUNT) < GRID_COLUMN_LENGTH)
    {
        product = 1;
        for (uint8_t index = 0; index < NUMBER_TO_COUNT; index++)
        {
            product *= GRID[lineIndex + index][columnIndex];
        }
    }
    return product;
}

uint32_t computeProductRIGHT(const uint8_t lineIndex, const uint8_t columnIndex)
{
    uint32_t product = 0;
    if ((columnIndex + NUMBER_TO_COUNT) < GRID_COLUMN_HEIGHT)
    {
        product = 1;
        for (uint8_t index = 0; index < NUMBER_TO_COUNT; index++)
        {
            product *= GRID[lineIndex][columnIndex + index];
        }
    }
    return product;
}

uint32_t computeProductLEFT(const uint8_t lineIndex, const uint8_t columnIndex)
{
    uint32_t product = 0;
    if (((columnIndex - NUMBER_TO_COUNT) + 1) >= 0)
    {
        product = 1;
        for (uint8_t index = 0; index < NUMBER_TO_COUNT; index++)
        {
            product *= GRID[lineIndex][columnIndex - index];
        }
    }
    return product;
}

uint32_t computeProductDIAGONAL(const uint8_t lineIndex, const uint8_t columnIndex)
{
    uint32_t product = 0;
    if ((((columnIndex + NUMBER_TO_COUNT) < GRID_COLUMN_HEIGHT)) && (((lineIndex + NUMBER_TO_COUNT) < GRID_COLUMN_LENGTH)))
    {
        product = 1;
        for (uint8_t index = 0; index < NUMBER_TO_COUNT; index++)
        {
            product *= GRID[lineIndex + index][columnIndex + index];
        }
    }
    return product;
}

uint32_t computeProductREVERSEDIAGONAL(const uint8_t lineIndex, const uint8_t columnIndex)
{
    uint32_t product = 0;
    if (((((columnIndex - NUMBER_TO_COUNT) + 1) >= 0)) && (((lineIndex + NUMBER_TO_COUNT) < GRID_COLUMN_LENGTH)))
    {
        product = 1;
        for (uint8_t index = 0; index < NUMBER_TO_COUNT; index++)
        {
            product *= GRID[lineIndex + index][columnIndex - index];
        }
    }
    return product;
}

int challenge011()
{
    static const int NB_FUNCTION = 5;
    uint32_t maxProduct = 0;
    uint32_t currentProduct = 0;

    // collection of functions to call
    uint32_t (*ProductComputationFunctions[NB_FUNCTION])(const uint8_t, const uint8_t);
    //ProductComputationFunctions[0] = computeProductUP;
    ProductComputationFunctions[0] = computeProductDOWN;
    ProductComputationFunctions[1] = computeProductRIGHT;
    ProductComputationFunctions[2] = computeProductLEFT;
    ProductComputationFunctions[3] = computeProductDIAGONAL;
    ProductComputationFunctions[4] = computeProductREVERSEDIAGONAL;
    // for each line, while there is at least four line below to perform the computation
    for (int k = 0; k < GRID_COLUMN_LENGTH; k++)
    {
        // for each element of the line, while there is at least four element to perform computation
        for (int i = 0; i < GRID_COLUMN_HEIGHT; i++)
        {
            // compute the product
            for (int j = 0; j < NB_FUNCTION; j++)
            {
                currentProduct = ProductComputationFunctions[j](k,i);
                if (currentProduct > maxProduct)
                    maxProduct = currentProduct;
            }
        }
    }
    return maxProduct;
}

int main()
{
    std::cout << "Challenge 011 : " << challenge011() << std::endl;
}