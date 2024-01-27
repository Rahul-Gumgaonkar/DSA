#include <iostream>
#include <limits.h>

using namespace std;

int findMax(int arr[], int size)
{
    int maxi = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

bool isPossible(int arr[], int size, int mid, int h)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        // Yaha Galti Hongi
        if (arr[i] > mid)
        {
            sum += arr[i] - mid;
        }
    }
    return sum >= h;
}

int findMaximumHeight(int arr[], int size, int h)
{
    int start = 0;
    int end = findMax(arr, size);
    int ans = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, size, mid, h))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{

    int arr[] = {20, 15, 10, 17};
    int size = sizeof(arr) / sizeof(int);
    int h = 7;

    int ans = findMaximumHeight(arr, size, h);

    cout << "Maximum Height from where the tree cut is : " << ans << endl;

    return 0;
}