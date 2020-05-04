// #include <iostream>
// using namespace std;

// int main()
// {
//     int t;
//     int i = 0;
//     cin >> t;
//     while (i < t)
//     {
//         string bracket;
//         int sbracket = 0;
//         int mbracket = 0;
//         int lbracket = 0;
//         cin >> bracket;

//         for (int j = 0; j < bracket.length(); j++)
//         {
//             if (bracket[j] == '(')
//             {
//                 sbracket += 1;
//                 if (bracket[j + 1] == '}' || bracket[j + 1] == ']')
//                     break;
//             }
//             else if (bracket[j] == '{')
//             {
//                 mbracket += 1;
//                 if (bracket[j + 1] == ')' || bracket[j + 1] == ']')
//                     break;
//             }
//             else if (bracket[j] == '[')
//             {
//                 lbracket += 1;
//                 if (bracket[j + 1] == ')' || bracket[j + 1] == '}')
//                     break;
//             }
//             else if (bracket[j] == ')')
//                 sbracket -= 1;
//             else if (bracket[j] == '}')
//                 mbracket -= 1;
//             else if (bracket[j] == ']')
//                 lbracket -= 1;

//             if (sbracket < 0 || mbracket < 0 || lbracket < 0)
//                 break;
//         }
//         if (sbracket == 0 && mbracket == 0 && lbracket == 0)
//             cout << 1 << endl;
//         else
//             cout << 0 << endl;
//         i++;
//     }
//     return 0;
// }

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int t;
    int i = 0;
    cin >> t;
    while (i < t)
    {
        stack<char> bracket;

        string iBracket;
        cin >> iBracket;
        for (int j = 0; j < iBracket.length(); j++)
        {
            if (iBracket[j] == '(' || iBracket[j] == '{' || iBracket[j] == '[')
                bracket.push(iBracket[j]);
            else if (iBracket[j] == ')' || iBracket[j] == '}' || iBracket[j] == ']')
            {
                if (bracket.empty() != 1)
                {
                    if (iBracket[j] == ')')
                    {
                        if (bracket.top() == '(')
                            bracket.pop();
                        else
                            break;
                    }
                    else if (iBracket[j] == '}')
                    {
                        if (bracket.top() == '{')
                            bracket.pop();
                        else
                            break;
                    }
                    else if (iBracket[j] == ']')
                    {
                        if (bracket.top() == '[')
                            bracket.pop();
                        else
                            break;
                    }
                }
                else
                {
                    bracket.push(1);
                    break;
                }
            }
        }
        cout << bracket.empty() << endl;
        i++;
    }
    return 0;
}