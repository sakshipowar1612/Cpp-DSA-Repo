#include<iostream>
using namespace std;

//print sum of row elements.

void rowWiseSum(int arr[][4], int row, int col){
    int sum;
    cout << "Rowwise Sum : " << endl;
    for (int i = 0; i < row; i++)
    {
        sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j];
        }
        cout << "sum of elements in row " << i << " = " << sum << endl;
    }
}

void colWiseSum(int arr[][4], int row, int col){
    int sum;
    cout << "Colwise Sum : " << endl;
    for (int i = 0; i < col; i++)
    {
        sum = 0;
        for (int j = 0; j < row; j++)
        {
            sum += arr[j][i];
        }
        cout << "sum of elements in col " << i << " = " << sum << endl;
    }
}

void digonalWiseSum(int arr[][4], int row, int col){
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i==j)
            {
                sum += arr[i][j];
            }
            
        }
    }
    cout << "Sum of digonal element = " << sum << endl;
}

void secDigonalWiseSum(int arr[][4], int row, int col){
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i+j == 3)
            {
                sum += arr[i][j];
            }
            
        }    
    }
    cout << "Sum of second digonal element = " << sum << endl;
}


int main(){
    int arr[][4] = {
                        {10, 20, 5, 7},
                        {2, 4, 6, 8},
                        {10, 15, 15, 10}
                    };

    int brr[][4] = {
                        {10, 20, 5, 7},
                        {2, 4, 6, 8},
                        {10, 15, 15, 10},
                        {3, 5, 6, 7}
                    };

    rowWiseSum(arr, 3, 4);
    colWiseSum(arr, 3, 4);
    digonalWiseSum(brr, 4, 4);
    secDigonalWiseSum(brr, 4, 4);
}