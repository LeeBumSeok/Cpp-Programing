#include <iostream>
using namespace std;

int main()
{
    int t;
    int i = 0;

    cin >> t;
    while (i < t)
    {
        int prime, j;
        cin >> prime;
        for (j = 2; j < prime; j++)
        {
            if (prime % j == 0)
            {
                cout << '0' << endl;
                break;
            }
        }
        if (j == prime)
            cout << '1' << endl;
        i++;
    }
    return 0;
}
