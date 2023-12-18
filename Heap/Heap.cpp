#include <iostream>

using namespace std;

class Heap
{
public:
    int *arr = new int[100];
    int size;

    Heap()
    {
        size = 0;
    }

    void insert(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    int deleteElement()
    {
        int index = 1;
        int ans = arr[1];
        arr[index] = arr[size];
        size--;

        while (index <= size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int largest = index;
            if (leftIndex <= size && arr[leftIndex] > arr[largest])
            {
                largest = leftIndex;
            }
            if (rightIndex <= size && arr[rightIndex] > arr[largest])
            {
                largest = rightIndex;
            }

            if (largest != index)
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 30;
    h.arr[5] = 40;
    h.arr[6] = 45;
    h.arr[7] = 55;
    h.arr[8] = 10;
    h.arr[9] = 20;
    h.size = 9;

    cout << "Printing the Element : " << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    h.insert(75);
    cout << "Printing the Element : " << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    int ans = h.deleteElement();
    cout << "Deleted ELement is : " << ans << endl;
    cout << "Printing the Element : " << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }

    return 0;
}