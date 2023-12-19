#include <iostream>

using namespace std;

int main()
{

    int n;
    cout << "Enter the Value of N : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 3 - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j & 1)
            {
                cout << "*";
            }
            else
            {
                cout << i + 1;
            }
        }
        for (int j = 0; j < n + 3 - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}