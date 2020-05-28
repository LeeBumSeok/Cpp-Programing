#include "cstring"
#include "27.1. MyISBN.h"
// constructors
MyISBN::MyISBN()
{
    isbn[0] = '\0';
}
MyISBN::MyISBN(char isbn_number[])
{
    strcpy(isbn, isbn_number);
}
// utility functions
bool MyISBN::isCorrectNumber() const
{
    if (isSyntaxValid() == false)
        return false;
    if (isSyntaxValid() && isCheckSumValid())
        return true;
    else
        return false;
}
// private functions
bool MyISBN::isSyntaxValid() const
{
    int len = strlen(isbn);
    int hyphen = 0, cnt = 0;
    int hyphenIndex[10];
    for (int i = 0; i < len; i++)
    {
        if (isbn[i] >= '0' && isbn[i] <= '9' || isbn[i] == '-' || isbn[i] == 'X')
        {
            if (isbn[i] == '-')
            {
                hyphenIndex[hyphen] = i;
                hyphen++;
                if (isbn[i + 1] == '-')
                    return false;
            }
        }
        else
            return false;
    }

    if (hyphen != 3)
        return false;

    if (hyphenIndex[0] < 1 || hyphenIndex[0] > 5)
        return false;
    else if (hyphenIndex[1] - hyphenIndex[0] == 1 || hyphenIndex[1] - hyphenIndex[0] > 8)
        return false;
    else if (hyphenIndex[2] - hyphenIndex[1] == 1 || hyphenIndex[2] - hyphenIndex[1] > 7)
        return false;
    else if (len - hyphenIndex[2] - 1 != 1)
        return false;

    return true;
}

bool MyISBN::isCheckSumValid() const
{
    int result[10];
    int count = 0;
    int len = strlen(isbn);
    for (int i = 0; i < len; i++)
    {
        if (isbn[i] != '-')
        {
            result[count] = isbn[i] - 48;
            count++;
        }
    }
    int checkSum;
    int multi = 10;
    int sum = 0;
    for (int k = 0; k < count; k++)
    {
        if (result[k] == 40)
            sum += 10;
        else
        {
            sum += result[k] * multi;
            multi--;
        }
    }

    if (sum % 11 == 0)
        return true;
    else
        return false;
}