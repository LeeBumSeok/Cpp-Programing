#include <iostream>
using namespace std;

int main()
{
    int t;
    int i = 0;

    cin >> t;

    while (i < t)
    {
        int px1, px2, py1, py2, qx1, qx2, qy1, qy2;
        int temp;

        cin >> px1 >> py1 >> px2 >> py2 >> qx1 >> qy1 >> qx2 >> qy2;

        if (px1 > px2)
        {
            temp = px1;
            px1 = px2;
            px2 = temp;
        }
        if (py1 > py2)
        {
            temp = py1;
            py1 = py2;
            py2 = temp;
        }
        if (qx1 > qx2)
        {
            temp = qx1;
            qx1 = qx2;
            qx2 = temp;
        }
        if (qy1 > qy2)
        {
            temp = qy1;
            qy1 = qy2;
            qy2 = temp;
        }

        if (((qx1 < px1) && (px1 < qx2)) && ((py1 < qy1) && (qy1 < py2)) || ((px1 < qx1) && (qx1 < px2)) && ((qy1 < py1) && (py1 < qy2)))
            cout << 1;
        else if ((px1 == qx1) || (px2 == qx2))
        {
            if (((py1 <= qy1) && (qy1 <= py2)) || ((qy1 <= py1) && (py1 <= qy2)))
                cout << 2;
            else
                cout << 0;
        }
        else if ((py1 == qy1) || (py2 == qy2))
        {
            if (((px1 <= qx1) && (qx1 <= px2)) || ((qx1 <= px1) && (px1 <= qx2)))
                cout << 2;
            else
                cout << 0;
        }
        else
            cout << 0;
        cout << endl;
        i++;
    }
    return 0;
}