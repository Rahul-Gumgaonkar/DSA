#include <iostream>

using namespace std;

class KQueues
{

public:
    int n, k, freeSpot;
    int *arr, *front, *rear, *next;

    KQueues(int _n, int _k) : n(_n), k(_k), freeSpot(0)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    // push x into qith Queue
    bool push(int x, int qi)
    {
        // overflow
        if (freeSpot == -1)
        {
            return false;
        }
        // find fist free index;
        int index = freeSpot;

        // Update freespot
        freeSpot = next[index];

        // if first element in qi
        if (front[qi] == -1)
        {
            front[qi] = index;
        }
        else
        {
            // link new element to that q's rearest element
            next[rear[qi]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    // pop element from qith Queue
    int pop(int qi)
    {
        // underflow
        if (front[qi] == -1)
        {
            return -1;
        }

        // find index to pop
        int index = front[qi];

        // front update
        front[qi] = next[index];

        // update freeSpots
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    ~KQueues()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main()
{

    KQueues kq(8, 3);
    cout << kq.push(10, 0) << endl;
    cout << kq.push(2, 0) << endl;
    cout << kq.push(5, 1) << endl;
    cout << kq.push(3, 0) << endl;
    cout << kq.pop(1) << endl;
    cout << kq.pop(0) << endl;

    return 0;
}
