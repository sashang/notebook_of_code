/*
Largest prime factor
Problem 3

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <cstdint>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>

using namespace std;

//work out the largest prime factor of the given integer.
int main(int argc, char* argv[])
{
    unsigned long number;
    number = std::stoull(string(argv[1]));
    unsigned long square_root = sqrt(number);
    for (unsigned long i = 2; i <= square_root ; i++)
    {
        if (number % i == 0)
        {
            number = number / i;
            square_root = sqrt(number);
            i = 1;
            continue;
        }
    }
    cout << number << endl;
}   

