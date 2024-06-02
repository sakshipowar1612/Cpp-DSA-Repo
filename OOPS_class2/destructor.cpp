#include<iostream>
#include<string>
#include<vector>
using namespace std;

class student{
private:
    string gf;
public:
    int id;
    int age;
    int present;
    string name;
    int nos;
    int *v;

    //default ctor
    student(){
        cout << "constructor is called" << endl;
    }
    
    //polymeterized ctor
    student(int id, int age, bool present, string name, int nos, string gf){
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        cout << "Student parameterized ctor called" << endl;
    }

    student(int id, int age, bool present, string name, int nos){
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        cout << "Student parameterized ctor w/o gf called" << endl;
    }

    //copy ctor
    student(const student&srcobj){
        this->name = srcobj.name;
        this->id = srcobj.id;
        this->age = srcobj.age;
        this->present = srcobj.present;
        this->nos = srcobj.nos;
        this->gf = srcobj.gf;
        cout << "copy stor is called" << endl;
    }

    ~student(){
        cout << "\n******* Destructor is called *******\n" << endl;
    }

};


int main(){
    
    {
        //scope is defined
        student s1(12, 20, 1, "Nobita", 3, "Sheezuka");
        cout << s1.name << endl;
        //here a destructor is called.
    }
    student s2;
    cout << "as the scope is about to complete, destructor is called" << endl;
    return 0;
}