#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

bool compareInterval(tuple<char, string, string, char> t1, tuple<char, string, string, char> t2)
{
    if (stoi(get<1>(t1)) == stoi(get<1>(t2)))
        return (stoi(get<2>(t1)) <= stoi(get<2>(t2)));
    return (stoi(get<1>(t1)) <= stoi(get<1>(t2)));

}

int main() {
    int n;
    cin >> n;

    tuple<char, string, string, char> intervals[n];
    string s1, s2;

    string oop = "2147483647";
    string oon = "-2147483647";

    for(int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;

        string first = "",second = "";
        char a, b;
        for(int j = 1; j < s1.length() - 1; j++)
            first += s1[j];

        for(int j = 0; j < s2.length() - 1; j++)
            second += s2[j];


        if(second == "inf" && s1[0] == '(')
        {
            a = '(';
            b = ')';
            second = oop;
        }

        else if(second == "inf" && s1[0] == '[')
        {
            a = '[';
            b = ')';
            second = oop;
        }

        else if(first == "-inf" && s2[s2.length() - 1] == ')')
        {
            a = '(';
            b = ')';
            first = oon;
        }

        else if(first == "-inf" && s2[s2.length() - 1] == ']')
        {
            a = '(';
            b = ']';
            first = oon;
        }

        else if(s1[0] == '(' && s2[s2.length() - 1] == ')')
        {
            a = '(';
            b = ')';
        }

        else if(s1[0] == '(' && s2[s2.length() - 1] == ']')
        {
            a = '(';
            b = ']';
        }

        else if(s1[0] == '[' && s2[s2.length() - 1] == ')')
        {
            a = '[';
            b = ')';
        }

        else if(s1[0] == '[' && s2[s2.length() - 1] == ']')
        {
            a = '[';
            b = ']';
        }

        intervals[i] = make_tuple(a, first, second, b);




    }

    sort(intervals, intervals + n, compareInterval);





    int l1 = stoi(get<1>(intervals[0]));
    int r1 = stoi(get<2>(intervals[0]));
    char a1 = get<0>(intervals[0]);
    char b1 = get<3>(intervals[0]);
    for(int i = 1; i < n; i++)
    {
        int l2 = stoi(get<1>(intervals[i]));
        int r2 = stoi(get<2>(intervals[i]));
        char a2 = get<0>(intervals[i]);
        char b2 = get<3>(intervals[i]);

        if(r1 > l2 || (r1 == l2 && (b1 == ']' || a2 == '[')))
        {
            if(r2 > r1)
            {
                r1 = r2;
                b1 = b2;
            }
            if(r2 == r1 && (b2 == ']' || b1 == ']'))
                b1 = ']';
            if(l2 == l1 && (a2 == '[' || a1 == '['))
                a1 = '[';
        }
        else
        {
            if(r1 == stoi(oop) && l1 == stoi(oon))
                cout << a1 << "-inf" << ", " << "inf" << b1 << " U ";
            else if(r1 != stoi(oop) && l1 == stoi(oon))
                cout << a1 << "-inf" << ", " << r1 << b1 << " U ";
            else if(r1 == stoi(oop) && l1 != stoi(oon))
                cout << a1 << l1 << ", " << "inf" << b1 << " U ";
            else
                cout << a1 << l1 << ", " << r1 << b1 << " U ";

            l1 = l2;
            r1 = r2;
            a1 = a2;
            b1 = b2;
        }
    }

    if(r1 == stoi(oop) && l1 == stoi(oon))
        cout << a1 << "-inf" << ", " << "inf" << b1 << endl;
    else if(r1 != stoi(oop) && l1 == stoi(oon))
        cout << a1 << "-inf" << ", " << r1 << b1 << endl;
    else if(r1 == stoi(oop) && l1 != stoi(oon))
        cout << a1 << l1 << ", " << "inf" << b1 << endl;
    else
        cout << a1 << l1 << ", " << r1 << b1 << endl;

    return 0;
}
