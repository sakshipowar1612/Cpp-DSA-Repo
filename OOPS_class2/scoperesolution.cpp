#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    void walk(){
        cout << "walking... " << endl;
    }

};

class Teacher : public Person{
public:
    void teach(){
        cout << "teaching..." << endl;
    }
 
};

class Researcher : public Person{

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
    //solution 1.Scope Resolution
    p.Teacher::walk();
    p.Researcher::walk();

    return 0;
}
