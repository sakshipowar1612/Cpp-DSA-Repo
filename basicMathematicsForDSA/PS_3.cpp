//LCM using GCD
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
    pair<int,int>p = {24, 72};
    int LCD = (p.first*p.second)/gcd(p.first, p.second);
    cout << " LCD = " << LCD << endl;
    return 0;
}