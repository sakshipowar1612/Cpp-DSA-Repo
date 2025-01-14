#include<iostream>
using namespace std;

int slowExponentiation(int a, int b){
    //Timecomplexity O(n) here n = b
    int ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
    }
    return ans;
}

int fastExponentiation(int a, int b){
    //Timecomplexity O(logn) here n = b;
    int ans = 1;
    while(b>0){
        if (b^1)
        {
            ans = ans*a;
        }
        a = a*a;
        b >>= 1; // b = b/2;
    }
    return ans;
}

int main(){
    cout << slowExponentiation(2, 5) << endl;
    cout << fastExponentiation(2, 5) << endl;
}