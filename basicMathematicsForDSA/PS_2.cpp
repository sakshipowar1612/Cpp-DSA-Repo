#include<iostream>
using namespace std;

int gcd(int num1, int num2){
    if (num1 == 0)
       return num2;
    else if(num2 == 0)
       return num1;

    while(num1 > 0 && num2 > 0){
        if( num1 > num2){
            num1 = num1-num2;
        }
        else{
            num2 = num2-num1;
        }
    }
    return num1 == 0 ? num2:num1;
    
}

int main(){
    cout << "GCD of " << gcd(24, 72) << endl;
}