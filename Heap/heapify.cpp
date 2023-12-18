#include <iostream>

using namespace std;

void heapify(int arr[], int size, int i)
{
    int index = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = index;

    if (left <= size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        index = largest;
        heapify(arr, size, index);
    }
}

void buildHeap(int arr[], int size)
{

    for (int i = size / 2; i > 0; i--)
    {
        heapify(arr, size, i);
    }
}

void headSort(int arr[], int size)
{
    while (size > 1)
    {
        swap(arr[1], arr[size--]);
        heapify(arr, size, 1);
    }
}

int main()
{
    int arr[] = {-1, 12, 14, 13, 17, 15};
    int size = 5;
    buildHeap(arr, size);

    cout << "Printing the element : " << endl;
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    headSort(arr, size);
    cout << "Printing the element : " << endl;
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}