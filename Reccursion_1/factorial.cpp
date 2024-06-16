#include<iostream>
using namespace std;


int factorial(int n){
    int ans = 1;
    if(n==0)
    return 1;
    while(n){
        ans *= n;
        n--;
    }
    return ans;
}


int withreccursion(int n){
    //base case
    if (n==0)
    {
        return 1;
    }
    
    int ans = n*withreccursion(n-1);
    return ans;
    
}

void printCounting(int n){
    if (n==1)
    {
        cout << 1 << " " ;
        return;
    }
    
    printCounting(n-1);
    cout << n << " ";
    return;
}

int twotothepower(int n){
    if (n==0)
    {
        return 1;
    }
    return 2 * twotothepower(n-1); 
}

int fib(int n){
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    int ans = fib(n-2)+fib(n-1);
    return ans;
}

int sumOfN(int n){
    if (n==1)
    {
        return 1;
    }
    
    return n + sumOfN(n-1);
}




int main(){
    // cout << factorial(4) << endl;
    // cout << withreccursion(5) << endl;
    // printCounting(11);
    // cout << endl;
    // cout << twotothepower(0) << endl;
    cout << fib(1) << endl;
    cout << fib(0) << endl;
    cout << fib(7) << endl;
    cout << sumOfN(3) << endl;
}