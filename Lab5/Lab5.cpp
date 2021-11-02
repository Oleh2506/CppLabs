/*
* Variant 2. Program to complement the given number with two digits.
* The required number has to be divisible by another specified number.
*/

#include <iostream>
#include <cmath>

int main()
{
    const int INITIAL_NUM = 22200, DIVISOR = 15, FIRST_DIGIT_POS = 1, SECOND_DIGIT_POS = 0;
    // code to find and output numbers satisfying given condition
   
    for (int i = 0; i <= 9; ++i)     // loop to find first undefined digit of the given number
    {
        for (int j = 0; j <= 9; ++j) // loop to find second undefined digit of the given number
        {
            int currentNum;
            currentNum = INITIAL_NUM + i * pow(10, FIRST_DIGIT_POS) + j * pow(10, SECOND_DIGIT_POS);

            if (currentNum % DIVISOR == 0)
            {
                std::cout << currentNum << " mod " << DIVISOR << " == 0\n";
            }
        }
    }
    return 0;
}
