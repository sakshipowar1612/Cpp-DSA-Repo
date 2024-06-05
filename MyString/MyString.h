#ifndef MYSTRING_H
#define MYSTRING_H  //If MYSTRING_H is not define then define it.



#include<iostream>

class MyString{

    private:
    char *data; //pointer to character array data
    int length; //size of my string

    public:
        //default ctror
        MyString();

        
        MyString(const char *st);

        MyString(const MyString &other);

        ~MyString();

        int size() const;

        bool empty() const;

};

#endif //MYSTRING_H
