// Vector
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<vector<int>> arr(5, vector<int>(10, 0));
    // row size = arr.size()   column size = arr[i].size
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    /*
        0 0 0 0 0 0 0 0 0 0
        0 0 0 0 0 0 0 0 0 0
        0 0 0 0 0 0 0 0 0 0
        0 0 0 0 0 0 0 0 0 0
        0 0 0 0 0 0 0 0 0 0
    */
   vector<vector<int>>brr;
   vector<int>vec1(1,1);
   vector<int>vec2(2,2);
   vector<int>vec3(3,3);
   vector<int>vec4(4,4);
    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    brr.push_back(vec4);

    for (int i = 0; i < brr.size(); i++)
    {
        for (int j = 0; j < brr[i].size(); j++)
        {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }

}