#include <iostream>

using namespace std;

int merge(int arr[], int start, int end)
{
    int c = 0;
    int mid = start + (end - start) / 2;
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int k = start;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = start;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else if (left[leftIndex] > right[rightIndex])
        {
            arr[mainArrayIndex++] = right[rightIndex++];
            c += len1 - leftIndex;
        }
    }

    while (leftIndex < len1)
    {
        arr[mainArrayIndex++] = left[leftIndex++];
    }
    while (rightIndex < len2)
    {
        arr[mainArrayIndex++] = right[rightIndex++];
    }
    return c;
}

int mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    int mid = start + (end - start) / 2;
    int c = 0;
    c += mergeSort(arr, start, mid);
    c += mergeSort(arr, mid + 1, end);
    c += merge(arr, start, end);
    return c;
}

int main()
{
    int arr[] = {8, 4, 2, 1};
    int size = 4;
    int start = 0;
    int end = size - 1;
    int c = 0;
    c = mergeSort(arr, start, end);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "No. of Inversion is : " << c << endl;
}