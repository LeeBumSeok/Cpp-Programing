#include <iostream>
using namespace std;

int main()
{
    int test;
    int i = 0;
    cin >> test;
    while (i < test)
    {
        int r;
        int s;
        int t;
        int sum;

        cin >> r >> s >> t;
        int matrixA[s][r];
        int matrixB[t][s];
        int result[t][r];

        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < s; k++)
            {
                cin >> matrixA[k][j];
            }
        }
        for (int a = 0; a < s; a++)
        {
            for (int b = 0; b < t; b++)
            {
                cin >> matrixB[b][a];
            }
        }
        for (int c = 0; c < r; c++)
        {
            for (int d = 0; d < t; d++)
            {
                result[d][c] = 0;
                for (int q = 0; q < s; q++)
                {
                    result[d][c] += matrixA[q][c] * matrixB[d][q];
                }
                cout << result[d][c] << ' ';
            }
            cout << endl;
        }
        i++;
    }
    return 0;
}
