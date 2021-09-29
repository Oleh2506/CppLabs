//variant 2

#include <iostream>

using namespace std;

int main()
{
    float edge1, edge2, edge3, side1, side2;

    cout << "The first edge of the brick: "; cin >> edge1;
    cout << "The second edge of the brick: "; cin >> edge2;
    cout << "The third edge of the brick: "; cin >> edge3;
    cout << "The first side of the hole: "; cin >> side1;
    cout << "The second side of the hole: "; cin >> side2;

    bool data_is_correct = true;

    if ((edge1 <= 0) || (edge2 <= 0) || (edge3 <= 0) || (side1 <= 0) || (side2 <= 0))
    {
        cout << "Error: inputted data aren't correct";
        data_is_correct = false;
    }

    if (data_is_correct)
    {
        if (((side1 >= edge1) && (side2 >= edge2)) || ((side1 >= edge2) && (side2 >= edge3)) \
            || ((side1 >= edge1) && (side2 >= edge3)) || ((side1 >= edge2) && (side2 >= edge1)) \
            || ((side1 >= edge3) && (side2 >= edge2)) || ((side1 >= edge3) && (side2 >= edge1)))
        {
            cout << "The brick can be pushed through the hole";
        }
        else
        {
            cout << "The brick can't be pushed through the hole";
        }
    }

    return 0;
}
