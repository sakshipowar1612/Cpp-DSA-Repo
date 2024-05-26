//Transpose the matrix.
#include<iostream>
#include<string>
using namespace std;

void Transpose(int arr[][3], int row, int col){
    int temp;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i > j)
            {
                temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
}

void TransposeMethod(int arr[][3], int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
        
    }
    
}

void print2DArray(int arr[][3], int row, int col){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } 
    
}

int main(){
    int arr[][3] = {
                        {1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}
                    };
    cout << "2D array : " << endl; 
    print2DArray(arr, 3, 3);
    TransposeMethod(arr, 3, 3);
    cout << "Transpose of Matrix : " << endl;
    print2DArray(arr, 3, 3); 
}