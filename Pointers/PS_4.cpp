#include<iostream>
using namespace std;

int main(){
    char ch[50] = "statement";
    char *cptr = ch;
    cout << ch << endl;
    cout << &ch << endl;
    cout << *(ch + 3) << endl;
    cout << cptr << endl;
    cout << &cptr << endl;
    cout << *(cptr + 3) << endl;
    cout << cptr + 2 << endl;
    cout << *cptr << endl;
    cout << cptr + 8 << endl;
    return 0;
}