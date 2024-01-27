#include <iostream>

using namespace std;

void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isSwap = false;
        for (int j = 1; j < size - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                isSwap = true;
                swap(arr[j - 1], arr[j]);
            }
        }
        if (!isSwap)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {1, 3, 5, 4, 7, 2, 8, 9, 5, 67, 5, 3};
    int size = sizeof(arr) / sizeof(int);

    BubbleSort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}