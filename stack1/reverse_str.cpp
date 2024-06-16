#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str = "Hellojee";
    stack<char>rstr;
    for (int i = 0; i < str.length(); i++)
    {
        rstr.push(str[i]);

    }
    
    
    // int size = rstr.size();
    // for (int i = 0; i < size; i++)
    // {
    //     cout << rstr.top() << " ";
    //     rstr.pop();
    // }

    while (!rstr.empty())
    {
       cout << rstr.top() << " ";
        rstr.pop();
    }
    
    
    cout << endl;
    return 0;

}