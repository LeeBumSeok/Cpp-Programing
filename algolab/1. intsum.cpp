#include <iostream>
using namespace std;

int main()
{
    int t, n, j;
    int i = 0;

    cin >> t;

    while (i < t)
    {
        cin >> n;
        int number[n];
        int result = 0;
        for (j = 0; j < n; j++)
        {
            cin >> number[j];
            result += number[j];
        }
        cout << result << endl;
        i++;
    }
}