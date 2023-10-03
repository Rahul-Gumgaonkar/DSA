#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // creation of Stack using STL
    stack<int> st;

    // Insert Data Into the stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    // Deleting the element of stack
    st.pop();

    // Printing Top Most Element of stack
    cout << "Top Most Elemet of Stack is : " << st.top() << endl;

    // Checking Whether is empty or not
    if (st.empty())
    {
        cout << "Stack is Empty" << endl;
        }
    else
    {
        cout << "stack is Not Empty" << endl;
    }

    // Size of the Stack is
    cout << "Size of the Stack is : " << st.size() << endl;

    // Printing the elemet of stack
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}