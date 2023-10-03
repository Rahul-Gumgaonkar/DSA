#include <iostream>

using namespace std;

class CircularQueue
{
private:
    int size;
    int *arr;
    int front;
    int rear;

public:
    CircularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        // Queue is Full
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout << "Queue is Full" << endl;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if (rear == size - 1 && front != 0)
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

    void pop()
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
            front = 0;
        }
        else
        {
            front++;
        }
    }

    int getSize()
    {
        return rear - front + 1;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int frontEle()
    {
        return arr[front];
    }
};

int main()
{

    CircularQueue q(6);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    return 0;
}