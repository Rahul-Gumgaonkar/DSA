#include <iostream>

using namespace std;

class Stack
{
public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->top = -1;
        this->size = size;
        arr = new int[size];
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack is OverFlow" << endl;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is UnderFlow" << endl;
        }
        else
        {
            top--;
        }
    }

    int getSize()
    {
        return top + 1;
    }

    void getTop()
    {
        if (top == -1)
        {
            cout << "stack is Empty" << endl;
        }
        else
        {
            cout << "Top Element of Stack is : " << arr[top] << endl;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    // st.push(60);

    st.pop();

    while (!st.isEmpty())
    {
        st.getTop();

        st.pop();
    }

    st.pop();
    cout << (st.isEmpty()) ? cout << "Stack is Empty" : cout << "Stack is Not Empty";

    return 0;
}