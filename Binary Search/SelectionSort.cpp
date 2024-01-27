#include <iostream>
#include <limits.h>

using namespace std;

void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
        swap(arr[index], arr[i]);
    }
}

int main()
{

    int arr[] = {1, 3, 5, 4, 7, 2};
    int size = sizeof(arr) / sizeof(int);

    SelectionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}