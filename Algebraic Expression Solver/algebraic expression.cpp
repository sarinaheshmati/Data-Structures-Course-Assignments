//
//  main.cpp
//  ebjabri
//
//  Created by MacBook on 8/10/1401 AP.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> ooperator;
stack<long long int> operand;
long long int m = 1000000000 + 7;
long long int a, b;

int check (char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*')
        return 2;
    else
        return 0;
}


int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            int t = 0;
            while(s[i] >= '0' && s[i] <= '9')
            {
                t = t * 10 + (s[i] - '0');
                i++;
            }
            i--;
            operand.push(t);
            continue;
        }
        else
        {
            if (ooperator.empty())
                ooperator.push(s[i]);
            else
            {
                if (s[i] == '(')
                {
                    ooperator.push(s[i]);
                    continue;
                }
                if (s[i] == ')')
                {
                    while (!ooperator.empty() && ooperator.top() != '(' )
                    {
                        if(!ooperator.empty() && ooperator.top() == '+')
                        {
                            b = operand.top();
                            operand.pop();
                            a = operand.top();
                            operand.pop();
                            operand.push(((a % m) + (b % m)) % m);
                            ooperator.pop();
                        }
                        else if(!ooperator.empty() && ooperator.top() == '-')
                        {
                            b = operand.top();
                            operand.pop();
                            a = operand.top();
                            operand.pop();
                            operand.push((((a % m) - (b % m)) + m ) % m);
                            ooperator.pop();
                        }
                        else if(!ooperator.empty() && ooperator.top() == '*')
                        {
                            b = operand.top();
                            operand.pop();
                            a = operand.top();
                            operand.pop();
                            operand.push(((a % m) * (b % m)) % m);
                            ooperator.pop();
                        }
                    }
                    ooperator.pop();
                    continue;
                }
                if((!ooperator.empty()) && ((check(s[i])) > (check(ooperator.top()))))
                {
                    ooperator.push(s[i]);
                }
                else
                {
                    while((!ooperator.empty()) && ((check(s[i]) <= check(ooperator.top()))))
                    {
                        if((!ooperator.empty()) && (ooperator.top() == '+'))
                        {
                            b = operand.top();
                            operand.pop();
                            a = operand.top();
                            operand.pop();
                            operand.push(((a % m) + (b % m)) % m);
                            ooperator.pop();
                        }
                        else if((!ooperator.empty()) && (ooperator.top() == '-'))
                        {
                            b = operand.top();
                            operand.pop();
                            a = operand.top();
                            operand.pop();
                            operand.push((((a % m) - (b % m)) + m ) % m);
                            ooperator.pop();
                        }
                        else if((!ooperator.empty()) && (ooperator.top() == '*'))
                        {
                            b = operand.top();
                            operand.pop();
                            a = operand.top();
                            operand.pop();
                            operand.push(((a % m) * (b % m)) % m);
                            ooperator.pop();
                        }
                    }
                    ooperator.push(s[i]);
                }
            }
        }
    }
    while (!ooperator.empty())
    {
        if((!ooperator.empty()) && (ooperator.top() == '+'))
        {
            b = operand.top();
            operand.pop();
            a = operand.top();
            operand.pop();
            operand.push(((a % m) + (b % m)) % m);
            ooperator.pop();
        }
        else if((!ooperator.empty()) && (ooperator.top() == '-'))
        {
            b = operand.top();
            operand.pop();
            a = operand.top();
            operand.pop();
            operand.push((((a % m) - (b % m)) + m ) % m);
            ooperator.pop();
        }
        else if((!ooperator.empty()) && (ooperator.top() == '*'))
        {
            b = operand.top();
            operand.pop();
            a = operand.top();
            operand.pop();
            operand.push(((a % m) * (b % m)) % m);
            ooperator.pop();
        }
        
    }
    cout << operand.top() % m << endl;
    return 0;
}
