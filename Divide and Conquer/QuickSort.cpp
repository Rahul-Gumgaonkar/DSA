#include <iostream>

using namespace std;

int Partition(int arr[], int start, int end)
{
    int pivotIndex = start;
    int pivotEle = arr[start];

    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < pivotEle)
        {
            count++;
        }
    }
    pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] > arr[pivotIndex])
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++, j--;
        }
    }
    return pivotIndex;
}

void QuickSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int index = Partition(arr, start, end);

    QuickSort(arr, start, index);
    QuickSort(arr, index + 1, end);
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