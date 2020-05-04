#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, n, j;
    int i = 0;

    cin >> t;

    while (i < t)
    {
        cin >> n;
        int num;
        int number[n];
        if (n == 1)
        {
            cin >> num;
            cout << num << ' ' << num << endl;
        }
        else
        {
            for (j = 0; j < n; j++)
            {
                cin >> number[j];
            }
            sort(number, number + n);
            cout << number[n - 1] << " " << number[0] << endl;
        }
        i++;
    }
}
