#include <iostream>
#include <algorithm>
using namespace std;

string binaryNumber(unsigned int num)
{
    string binary;
    while (num > 1)
    {
        if (num % 2 == 1)
            binary += '1';
        else
            binary += '0';
        num /= 2;
    }
    binary += '1';
    while (binary.length() < 32)
        binary += '0';
    return binary;
    binary.clear();
}

int getHammingWeight(string num)
{
    int weight = 0;
    for (int j = 0; j < num.length(); j++)
    {
        if (num[j] == '1')
            weight++;
    }
    return weight;
}

int getHammingDistance(string num1, string num2)
{
    int distance = 0;

    for (int j = 0; j < 32; j++)
    {
        if (num1[j] != num2[j])
            distance++;
    }
    return distance;
}

int main()
{
    int numTestCases;
    cin >> numTestCases;

    for (int i = 0; i < numTestCases; i++)
    {
        unsigned int num1, num2;
        cin >> num1 >> num2;

        string numStr1 = binaryNumber(num1);
        string numStr2 = binaryNumber(num2);

        cout << getHammingWeight(numStr1) << ' ' << getHammingWeight(numStr2) << ' '
             << getHammingDistance(numStr1, numStr2) << endl;
    }
    return 0;
}