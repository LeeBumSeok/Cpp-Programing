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
        int ab, ac, bc;
        int save;

        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

        ab = pow(b1 - a1, 2) + pow(b2 - a2, 2);
        ac = pow(c1 - a1, 2) + pow(c2 - a2, 2);
        bc = pow(c1 - b1, 2) + pow(c2 - b2, 2);

        if (ab > bc)
        {
            save = ab;
            ab = bc;
            bc = save;
        }
        if (bc > ac)
        {
            save = bc;
            bc = ac;
            ac = save;
        }

        if ((b1 - a1) * (c2 - b2) == (c1 - b1) * (b2 - a2))
            cout << 0;
        else if (ac - bc - ab == 0)
            cout << 1;
        else if (ac - bc - ab > 0)
            cout << 2;
        else
            cout << 3;

        cout << endl;
        i++;
    }
    return 0;
}