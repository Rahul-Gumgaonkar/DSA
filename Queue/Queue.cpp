#include <iostream>

using namespace std;

class Queue
{
private:
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        this->front = 0;
        this->rear = 0;
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if (front == rear)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int getSize()
    {
        return rear - front;
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getFront()
    {
        if (front == rear)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            return arr[front];
        }
    }
};

int main()
{

    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "size of Queue is : " << q.getSize() << endl;
    cout << "Front Element of Queue is: " << q.getFront() << endl;

    q.pop();

    cout << "size of Queue is : " << q.getSize() << endl;
    cout << "Front Element of Queue is: " << q.getFront() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is Not Empty" << endl;
    }

    return 0;
}