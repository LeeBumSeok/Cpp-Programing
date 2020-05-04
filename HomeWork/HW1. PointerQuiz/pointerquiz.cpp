#include <iostream>
using namespace std;

int main()
{
    double d;
    char *cp;
    int *ip;
    float *fp;
    double *dp;

    cp = (char *)&d;
    ip = (int *)&d;
    fp = (float *)&d;
    dp = &d;

    cout << d << endl;
    d = 3.14159;

    cout << *cp << ' ' << *ip << ' ' << *fp << ' ' << ' ' << *dp << endl;
}