#include <iostream>
using namespace std;

class abc {
public:
    int x;
    int* y;
    abc(){

    }

    // Constructor
    abc(int _x, int _y) : x(_x), y(new int(_y)) {
          // Allocate memory for y and initialize it
    }

    //deep copy;
    abc(const abc &src){
        this->x = src.x;
        this->y = new int(*src.y);
    }
    // Destructor to free allocated memory
    ~abc() {
        delete y;
    }

    void print() const {
        printf("x: %d\nPTR y: %p\nContent of y(*y): %d\n\n", x, y, *y);
    }
};

int main() {
    abc obj(10, 20);
    cout << "printing a: " << endl;
    obj.print();

    //obj1(obj)
    abc obj1 = obj; //call copy constructor
    cout << "printing b: " << endl;
    obj1.print();
    
    *(obj1.y) = 40;
    cout << "printing b: " << endl;
    obj1.print();
    cout << "printing a: " << endl;
    obj.print();
    return 0;
}
