#include <iostream>
#include <deque>

using namespace std;

int main()
{

    deque<int> dq;
    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(30);
    dq.push_back(40);
    dq.push_back(50);
    dq.push_back(60);

    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }
    cout << endl;

    dq.pop_back();
    dq.pop_front();

    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }
    cout << endl;

    cout << "Size of Deque is : " << dq.size() << endl;
    cout << "Front element is: " << dq.front() << endl;
    cout << "Back element is : " << dq.back() << endl;

    return 0;
}