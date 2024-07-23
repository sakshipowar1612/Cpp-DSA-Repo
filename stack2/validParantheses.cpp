#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
    if (s.length() == 0 || s.length() == 1)
    {
        return false;
    }
    if (s[0] == ')' || s[0] == '}' || s[0] == ']')
    {
        return false;
    }
    stack<char> st;
    int i = 0;
    while (i != s.length())
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[' )
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (ch == ')' && !st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else if (ch == '}' && !st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else if (ch == ']' && !st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    if (!st.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;
    if (isValid(s))
    {
        cout << "The string is valid." << endl;
    }
    else
    {
        cout << "The string is not valid." << endl;
    }
    return 0;
}