#include <iostream>
#include<vector>
using namespace std;

//INCLUDE EXCLUDE PATTERN

void seqOfString(string str, string substr, int index)
{
    if (index >= str.length())
    {
        cout << "substring = " << substr << endl;
        return;
    }
    else
    {
        char ch = str[index];
        // exclude
        seqOfString(str, substr, index + 1);
        // include
        substr.push_back(ch);
        seqOfString(str, substr, index + 1);


        // //OR
        // // include
        // substr.push_back(ch);
        // seqOfString(str, substr, index + 1);
        // //exclude
        // substr.pop_back();
        // seqOfString(str, substr, index + 1);

        
    }
}

void seqOfStringInVec(string str, string substr, int index, vector<string>&vec)
{
    if (index >= str.length())
    {
        vec.push_back(substr);
        return;
    }
    
    else
    {
        char ch = str[index];

        // // exclude
        // seqOfStringInVec(str, substr, index + 1, vec);
        // // include
        // substr.push_back(ch);
        // seqOfStringInVec(str, substr, index + 1, vec);


        //OR
        // include
        substr.push_back(ch);
        seqOfStringInVec(str, substr, index + 1, vec);
        //exclude
        substr.pop_back();
        seqOfStringInVec(str, substr, index + 1, vec);

        
    }
}

int main()
{
    seqOfString("abc", "", 0);
    vector<string>ans;
    seqOfStringInVec("abc", "", 0, ans);
    for(string i : ans){
        cout << i << endl;
    }
    cout << ans.size();
}