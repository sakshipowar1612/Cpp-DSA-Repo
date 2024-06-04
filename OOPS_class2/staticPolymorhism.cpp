#include<iostream>
using namespace std;


//function overloading
//functions having same name but works differently


// int add(int a, int b){
//     return a+b;
// }

// double add(double a, double b){
//     return a+b;
// }


// int add(int a, int b, int c){
//     return a+b+c;
// }

class vector{
    int x, y;
    public:
        // vector(int x, int y){
        //     this->x = x;
        //     this->y = y;
        // }
    //intit list
        vector(int x, int y): x(x), y(y){}

        //op overloading
        //we want answer in v1 that's why we are tahing v2 as src
        vector  operator+(const vector &src){
            this->x += src.x;
            this->y += src.y;
            return vector(x,y);
        }

        void operator++(){
            this->x++;
            this->y++;
        }

        void display(){
            cout << "x = " << x << " y = " << y << endl;
        }
};

int main(){
    // cout << add(1,2) << " " << add(1.5, 1.6) << " " << add(4,5,1) << endl;
    
    vector v1(1, 2);
    vector v2(3, 4);
    vector v3(5,6);
    vector v4(0,0);

    //v1+v2;

    v1.display();
    v2.display();
    // v1.operator+(v2);
    v4=v1+v2+v3; 
    v4.display();
    ++v1;
    v1.display();
}