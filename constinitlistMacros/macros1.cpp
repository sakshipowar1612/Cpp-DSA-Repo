#include<iostream> 
using namespace std;
#define pi 3.14
#define MAXX(x, y)(x > y ? x : y)

float circleArea(float r){
    return pi*r*r;
}

float circlePerimeter(float r){
    return 2*pi*r;
}

void fun(){
    int x = 6;
    int b = 17;
    int c = MAXX(x, b);
    cout << c << endl; 
}

int main(){
    cout << circleArea(1.5) << " \n" << circlePerimeter(1.5) << endl;
    fun();
    return 0;
}