#include <iostream>
using namespace std;

int main()
{
    int t;
    int i = 0;
    cin >> t;

    while (i < t)
    {
        int num;
        cin >> num;
        int a = 1, b, c = 0;
        int d[32];
        unsigned long int result = 0;

        for (int k = 0; k < 32; k++)
        {
            d[k] = 0;
        }

        while (a != 0)
        {
            a = num / 2;
            b = num - a * 2;
            d[c] = b;
            num = a;
            c++;
        }
        int cnt = 0;
        for (int l = 0; l < 32; l++)
        {
            if (d[l] == 1)
                cnt++;
        }
        if (cnt % 2 == 1)
            d[31] = 1;
        unsigned long int saveS = 1;
        for (int s = 0; s < 32; s++)
        {
            if (d[s] == 1)
                result += saveS;
            saveS *= 2;
        }
        cout << result << endl;
        i++;
    }
}