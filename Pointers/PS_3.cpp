#include<iostream>
using namespace std;

int main(){
    char ch[50] = "Love";
    // char *cptr = &ch; - wrong.
    char *cptr = ch;
    cout << ch << endl;
    cout << &ch << endl;
    cout << ch[0] << endl;
    cout << cptr << endl;
    cout << &cptr << endl;
    cout << *cptr << endl; //*(cptr + 0)
}