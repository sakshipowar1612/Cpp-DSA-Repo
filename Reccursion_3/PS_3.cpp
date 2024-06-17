#include<iostream>
#include<string.h>
using namespace std;

//Include Exclude Method.

void findSubSequence(string str, string output, int index){
    
    if (index>=str.length())
    {
        //ans output string mein build ho chuka hai
        //print kardo
        cout << "->" << output << endl;
        return;
    }
    char ch = str[index];
    // //exclude;
    // findSubSequence(str, output, index+1);
    // //include;
    // //output string mein ch add kardo.
    // output.push_back(ch);
    // findSubSequence(str, output, index+1);

    //include
    output.push_back(ch);
    findSubSequence(str, output, index+1);

    output.pop_back();
    findSubSequence(str, output, index+1);
}


int main(){
    string s1 = "abc";
    string s2;
    int index = 0;
    findSubSequence(s1,s2,index); 
}