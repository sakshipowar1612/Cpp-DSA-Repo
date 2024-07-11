#include <iostream>
#include <queue>
using namespace std;

void give(int arr[], int size, int k)
{
    deque<int> dq;

    // Process first k elements - first window
    for (int index = 0; index < k; index++)
    {
        int element = arr[index];
        if (element < 0)
        {
            dq.push_back(index);
        }
    }

    // Process remaining windows -> Removal and Addition.
    for (int index = k; index < size; index++)
    {
        // aage badhne se pehale purani window ka ans. nikaldo.
        if (dq.empty())
        {
            cout << "0" << endl;
        }
        else
        {
            cout << arr[dq.front()] << endl;
        }
        // Removal - jo bhi index out of range hain, usko queue main se nikal do.
        if (index - dq.front() >= k)
        {
            dq.pop_front();
        }

        // Addition.
        int newEle = arr[index];
        if (newEle < 0)
        {
            dq.push_back(index);
        }
    }

    if (dq.empty())
    {
        cout << "0" << endl;
    }
    else
    {
        cout << arr[dq.front()] << endl;
    }
}

int main()
{
    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    give(arr, 7, 3);
    return 0;
}