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
        int x1, x2, y1, y2, x, y;
        int euclidean;
        int rectilinear;

        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x >> y;

        if ((x1 <= x && x <= x2) && (y1 <= y && y <= y2))
        {
            euclidean = 0;
            rectilinear = 0;
        }
        if ((x1 <= x && x <= x2))
        {
            if (y > y2)
            {
                euclidean = pow(y2 - y, 2);
                rectilinear = abs(y2 - y);
            }
            else if (y < y1)
            {
                euclidean = pow(y1 - y, 2);
                rectilinear = abs(y1 - y);
            }
        }
        else if (y1 <= y && y <= y2)
        {
            if (x > x2)
            {
                euclidean = pow(x2 - x, 2);
                rectilinear = abs(x2 - x);
            }
            else if (x < x1)
            {
                euclidean = pow(x1 - x, 2);
                rectilinear = abs(x1 - x);
            }
        }
        else if (x > x2 && y > y2)
        {
            euclidean = pow(x2 - x, 2) + pow(y2 - y, 2);
            rectilinear = abs(x2 - x) + abs(y2 - y);
        }
        else if (x < x1 && y < y1)
        {
            euclidean = pow(x1 - x, 2) + pow(y1 - y, 2);
            rectilinear = abs(x1 - x) + abs(y1 - y);
        }
        else if (x < x1 && y > y2)
        {
            euclidean = pow(x1 - x, 2) + pow(y2 - y, 2);
            rectilinear = abs(x1 - x) + abs(y2 - y);
        }
        else if (x > x2 && y < y1)
        {
            euclidean = pow(x2 - x, 2) + pow(y1 - y, 2);
            rectilinear = abs(x2 - x) + abs(y1 - y);
        }

        cout << euclidean << ' ' << rectilinear << endl;
        i++;
    }
    return 0;
}