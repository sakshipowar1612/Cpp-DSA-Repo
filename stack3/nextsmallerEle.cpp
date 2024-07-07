#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmaller(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        int min = vec[i];
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < min)
            {
                min = vec[j];
            }
        }
        if (min == vec[i])
        {
            vec[i] = -1;
        }
        else
        {
            vec[i] = min;
        }
    }
}

void printVec(vector<int> vec)
{
    for (int ele : vec)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {2, 1, 4, 6, 3};
    printVec(vec);
    nextSmaller(vec);
    printVec(vec);

}
