#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    int i = 0;
    cin >> t;

    while (i < t)
    {
        int a1, a2, b1, b2, c1, c2;
        int temp;
        int signedArea;

        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
        signedArea = ((b1 - a1) * (c2 - a2) - (c1 - a1) * (b2 - a2));

        if ((b1 - a1) * (c2 - b2) == (c1 - b1) * (b2 - a2))
            temp = 0;
        else if (signedArea > 0)
            temp = 1;
        else if (signedArea < 0)
            temp = -1;

        cout << abs(signedArea) << ' ' << temp << endl;
        i++;
    }
    return 0;
}