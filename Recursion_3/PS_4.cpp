#include<iostream>
#include<vector>
using namespace std;

int cutIntoSeg(int num, int x, int y, int z){
    
    if (num<=0 || (num < x && num < y && num < z))
    {
        return 0;
    }

    //maine x len ka 1 segment cut karliya and baaki recursion dekhlega
    int option1 = 1 + cutIntoSeg(num-x, x, y, z);
    
    //maine y len ka 1 segment cut karliya and baaki recursion dekhlega
    int option2 = 1 + cutIntoSeg(num-y, x, y, z);

    //maine z len ka 1 segment cut karliya and baaki recursion dekhlega
    int option3 = 1 + cutIntoSeg(num-z, x, y, z);

    return max(option1, max(option2, option3));
}

int main(){
    cout << cutIntoSeg(5, 5, 2, 3);

}