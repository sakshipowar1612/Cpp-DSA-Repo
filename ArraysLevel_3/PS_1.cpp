#include<iostream>
using namespace std;

bool search(int arr[][3], int col, int row, int target){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j]== target)
            return true;
        }
    }
    return false;  
}

int main(){
    int arr[][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    if (search(arr, 3, 3, 10))
    {
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    
}