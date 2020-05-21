#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        char ipv4[16];
        int ipv4Array[4] = {
            0,
        };
        unsigned int num;
        unsigned int sum = 0;
        int num8 = 24;
        int k;
        cin >> k;
        if (k == 1)
        {
            cin >> ipv4;
            char *ptr = strtok(ipv4, ".");
            int count = 0;
            for (int i = 0; i < 4; i++)
            {
                ipv4Array[i] = atoi(ptr);
                ptr = strtok(NULL, ".");
            }
            for (int i = 0; i < 4; i++)
            {
                sum += (ipv4Array[i] << num8);
                num8 -= 8;
            }
            cout << sum;
        }

        else if (k == 2)
        {
            cin >> num;
            for (int i = 0; i < 4; i++)
            {
                ipv4Array[i] = (num >> num8) & 255;
                num8 -= 8;
            }
            for (int i = 0; i < 3; i++)
                cout << ipv4Array[i] << ".";
            cout << ipv4Array[3];
        }
        cout << endl;
    }
    return 0;
}