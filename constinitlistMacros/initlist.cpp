#include<iostream>
using namespace std;

class abc{
    int x;
    int *y;
    int z;
    public:

    //ctor: old method
    // abc(int _x, int _y, int _z=0){
    //     x = _x;
    //     *y = _y;
    //     z = _z;
    // }

    //initialization list
    abc(int _x, int _y, int _z):x(_x), y(new int(_y)), z(_z){};

    void setX(int _x){
        this->x = _x;
    }
    int getX() const{
        return x;
    }
    void setY(int _y){
       *y = _y;
    }
    int getY() const{
        return *y;
    }
    void setZ(int _z){
       z = _z;;
    }
    int getZ() const{
        return z;
    }


};

int main(){
    abc a1(1, 2, 3);
    cout << a1.getX() << " " << a1.getY() << " " << a1.getZ()<< endl;
    return 0;

}