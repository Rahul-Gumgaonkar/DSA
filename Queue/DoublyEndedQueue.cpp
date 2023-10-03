#include <iostream>

using namespace std;

class DoublyEndedQueue
{
public:
    int size;
    int *arr;
    int front;
    int rear;

    DoublyEndedQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        this->front = -1;
        this->rear = -1;
    }

    void PushRear(int data)
    {
        if ((front == 0 && rear == size - 1) || front == rear + 1)
        {
            cout << "Queue is Full" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[front] = data;
        }
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void PushFront(int data)
    {
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[front] = data;
        }
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = data;
        }
        else
        {
            front--;
            arr[front] = data;
        }
    }

    void PopFront()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void PopRear()
    {
        if (front == -1)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }

    // This Print Function is Only for Checking Do not used it in any interview or online test
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    DoublyEndedQueue dq(6);

    dq.PushFront(10);
    dq.PushFront(20);
    dq.PushFront(30);
    dq.PushRear(40);
    dq.PushRear(50);
    dq.PushRear(60);

    dq.print();

    dq.PopFront();
    dq.PopRear();

    dq.print();

    return 0;
}