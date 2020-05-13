#include <iostream>
using namespace std;

int *getEncodeBinaryNumber(unsigned int num, int parity[])
{
    int parityBit = 1;
    for (int i = 0; i < 32; i++)
    {
        if (i == parityBit - 1)
        {
            parity[i] = 2;
            parityBit *= 2;
        }
        else
        {
            if (num > 0)
            {
                parity[i] = num % 2;
                num /= 2;
            }
            else
                parity[i] = 0;
        }
    }
    parity[31] = 0;
    return parity;
}

int *getDecodeBinaryNumber(unsigned int num, int parity[])
{
    for (int j = 0; j < 32; j++)
    {
        if (num > 0)
        {
            parity[j] = num % 2;
            num /= 2;
        }
        else
            parity[j] = 0;
    }
    return parity;
}

unsigned int getDecimalNumber(int parity[])
{
    unsigned int decimal = 1;
    unsigned int result = 0;
    for (int k = 0; k < 32; k++)
    {
        if (parity[k] == 1)
            result += decimal;
        decimal *= 2;
    }
    return result;
}

int P1(int parity[])
{
    int p1 = 0;
    for (int l = 0; l < 31; l++)
    {
        if (l % 2 == 0)
        {
            if (parity[l] == 1)
                p1++;
        }
    }
    return p1;
}

int P2(int parity[])
{
    int p2 = 0;
    int index = 1;
    int limit = 0;
    while (index < 31)
    {
        if (parity[index] == 1)
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

int P4(int parity[])
{
    int p4 = 0;
    int index = 3;
    int limit = 0;
    while (index < 31)
    {
        if (parity[index] == 1)
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

int P8(int parity[])
{
    int p8 = 0;
    int index = 7;
    int limit = 0;
    while (index < 31)
    {
        if (parity[index] == 1)
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

int P16(int parity[])
{
    int p16 = 0;
    for (int index = 15; index < 31; index++)
    {
        if (parity[index] == 1)
            p16++;
    }
    return p16;
}

int *convertHammingcode(int parity[])
{
    if (P1(parity) % 2 == 1)
        parity[0] = 1;
    else
        parity[0] = 0;

    if (P2(parity) % 2 == 1)
        parity[1] = 1;
    else
        parity[1] = 0;

    if (P4(parity) % 2 == 1)
        parity[3] = 1;
    else
        parity[3] = 0;

    if (P8(parity) % 2 == 1)
        parity[7] = 1;
    else
        parity[7] = 0;

    if (P16(parity) % 2 == 1)
        parity[15] = 1;
    else
        parity[15] = 0;

    return parity;
}

int *decodeHammingcode(int parity[])
{
    int errorNumber = 0;
    int errorCnt = 0;

    if (P1(parity) % 2 == 1)
    {
        errorNumber += 1;
        errorCnt++;
    }
    if (P2(parity) % 2 == 1)
    {
        errorNumber += 2;
        errorCnt++;
    }
    if (P4(parity) % 2 == 1)
    {
        errorNumber += 4;
        errorCnt++;
    }
    if (P8(parity) % 2 == 1)
    {
        errorNumber += 8;
        errorCnt++;
    }
    if (P16(parity) % 2 == 1)
    {
        errorNumber += 16;
        errorCnt++;
    }

    if (parity[errorNumber - 1] == 1)
        parity[errorNumber - 1] = 0;
    else
        parity[errorNumber - 1] = 1;

    return parity;
}

unsigned int getDecimalDecodeNumber(int parity[])
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
        if (parity[o] == 1)
            result += decimal;
        decimal *= 2;
    }
    return result;
}

int main()
{
    int numTestCases;
    cin >> numTestCases;
    for (int q = 0; q < numTestCases; q++)
    {
        int type;
        int parity[32];
        unsigned int num;
        cin >> type >> num;

        if (type == 0)
        {
            getEncodeBinaryNumber(num, parity);
            convertHammingcode(parity);
            cout << getDecimalNumber(parity);
        }
        else
        {
            getDecodeBinaryNumber(num, parity);
            decodeHammingcode(parity);
            cout << getDecimalDecodeNumber(parity);
        }
        cout << endl;
    }
    return 0;
}