//variant 2

#include <iostream>

using namespace std;

int main()
{
    double S1, S2; //declaration of variables; S1 -- area of the circumscribed square, S2 -- area of the inscribed square
    cout << "S1 = "; cin >> S1; //input of variable
    S2 = S1 / 2; //calculation of S2
    printf("S2 = %f\n", S2); //output of the result
    cout << "S2 / S1 = 2"; //output of the result
}
