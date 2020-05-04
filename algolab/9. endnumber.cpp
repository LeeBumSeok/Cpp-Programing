#include <iostream>
using namespace std;

int main()
{
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int k;
        unsigned long result = 1;

        cin >> k;
        unsigned long arr[k];

        for (int m = 0; m < k; m++)
        {
            cin >> arr[m];
            result *= arr[m];
            result %= 10;
        }
        cout << result << endl;
    }
    return 0;
}