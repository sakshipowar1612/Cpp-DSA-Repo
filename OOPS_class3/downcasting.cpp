#include<iostream>
using  namespace std;


class Parents{

public:
    void relation(){
        cout << "I am parent" << endl;
    }

};
class Daughter: public Parents{

public:
    void relation(){
        cout << "I am daughter" << endl;
    }

};
class Son: public Parents{

public:
    void relation(){
        cout << "I am parent" << endl;
    }

};


int main(){

    Parents *p = new Parents();
    p->relation();
    Parents *p1 = new Daughter();
    p1->relation();
    Daughter *d = new Daughter();
    d->relation();
    // Daughter *d = new Parents();  <------------------ giving error (but in lecture sir said that it doesn't give error in c++ but it is a bad practice)
    // If there is not a virtual function in the class which is at left side, then function at left sides is called.

}