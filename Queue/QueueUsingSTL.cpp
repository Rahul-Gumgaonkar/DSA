#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout << "Size of Queue is : " << q.size() << endl;
    cout << "Front Element of Queue is : " << q.front() << endl;

    q.pop();

    cout << "Size of Queue is : " << q.size() << endl;
    cout << "Front Element of Queue is : " << q.front() << endl;

    if (q.empty())
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << "Queue is Not Empty" << endl;
    }

    return 0;
}