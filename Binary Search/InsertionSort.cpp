#include <iostream>

using namespace std;

void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int ele = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (ele < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }
        arr[j + 1] = ele;
    }
}

int main()
{
    int arr[] = {1, 3, 5, 4, 7, 2, 8, 9, 5, 67, 5, 3};
    int size = sizeof(arr) / sizeof(int);

    InsertionSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}