#include <iostream>
#include <algorithm> // For std::max
using namespace std;

int lenOfLongSubarr(int A[], int N, int K)
{
    int sum = K;
    int size = -1;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        sum = K;
        count = 0;
        for (int j = i; j < N; j++)
        {
            if (sum == 0)
            {
                size = max(size, count);
                cout << count << endl;
                break;
            }
            else if (sum < 0)
            {
                break;
            }
            sum -= A[j];
            cout << sum << endl;
            count++;
            cout << count << endl;
        }
    }
    return size;
}

int main()
{
    int A[] = {1, 4, 3, 3, 5, 5};
    int N = sizeof(A) / sizeof(A[0]);
    int K = 16;

    int result = lenOfLongSubarr(A, N, K);
    if (result != -1)
    {
        cout << "The length of the longest subarray is " << result << endl;
    }
    else
    {
        cout << "No subarray with sum " << K << " found." << endl;
    }

    return 0;
}
