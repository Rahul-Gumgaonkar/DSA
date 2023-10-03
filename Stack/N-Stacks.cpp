#include <iostream>

using namespace std;

class NStack
{
    int *a, *top, *next;
    int n;        // no. of stacks
    int size;     // size of main array
    int freeSpot; // tells free space in main array

public:
    NStack(int _n, int _s) : n(_n), size(_s)
    {
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }

        next[size - 1] = -1;
    }

    // Push X into mth stack
    bool push(int X, int m)
    {
        if (freeSpot == -1)
        {
            return false; // stack overflow
        }

        // 1.find index
        int index = freeSpot;

        //  2.update freespot
        freeSpot = next[index];

        //  3.insert
        a[index] = X;

        //  4.Update next
        next[index] = top[m - 1];

        //  5.update top
        top[m - 1] = index;

        return true; // push success
    }

    // pop from mth stack
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return -1; // stack underflow
        }

        int index = top[m - 1];
        top[m - 1] = next[index];
        int poppedElement = a[index];
        next[index] = freeSpot;
        freeSpot = index;
        return poppedElement;
    }

    ~NStack()
    {
        delete[] a;
        delete[] top;
        delete[] next;
    }
};

int main()
{

    NStack st(3, 6);
    cout << st.push(10, 1) << endl;
    cout << st.push(11, 1) << endl;
    cout << st.push(12, 1) << endl;
    cout << st.push(13, 2) << endl;
    cout << st.push(14, 3) << endl;

    cout << st.pop(1) << endl;
    cout << st.pop(2) << endl;

    return 0;
}