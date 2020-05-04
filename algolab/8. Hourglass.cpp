#include <iostream>
using namespace std;

int main()
{
    int t;
    int i = 0;

    cin >> t;

    while (i < t)
    {
        int k;
        cin >> k;

        char s[k][k];

        int j = 0;
        while (j < k)
        {
            if (j % 2 == 0)
            {
                for (int a = 0; a < k; a++)
                {
                    if (a % 2 == 0)
                        s[j][a] = '*';
                    else
                        s[j][a] = '+';
                }
            }
            else
            {
                for (int a = 0; a < k; a++)
                {
                    if (a % 2 == 0)
                        s[j][a] = '+';
                    else
                        s[j][a] = '*';
                }
            }
            int fw = 1;
            int back = k - 2;

            for (int c = 0; c < k / 2; c++)
            {
                for (int d = fw; d <= back; d++)
                {
                    s[d][c] = '-';
                    s[d][k - c - 1] = '-';
                }
                fw++;
                back--;
            }
            j++;
        }

        for (int a = 0; a < k; a++)
        {
            for (int b = 0; b < k; b++)
            {
                cout << s[a][b];
            }
            cout << endl;
        }
        i++;
    }
    return 0;
}