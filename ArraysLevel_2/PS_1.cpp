#include <iostream>
using namespace std;

int findUniqueElement(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != -1)
        {
            int found = 0;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] == arr[j])
                {
                    found = 1;
                    arr[j] = -1;
                    break;
                }
            }
            cout << arr[i] << " " << found << endl;
            if (found == 0)
            {
                return arr[i];
            }
        }
    }
}

//Love Babbar's Solution. using XOR operation " ^ ".
int getUnique(int arr[], int size){
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans^arr[i];
        cout << ans << endl;
    }
    
    return ans;
}

int main()
{
    int arr[] = {2, 10, 11, 13, 10, 2, 15, 15, 13};
    cout << "Unique element : " << getUnique(arr, 9);
    return 0;
}