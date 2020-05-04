#include <iostream>
using namespace std;

int main()
{
    int t;
    int H, M, S, h, m, s;
    int i = 0;

    cin >> t;

    while (i < t)
    {
        int n;
        int j = 0;
        int d = 0;

        int totalHH = 0;
        int totalMM = 0;
        int totalSS = 0;
        int sumH = totalHH / 24;

        cin >> n;
        while (j < n)
        {

            cin >> H >> M >> S >> h >> m >> s;
            int totalH = h - H;
            int totalM = m - M;
            int totalS = s - S;

            if (totalM < 0)
            {
                totalH -= 1;
                totalM += 60;
            }
            if (totalS < 0)
            {
                totalM -= 1;
                totalS += 60;
            }
            totalHH += totalH;
            totalMM += totalM;
            totalSS += totalS;
            j++;
        }
        while (totalSS >= 60)
        {
            totalSS -= 60;
            totalMM += 1;
        }
        while (totalMM >= 60)
        {
            totalMM -= 60;
            totalHH += 1;
        }
        while (totalHH >= 24)
        {
            totalHH -= 24;
            d += 1;
        }
        cout << d << ' ' << totalHH << ' ' << totalMM << ' ' << totalSS << endl;
        i++;
    }
}