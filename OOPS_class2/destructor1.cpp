#include <iostream>
#include <string>
#include <vector>
using namespace std;

class student
{
private:
    string gf;
public:
    int id;
    int age;
    int present;
    string name;
    int nos;
    int *v;

    // default ctor
    student()
    {
        cout << "constructor is called" << endl;
    }

    // polymeterized ctor
    student(int id, int age, bool present, string name, int nos, string gf)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        this->gf = gf;
        this->v = new int(10);
        cout << "Student parameterized ctor called" << endl;
    }

    student(int id, int age, bool present, string name, int nos)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        cout << "Student parameterized ctor w/o gf called" << endl;
    }

    // copy ctor
    student(const student &srcobj)
    {
        this->name = srcobj.name;
        this->id = srcobj.id;
        this->age = srcobj.age;
        this->present = srcobj.present;
        this->nos = srcobj.nos;
        this->gf = srcobj.gf;
        cout << "copy stor is called" << endl;
    }

    //
    string getGFname(){
        return gf;
        // return this->gf;
    }

    void setGFname(string gf){
        this->gf = gf;
    }

    ~student()
    {
        cout << "\n******* Destructor is called *******\n"<< endl;
        delete v; // here we are deleting the memory

        //allocated memory in heap should be destroyed, otherwise memory will leak // the memory which will be allocated has to be destroyed by you.
        //to destroy this memory, we use destructor; 
    }
};

int main()
{

    student s1(12, 20, 1, "Nobita", 3, "Sheezuka");
    cout << s1.name << " - " << s1.getGFname() << endl; 
    s1.setGFname("Jaiko");
    cout << s1.name << " - " << s1.getGFname() << endl; 

    return 0;
}