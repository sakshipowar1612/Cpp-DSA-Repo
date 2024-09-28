#include <iostream>
#include <string>
#include<string.h>
using namespace std;

bool checkPalindrome(string s)
{
    cout << s << endl;
    int i = 0;
    int j = s.length() - 1;
    bool isPalindrome = true;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            isPalindrome = false;
            break;
        }
        i++;
        j--;
    }
    return isPalindrome;
}


int countSubstrings(string s)
{
    int n = s.length();
    int noOfSubPal = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            string sub = s.substr(i, j);
            bool isPal = checkPalindrome(sub);
            cout << isPal << endl;
            if (isPal == true)
            {
                noOfSubPal += 1;
            }
        }
    }
    return noOfSubPal;
}


int main(){
    string str = "abc";
    cout << countSubstrings(str) << endl;

}