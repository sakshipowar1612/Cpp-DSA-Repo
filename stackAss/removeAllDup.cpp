#include <iostream>
#include <stack>
using namespace std;
//Remove all adjacent duplicates in string
string removeDuplicates(string s)
{
    stack<char> box;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (box.empty())
        {
            box.push(s[i]);
            
        }
        else if (!box.empty() && s[i] == box.top())
        {
            while (!box.empty() && s[i] == box.top())
            {
                box.pop();
            }
        }
        else
        {
            box.push(s[i]);
            
        }
    }
    string ans = "";
    // cout << box.empty() << endl;
    while (!box.empty())
    {
        ans.push_back(box.top());
        // cout << box.top() << " ";
        box.pop();
    }
    return ans;
}

int main(){
    string s = "abbaca";
    s = removeDuplicates(s);
    for(char i: s){
        cout << i << " ";
    }
}