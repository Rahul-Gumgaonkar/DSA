#include <iostream>

using namespace std;

void merge(int arr[], int start, int end)
{
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

    int leftIndex = 0, rightIndex = 0, mainArrayIndex = start;

    while (leftIndex < len1 && rightIndex < len2)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex++] = left[leftIndex++];
        }
        else
        {
            arr[mainArrayIndex++] = right[rightIndex++];
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
}

void MergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 20};
    int size = 6;
    int start = 0, end = size - 1;

    cout << "Before Sorting Array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    MergeSort(arr, 0, size);
    cout << "After Sorting Array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}