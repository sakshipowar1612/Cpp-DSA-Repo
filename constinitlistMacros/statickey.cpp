#include<iostream>
using namespace std;

// class abc{
//     public:
//         int x, y;
//         void print() const{
//             cout << x << " " << y << endl;
//         }
// };

// int main(){
//     abc obj1 = {1, 2};
//     abc obj2 = {4, 5};
//     obj1.print();
//     obj2.print();
//     return 0;
// }

//****************STATIC DATA MEMBER****************

// class abc{
//     public:
//         static int x, y;

//         void print() const{
//             cout << x << " " << y << endl;
//         }
// };

// //variable of a class (not a variable of any other object)
// int abc :: x;
// int abc :: y;

// int main(){
//     abc obj1;
//     obj1.x = 1;
//     obj1.y = 2;
//     obj1.print();
//     abc obj2;
//     obj2.x = 4;
//     obj2.y = 6;
//     obj1.print();
//     obj2.print();
//     return 0;
// }

//*************************STATIC MEMBER FUNCTION***********************

class abc{
    public:
        int x, y;

        abc():x(0), y(1){}

        static void print(){
            cout << " I am in Static Function "<< endl;
        }
};

//variable of a class (not a variable of any other object)

int main(){
    abc obj1;
    obj1.x = 1;
    obj1.y = 2;
    abc::print();
    abc obj2;
    obj2.x = 4;
    obj2.y = 6;
    abc::print();
    abc::print();
    return 0;
}

