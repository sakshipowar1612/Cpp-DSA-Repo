#include <iostream>
#include <stack>
#include<limits>
using namespace std;

int solve(stack<int> *s1, int &pos)
{
    if (pos != 0)
    {
        int temp = s1->top();
        s1->pop();
        pos--;
        solve(s1, pos);
        s1->push(temp);
    }
    else return INT_MIN;
}
