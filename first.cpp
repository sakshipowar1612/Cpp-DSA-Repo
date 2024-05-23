#include<iostream>
#include<bit>
using namespace std;

int sum_in_range(int x, int y){
    int result = 0;
    for (int i = x; i <= y; i++)
    {
        result += i;
    }
    return result;
}

int sum_in_range_optimised(int x, int y){
    int a = x;
    int n = (y-x+1);
    int result = (n*(2*a+(n-1)*1))/2;
    return result;
}

int main(){
    cout << sum_in_range_optimised(6, 8) << endl;
}