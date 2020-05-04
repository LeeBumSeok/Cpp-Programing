// #include <iostream>
// using namespace std;

// int main()
// {
//     int t;
//     int i = 0;
//     cin >> t;
//     while (i < t)
//     {
//         int x, y;
//         cin >> x >> y;
//         char room[x][y];
//         int roomnumber[10] = {0};

//         for (int j = 0; j < y; j++)
//         {
//             for (int k = 0; k < x; k++)
//             {
//                 cin >> room[k][j];
//             }
//         }
//         for (int a = 0; a < y; a++)
//         {
//             for (int b = 0; b < x; b++)
//             {
//                 for (int c = 0; c < 10; c++)
//                 {
//                     if (room[b][a] == '.')
//                         roomnumber[c] += 1;
//                 }
//             }
//         }
//         i++;
//     }
// }

#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> stc;

int garho(string data)
{
    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] == '(' || data[i] == '{' || data[i] == '[')
        {
            stc.push(data[i]);
        }
        else
        {
            if (stc.empty() == 1)
            {
                return 0;
            }
            else
            {
                if (data[i] == ']' && stc.top() == '[')
                {
                    stc.pop();
                }
                else if (data[i] == '}' && stc.top() == '{')
                {
                    stc.pop();
                }
                else if (data[i] == ')' && stc.top() == '(')
                {
                    stc.pop();
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    if (stc.empty() == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int testCount;
    cin >> testCount;
    for (int i = 0; i < testCount; i++)
    {
        string data;
        cin >> data;
        cout << garho(data) << endl;
    }
}