#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file;
    file.open("input.txt");

    int t;
    int i = 0;
    file >> t;
    while (i < t)
    {
        int n;
        int k;
        int cnt;
        int temp;
        int var;
        file >> n;
        int sequence[n];
        for (int j = 0; j < n; j++)
        {
            file >> sequence[j];
        }
        file >> k;
        cnt = n - k + 1;
        cout << cnt << ' ';

        for (int l = 0; l < cnt; l++)
        {
            var = 0;
            temp = 0;
            for (int m = l; m < n; m++)
            {
                if (var == k)
                    break;
                temp += sequence[m];
                var++;
            }
            temp /= k;
            cout << temp << ' ';
        }
        cout << endl;
        i++;
    }
    file.close();
    return 0;
}