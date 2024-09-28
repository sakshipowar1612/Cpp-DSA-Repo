#include<iostream>
#include<string.h>
using namespace std;

bool checkPalindrome(char ch[], int size){
    int i=0;
    int j=size-1;
    bool isPalindrome=true;
    while(i<j){
        if(ch[i]!=ch[j]){
            isPalindrome = false;
            break;
        }
        i++;
        j--;
    }
    return isPalindrome;
}

int main(){
    char ch[10];
    cin >> ch;
    cout << checkPalindrome(ch, strlen(ch));
}