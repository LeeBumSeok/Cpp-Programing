#include <iostream>
using namespace std;

int main()
{
    int t;
    int i = 0;

    cin >> t;

    while (i < t)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a + b > c)
        {
            if (a == b && b == c)
                cout << 1;
            else if ((a * a) + (b * b) == (c * c))
                cout << 2;
            else if (a == b || a == c || b == c)
                cout << 3;
            else
                cout << 4;
        }
        else
            cout << 0;
        cout << endl;
        i++;
    }
    return 0;
}