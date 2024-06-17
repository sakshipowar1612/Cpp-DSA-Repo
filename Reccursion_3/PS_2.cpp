#include <iostream>
using namespace std;

int BST(int arr[], int &left, int &right, int target)
{
    if (left > right)
    {
        return -1;
    }

    int mid = left + right - left / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        right = mid - 1;
        int ans = BST(arr, left, right, target);
        return ans;
    }
    else if (arr[mid] < target)
    {
        left = mid + 1;
        int ans = BST(arr, left, right, target);
        return ans;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 23, 45, 67, 89};
    int left = 0;
    int right = 4;
    cout << BST(arr, left, right, 89);
}