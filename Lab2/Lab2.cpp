//variant 2

#include <iostream>

using namespace std;

int main()
{
    float edge1, edge2, edge3, side1, side2; // variables declaration; edge1, edge2, edge3 -- edges of the brick; side1, side2 -- sides of the hole

    cout << "Input first edge of the brick: "; cin >> edge1;  // variable input
    cout << "Input second edge of the brick: "; cin >> edge2; // variable input
    cout << "Input third edge of the brick: "; cin >> edge3;  // variable input
    cout << "Input first side of the hole: "; cin >> side1;   // variable input
    cout << "Input second side of the hole: "; cin >> side2;  // variable input

    bool data_are_correct; // declaration of boolean variable that describes the correctness of input data

    if ((edge1 <= 0) || (edge2 <= 0) || (edge3 <= 0) || (side1 <= 0) || (side2 <= 0)) // checking of input data
    {
        cout << "Error: input data aren't correct\n"; // error message output
        data_are_correct = false; // input data aren't correct
    }
    else
    {
        data_are_correct = true; // input data are correct
    }

    if (data_are_correct) // the main part of the program will be executed in case of successful input data verification 
    {
        if (((side1 >= edge1) && (side2 >= edge2)) || ((side1 >= edge2) && (side2 >= edge3)) // checking the possibility of pushing the brick through the hole
            || ((side1 >= edge1) && (side2 >= edge3)) || ((side1 >= edge2) && (side2 >= edge1)) 
            || ((side1 >= edge3) && (side2 >= edge2)) || ((side1 >= edge3) && (side2 >= edge1)))
        {
            cout << "The brick can be pushed through the hole\n"; // output result message
        }
        else
        {
            cout << "The brick can't be pushed through the hole\n"; // output result message
        }
    }

    system("pause");

    return 0;
}
