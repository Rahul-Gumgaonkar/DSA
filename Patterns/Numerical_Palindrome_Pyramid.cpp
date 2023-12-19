#include <iostream>

using namespace std;

int main()
{

    int n;
    cout << "Enter the Value of N : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}