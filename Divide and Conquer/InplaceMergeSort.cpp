#include <iostream>

using namespace std;

void merge(int arr[], int start, int end)
{
    int totel_len = end - start + 1;
    int gap = (totel_len / 2) + (totel_len % 2);

    while (gap > 0)
    {
        int i = start, j = start + gap;
        while (j <= end)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
            i++, j++;
        }
        gap = (gap <= 1) ? 0 : (gap / 2) + (gap % 2);
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