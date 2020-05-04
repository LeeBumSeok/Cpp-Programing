#include <iostream>
using namespace std;

int main()
{
    int t, m, n, result = 0;
    int i = 0;
    int j;

    cin >> t;

    while (i < t)
    {
        cin >> m >> n;
        for (j = m; j <= n; j++)
        {
            result += j;
        }
        cout << result << '\n';
        result = 0;
        i++;
    }
}