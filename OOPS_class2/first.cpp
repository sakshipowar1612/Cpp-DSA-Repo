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

};

int main(){
    student s1(1, 12, 1, "Choota bheem", 1, "Chutki");
    // student s2 = s1; 
    // student s2(s1);
    student s2;
    s2 = s1;

    // cout << s1.name << "\n" << s2.name << endl;
    return 0;
}