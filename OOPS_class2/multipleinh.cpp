#include<iostream>
#include<string>
using namespace std;

class person{
public:
    void walk(){
        cout << "walking... " << endl;
    }

};

class Teacher : public person{
public:
    void teach(){
        cout << "teaching..." << endl;
    }
 
};

class researcher : public person{

public:
    void research(){
        cout << "researching... " << endl;
    }

};


class professor: public Teacher, public researcher,{
public:
    void bore()
    {
        cout << "boring... " << endl;
    }


};

int main(){
    professor p;
    // p.walk(); //request for memeber 'walk' is ambiguous
    return 0;
}
