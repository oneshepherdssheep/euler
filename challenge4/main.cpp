#define ANKERL_NANOBENCH_IMPLEMENT

#include "nanobench.h"
#include <iostream>
#include <cstdint>
#include <string>

const bool IsNumberPalindrome(const uint64_t number){
    bool isPalindrome = true;
    std::string palindromeCandidate = std::to_string(number);
    for(uint16_t index = 0; index < palindromeCandidate.length()/2; index++){
        if(palindromeCandidate[index] != palindromeCandidate[palindromeCandidate.length()-index-1]){
            isPalindrome = false;
            break;
        }
    }
    return isPalindrome;
}

void SolveChallenge4(uint32_t &largestPalindrome ,uint32_t &largestPalindromeProductOne,uint32_t &largestPalindromeProductTwo){
    uint32_t palindromeCandidate=0;
    for(uint32_t numberOne = 999; numberOne > 99; numberOne--){ //for(uint32_t numberOne = 100; numberOne < 1000; numberOne++){ <-- slower
        for(uint32_t numberTwo = 999; numberTwo > 99; numberTwo--){ //for(uint32_t numberTwo = 100; numberTwo < 1000; numberTwo++){ <-- slower
            palindromeCandidate = numberOne*numberTwo;
            if( IsNumberPalindrome(palindromeCandidate)){
                //std::cout << palindromeCandidate <<  " ("<< numberOne<<" x "<<numberTwo <<") is Palindrome" << std::endl;
                if(palindromeCandidate>largestPalindrome){
                    largestPalindrome = palindromeCandidate;
                    largestPalindromeProductOne = numberOne;
                    largestPalindromeProductTwo = numberTwo;
                }
            }
        }
    }
}

int main(){
    uint32_t largestPalindrome = 0;
    uint32_t largestPalindromeProductOne;
    uint32_t largestPalindromeProductTwo;
    SolveChallenge4(largestPalindrome,largestPalindromeProductOne,largestPalindromeProductTwo);
    ankerl::nanobench::Bench().run("some double ops", [&] {
        SolveChallenge4(largestPalindrome,largestPalindromeProductOne,largestPalindromeProductTwo);
    });
    std::cout << largestPalindrome <<  " ("<< largestPalindromeProductOne<<" x "<<largestPalindromeProductTwo <<") "
                              "is the largest palindrome made from the product of two 3-digit numbers" << std::endl;
    return EXIT_SUCCESS;
}
