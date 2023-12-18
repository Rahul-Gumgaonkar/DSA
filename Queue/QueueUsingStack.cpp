#include <iostream>
#include <stack>

using namespace std;

stack<int> s1;
stack<int> s2;

void push(int data)
{
    if (s1.empty())
    {
        s1.push(data);
    }
    else
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
}

int pop()
{
    int pop = -1;
    if (s1.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        pop = s1.top();
        s1.pop();
    }
    return pop;
}
int top()
{
    int front = -1;
    if (s1.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        front = s1.top();
    }
}

int main()
{

    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    cout << "Front Element is : " << top() << endl;

    cout << "Pop element is : " << pop() << endl;

    return 0;
}