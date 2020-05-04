#include <iostream>
using namespace std;

int main()
{
    int t, k;
    int i = 0;

    cin >> t;

    while (i < t)
    {
        int j = 0;
        cin >> k;
        while (j < k)
        {
            for (int m = 0; m < k; m++)
            {
                if (j == k / 2)
                {
                    for (int l = 0; l < k; l++)
                    {
                        if (l == k / 2)
                            cout << 'O';
                        else
                            cout << '+';
                    }
                    cout << endl;
                    j++;
                }
                else if (j != k / 2)
                {
                    for (int o = 0; o < k; o++)
                    {
                        if (o == k / 2)
                            cout << 'I';
                        else if (m == k - o - 1)
                            cout << '*';
                        else
                            cout << '.';
                    }
                    cout << endl;
                    j++;
                }
            }
        }
        i++;
    }
}
