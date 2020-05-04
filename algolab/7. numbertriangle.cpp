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
        int j = 0;
        cin >> k;
        int s[k][k];

        while (j < k)
        {
            int num = 1;

            for (int a = 0; a < k; a++)
            {
                for (int b = a; b < k; b++)
                {
                    s[b][a] = num;
                    num++;
                }
            }
            j++;
        }
        for (int a = 0; a < k; a++)
        {
            for (int b = 0; b <= a; b++)
            {
                cout << s[a][b] << ' ';
            }
            cout << endl;
        }

        i++;
    }
    return 0;
}