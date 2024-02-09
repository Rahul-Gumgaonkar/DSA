#include <iostream>

using namespace std;

void QuickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = end;
    int i = start - 1;
    int j = start;

    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);
    QuickSort(arr, start, i - 1);
    QuickSort(arr, i + 1, end);
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 20, 1};
    int size = 7;
    int start = 0, end = size - 1;

    cout << "Before Sorting Array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    QuickSort(arr, 0, size);
    cout << "After Sorting Array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}