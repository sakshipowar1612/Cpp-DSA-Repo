//function overriding
#include<iostream>
using namespace std;

class animals{
    public:
    virtual void sound(){
        // Virtual - decision is going to take at runtime;
        cout << "Animal is making sound" << endl;

    }
   
    virtual ~animals(){
        cout << "animal destructor" << endl;
    }
};

class dogs: public animals{
    public:
    void sound() override{
        cout << "Dog is barking" << endl;
    }

    ~dogs(){
        cout << "dogs destructor" << endl;
    }


};

class cats: public animals{
    public:
    void sound() override{
        cout << "cat is mewing" << endl;
    }

    ~cats(){
        cout << "cats destructor" << endl;
    }

};

class parrots: public animals{
    public:
    void sound() override{
        cout << "Parrot is doing meethu meethu" << endl;
    }
};

void sound(animals *a){
    a->sound(); //Polymorphic line  (calling different sound() function for different animal)             <---------------------------SEE HERE
}


int main(){

    // animals *a = new animals();
    // a->sound();

    //animals ani = dogs()   <-------------- wrong approacch
    animals *ani = new dogs();
    sound(ani);

    delete ani;
    return 0;
}

