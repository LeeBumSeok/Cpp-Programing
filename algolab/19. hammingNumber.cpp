#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

vector<unsigned int> hamming;

void is_hamming()
{
    unsigned int max = -1;
    for (unsigned int k = 1;; k *= 2)
    {
        for (unsigned int l = k;; l *= 3)
        {
            for (unsigned int m = l;; m *= 5)
            {
                hamming.push_back(m);
                if (m > max / 5)
                    break;
            }
            if (l > max / 3)
                break;
        }
        if (k > max / 2)
            break;
    }
}
int main()
{
    ifstream file;
    file.open("input.txt");

    int t;
    int i = 0;
    file >> t;
    is_hamming();
    sort(hamming.begin(), hamming.end());

    while (i < t)
    {
        int k;
        file >> k;
        cout << hamming[k - 1] << endl;
        i++;
    }
    file.close();
    return 0;
}