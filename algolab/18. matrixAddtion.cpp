#include <iostream>
using namespace std;

int main()
{
    int t;
    int i = 0;
    cin >> t;
    while (i < t)
    {
        int m;
        int n;

        cin >> m >> n;
        int matrixA[n][m];
        int matrixB[n][m];
        int result[n][m];

        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cin >> matrixA[k][j];
            }
        }
        for (int l = 0; l < m; l++)
        {
            for (int a = 0; a < n; a++)
            {
                cin >> matrixB[a][l];
            }
        }
        for (int b = 0; b < m; b++)
        {
            for (int c = 0; c < n; c++)
            {
                result[c][b] = matrixA[c][b] + matrixB[c][b];
                cout << result[c][b] << ' ';
            }
            cout << endl;
        }
        i++;
    }
    return 0;
}