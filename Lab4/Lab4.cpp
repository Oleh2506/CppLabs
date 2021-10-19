#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cout << "Input n: ";
    cin >> n;

    float seriesSum = 0, currentElem;
    for (int i = 1; i <= n; i++)
    {
        currentElem = 1.0 / (i * pow(2 * i + 1, 2));
        seriesSum += currentElem;
    }

    cout << "Sum of the elements: " << seriesSum << "\n";
    system("pause");
    return 0;
}
