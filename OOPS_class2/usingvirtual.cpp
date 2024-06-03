#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    void walk(){
        cout << "walking... " << endl;
    }

};

class Teacher : virtual public Person{            //  <----------------------- SEE HERE
public:
    void teach(){
        cout << "teaching..." << endl;
    }
 
};

class Researcher : virtual public Person{                //  <----------------------- SEE HERE

public:
    void research(){
        cout << "researching... " << endl;
    }

};


class Professor: public Teacher, public Researcher{
public:
    void bore()
    {
        cout << "boring... " << endl;
    }


};

int main(){
    Professor p;
    // p.walk(); //request for memeber 'walk' is ambiguous
    //Diamond Problem
    //solution 2.Using Virtual
    p.walk();

    return 0;
}
