#include "MyHammingCode.h"

// constructors
MyHammingCode::MyHammingCode()
    : value(0) {}

MyHammingCode::MyHammingCode(unsigned int val)
    : value(val) {}

// utility functions
unsigned int MyHammingCode::getEncodedValue()
{
    encodedValue = 0;

    encodedValue |= copyBits(value, 0, 1, 2);
    encodedValue |= copyBits(value, 1, 3, 4);
    encodedValue |= copyBits(value, 4, 7, 8);
    encodedValue |= copyBits(value, 11, 15, 16);

    encodedValue = setParityBit(encodedValue, 1);
    encodedValue = setParityBit(encodedValue, 2);
    encodedValue = setParityBit(encodedValue, 4);
    encodedValue = setParityBit(encodedValue, 8);
    encodedValue = setParityBit(encodedValue, 16);

    return encodedValue;
}

unsigned int MyHammingCode::getDecodedValue()
{
    int errorPos;

    decodedValue = 0;

    errorPos = checkParityBit(value);
    if (errorPos > 0)
        value = negateBit(value, errorPos - 1);

    decodedValue |= copyBits(value, 2, 1, 0);
    decodedValue |= copyBits(value, 4, 3, 1);
    decodedValue |= copyBits(value, 8, 7, 4);
    decodedValue |= copyBits(value, 16, 15, 11);

    return decodedValue;
}

/*
  copyBits copies num bits from the from-th bit of n
  to the to-th bit of num.
*/
unsigned int MyHammingCode::copyBits(unsigned int n, int from, int num, int to)
{
    unsigned int mask = 0;

    // makes mask
    do
    {
        mask <<= 1;
        mask |= 0x01;
    } while (--num);

    // copies num bits from the from-th bit of n
    n >>= from;
    n &= mask;
    return n << to;
}

// setParityBit generates parity bit.
unsigned int MyHammingCode::setParityBit(unsigned int n, int pos)
{
    // masks of P1, P2, P4, P8, P16
    unsigned int mask[5] = {0x55555554, 0x66666664, 0x78787870,
                            0x7F807F00, 0x7FFF0000};

    int count;
    unsigned int checkBits; // checkBits checks parity bit.

    switch (pos)
    {
    case 1:
        checkBits = n & mask[0]; // masking with P1
        break;

    case 2:
        checkBits = n & mask[1]; // masking with P2
        break;

    case 4:
        checkBits = n & mask[2]; // masking with P4
        break;

    case 8:
        checkBits = n & mask[3]; // masking with P8
        break;

    case 16:
        checkBits = n & mask[4]; // masking with P16
        break;
    }

    count = hammingWeight(checkBits);
    if (count % 2) // checks whether error occurs or not.
        n = setBit(n, pos - 1);

    return n;
}

/*
  checkParityBit examines parity bit.
  If an error occurs, it is assumed that an error occurred in only one bit,
  and the location of the bit where the error occurred is returned.
*/
unsigned int MyHammingCode::checkParityBit(unsigned int n)
{
    // masks of P1, P2, P4, P8, P16
    unsigned int mask[5] = {0x55555555, 0x66666666, 0x78787878,
                            0x7F807F80, 0x7FFF8000};
    unsigned int errorPos = 0;

    for (int i = 0; i < 5; ++i)
        if (hammingWeight(n & mask[i]) % 2)
            errorPos += (0x01 << i);

    return errorPos;
}

// hammingWeight calculates the number of digits with bits 1 in a given integer.
int MyHammingCode::hammingWeight(unsigned int n)
{
    return __builtin_popcount(n);
}

// setBit sets the bit of pos digits into 1 in a given integer.
unsigned int MyHammingCode::setBit(unsigned int n, int pos) { return n | (0x01 << pos); }

// clearBit sets the bit of pos digits into 0 in a given integer.
unsigned int MyHammingCode::clearBit(unsigned int n, int pos) { return n & ~(0x01 << pos); }

// checkBit verifies whether the number of pos digits if a given integer is 0 or 1.
int MyHammingCode::checkBit(unsigned int n, int pos) { return n & (0x01 << pos); }

// negateBit reverses the number of pos digits of a given integer.
unsigned int MyHammingCode::negateBit(unsigned int n, int pos) { return n ^ (0x01 << pos); }

// _xor calculates Exclusive OR.
unsigned int MyHammingCode::_xor(unsigned int x, unsigned int y) { return !x ^ !y; }