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
        int m;
        int o;
        int setA[131] = {0};
        int setB[131] = {0};
        int intersection[131] = {0};
        int unionSet[131] = {0};
        int difference[131] = {0};

        file >> m;
        for (int j = 0; j < m; j++)
        {
            int a;
            file >> a;
            setA[a] = 1;
        }
        file >> o;
        for (int k = 0; k < o; k++)
        {
            int b;
            file >> b;
            setB[b] = 1;
        }
        int inter = 0;
        int uni = 0;
        int diff = 0;
        for (int h = 0; h < 132; h++)
        {
            if (setA[h] & setB[h])
            {
                intersection[h] = 1;
                inter++;
            }
            if (setA[h] | setB[h])
            {
                unionSet[h] = 1;
                uni++;
            }
            if (!setB[h] & setA[h])
            {
                difference[h] = 1;
                diff++;
            }
        }
        cout << inter << ' ';
        for (int u = 0; u < 132; u++)
        {
            if (intersection[u] == 1)
                cout << u << ' ';
        }
        cout << endl
             << uni << ' ';
        for (int w = 0; w < 132; w++)
        {
            if (unionSet[w] == 1)
                cout << w << ' ';
        }
        cout << endl
             << diff << ' ';
        for (int e = 0; e < 132; e++)
        {
            if (difference[e] == 1)
                cout << e << ' ';
        }
        cout << endl;
        i++;
    }
    file.close();
    return 0;
}