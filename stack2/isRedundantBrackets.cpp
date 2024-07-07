#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isRedundant(string str){
    stack<char>s;
    int i = 0;
    while (i<str.length())
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            int opera = 0;
            while (!s.empty() &&  s.top()!='(')
            {
                opera++;
                s.pop();
            }
            if (!s.empty())
            {
                s.pop();
            }
            if (opera==0)
            {
                return true;
            }
            
            
        }
        
        
        i++;
    }
    return false;
    
}


int main(){
    string str = "((a+b))";
    cout << isRedundant(str) << endl;
}