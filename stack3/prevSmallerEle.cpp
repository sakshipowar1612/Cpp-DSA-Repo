#include<iostream>
#include<stack>
#include<vector>
using namespace std;


void prevSmallerEle(vector<int>&vec){
    stack<int>s;
    vector<int>ans;
    s.push(-1);
    for (int i = 0; i < vec.size(); i++)
    {
        while (!s.empty() && s.top()>vec[i])
        {
            s.pop();
        }
        int temp = vec[i];
        vec[i] = s.top();
        s.push(temp); 
    }
    
}

void printVec(vector<int> vec)
{
    for (int ele : vec)
    {
        cout << ele << " ";
    }
    cout << endl;
}


int main(){
    vector<int>vec = {8, 4, 6, 2, 3};
    printVec(vec);
    prevSmallerEle(vec);
    printVec(vec);

}