#include <iostream>
using namespace std;

int main()
{
    int t;
    int i = 0;
    cin >> t;

    while (i < t)
    {
        int n;
        cin >> n;
        int x[n + 1], y[n + 1];
        int xSum = 0, ySum = 0, result = 0, sigma = 0;
        int sign;

        for (int j = 0; j < n; j++)
        {
            cin >> x[j] >> y[j];
        }
        x[n] = x[0];
        y[n] = y[0];
        for (int l = 0; l < n; l++)
        {
            if ((x[l] > 0 && x[l] < 0) || (x[l] < 0 && x[l] > 0))
                x[l] *= -1;
            else if ((y[l] < 0 && y[l + 1] > 0) || (y[l] > 0 && y[l + 1] < 0))
            {
                y[l] *= -1;
            }
            sigma = (x[l] + x[l + 1]) * (y[l + 1] - y[l]);
            result += sigma;
        }

        if (result > 0)
            sign = 1;
        else
            sign = -1;

        cout << abs(result) << ' ' << sign << endl;
        i++;
    }
    return 0;
}