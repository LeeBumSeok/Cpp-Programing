#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

string decimalToBinary(unsigned int num, string binaryNum)
{
    int temp;
    binaryNum = bitset<31>(num).to_string();
    reverse(binaryNum.begin(), binaryNum.end());
    return binaryNum;
}

unsigned int binaryToDecimal(unsigned int num, string binaryNum, unsigned int result)
{
    int length = binaryNum.length();
    unsigned int decimal = 1;
    result = 0;
    for (int l = 0; l < length; l++)
    {
        if (binaryNum[l] == '1')
            result += decimal;
        decimal *= 2;
    }
    return result;
}

string insertParityBit(string binaryNum)
{
    int geometricWaterSupply = 1;
    string parityBit = "2";
    for (int j = 0; j < 31; j++)
    {
        if (j == geometricWaterSupply - 1)
        {
            binaryNum.insert(j, "2");
            geometricWaterSupply *= 2;
        }
    }
    return binaryNum;
}

int checkP1(string binaryNum)
{
    int p1 = 0;

    for (int k = 0; k < 31; k++)
    {
        if (k % 2 == 0)
        {
            if (binaryNum[k] == '1')
                p1++;
        }
    }
    return p1;
}

int checkP2(string binaryNum)
{
    {
        int p2 = 0;
        int index = 1;
        int limit = 0;
        while (index < 31)
        {
            if (binaryNum[index] == '1')
                p2++;
            index++;
            limit++;
            if (limit == 2)
            {
                index += 2;
                limit = 0;
            }
        }
        return p2;
    }
}

int checkP4(string binaryNum)
{
    int p4 = 0;
    int index = 3;
    int limit = 0;
    while (index < 31)
    {
        if (binaryNum[index] == '1')
            p4++;
        index++;
        limit++;
        if (limit == 4)
        {
            index += 4;
            limit = 0;
        }
    }
    return p4;
}

int checkP8(string binaryNum)
{
    int p8 = 0;
    int index = 7;
    int limit = 0;
    while (index < 31)
    {
        if (binaryNum[index] == '1')
            p8++;
        index++;
        limit++;
        if (limit == 8)
        {
            index += 8;
            limit = 0;
        }
    }
    return p8;
}

int checkP16(string binaryNum)
{
    int p16 = 0;
    for (int index = 15; index < 31; index++)
    {
        if (binaryNum[index] == '1')
            p16++;
    }
    return p16;
}

string convertHammingCode(string binaryNum)
{
    int p1, p2, p4, p8, p16;
    p1 = checkP1(binaryNum);
    p2 = checkP2(binaryNum);
    p4 = checkP4(binaryNum);
    p8 = checkP8(binaryNum);
    p16 = checkP16(binaryNum);

    if (p1 % 2 == 0)
        binaryNum[0] = '0';
    else
        binaryNum[0] = '1';
    if (p2 % 2 == 0)
        binaryNum[1] = '0';
    else
        binaryNum[1] = '1';
    if (p4 % 2 == 0)
        binaryNum[3] = '0';
    else
        binaryNum[3] = '1';
    if (p8 % 2 == 0)
        binaryNum[7] = '0';
    else
        binaryNum[7] = '1';
    if (p16 % 2 == 0)
        binaryNum[15] = '0';
    else
        binaryNum[15] = '1';

    return binaryNum;
}

string decodeHammingCode(string binaryNum)
{
    int error = 0;
    int p1, p2, p4, p8, p16;
    p1 = checkP1(binaryNum);
    p2 = checkP2(binaryNum);
    p4 = checkP4(binaryNum);
    p8 = checkP8(binaryNum);
    p16 = checkP16(binaryNum);

    if (p1 % 2 == 1)
        error += 1;
    if (p2 % 2 == 1)
        error += 2;
    if (p4 % 2 == 1)
        error += 4;
    if (p8 % 2 == 1)
        error += 8;
    if (p16 % 2 == 1)
        error += 16;

    if (error != 0)
    {
        if (binaryNum[error - 1] == '1')
            binaryNum[error - 1] = '0';
        else
            binaryNum[error - 1] = '1';
    }
    return binaryNum;
}

unsigned int getDecimalDecodeNumber(string binaryNum)
{

    unsigned int decimal = 1;
    int geometricWaterSupply = 1;
    unsigned int result = 0;
    for (int o = 0; o < 32; o++)
    {
        if (o == geometricWaterSupply - 1)
        {
            geometricWaterSupply *= 2;
            continue;
        }
        if (binaryNum[o] == '1')
            result += decimal;
        decimal *= 2;
    }
    return result;
}

unsigned int getEncodeValue(unsigned int inputNum, string binaryNum, unsigned int result)
{
    binaryNum = decimalToBinary(inputNum, binaryNum);
    binaryNum = insertParityBit(binaryNum);
    binaryNum = convertHammingCode(binaryNum);
    result = binaryToDecimal(inputNum, binaryNum, result);

    return result;
}

unsigned int getDecodeValue(unsigned int inputNum, string binaryNum, unsigned int result)
{
    binaryNum = decimalToBinary(inputNum, binaryNum);
    binaryNum = decodeHammingCode(binaryNum);
    result = getDecimalDecodeNumber(binaryNum);

    return result;
}

int main()
{
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++)
    {
        int type;
        unsigned int num, result;
        string binaryNum;
        cin >> type >> num;
        if (type == 0)
            result = getEncodeValue(num, binaryNum, result);
        else
            result = getDecodeValue(num, binaryNum, result);
        cout << result << endl;
    }
    return 0;
}
