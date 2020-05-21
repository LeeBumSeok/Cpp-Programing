#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        string isbn;
        cin >> isbn;
        int status = 1;
        int hyphen = 0;
        int checkSum = 0;
        int len = isbn.length();
        while (status != 0)
        {
            if (isbn[0] == '-')
            {
                status = 0;
                break;
            }
            for (int i = 0; i < len; i++)
            {
                if (isbn[i] == '-')
                {
                    hyphen++;
                    if (isbn[i + 1] == '-')
                    {
                        status = 0;
                        break;
                    }
                }
                if (isbn[i] >= '0' && isbn[i] <= '9' || isbn[i] == '-' || isbn[i] == 'X')
                    continue;
                else
                {
                    status = 0;
                    break;
                }
            }
            if (status == 0)
                break;
            if (hyphen != 3)
            {
                status = 0;
                break;
            }
            int hyphen1, hyphen2, hyphen3;
            hyphen1 = isbn.find('-');
            hyphen2 = isbn.find('-', hyphen1 + 1);
            hyphen3 = isbn.find('-', hyphen2 + 1);
            if (hyphen1 > 5)
            {
                status = 0;
                break;
            }
            if (hyphen3 - hyphen2 > 7)
            {
                status = 0;
                break;
            }
            if (len - hyphen3 > 2)
            {
                status = 0;
                break;
            }
            isbn.replace(hyphen1, 1, "");
            isbn.replace(hyphen2 - 1, 1, "");
            isbn.replace(hyphen3 - 2, 1, "");
            if (isbn.length() != 10)
            {
                status = 0;
                break;
            }
            int Multi = 10;
            int Sum = 0;
            for (int k = 0; k <= 8; k++)
            {
                Sum += Multi * (isbn[k] - 48);
                Multi--;
            }
            if (Sum % 11 == 0)
                checkSum = 0;
            else
                checkSum = (Sum / 11 + 1) * 11 - Sum;

            if (checkSum != 10)
            {
                if (checkSum != isbn[9] - 48)
                {
                    status = 0;
                    break;
                }
            }
            else
            {
                if (isbn[9] != 'X')
                {
                    status = 0;
                    break;
                }
            }
            break;
        }
        cout << status << endl;
    }
    return 0;
}