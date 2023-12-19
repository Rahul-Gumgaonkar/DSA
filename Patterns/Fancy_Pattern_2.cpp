#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the Value : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
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
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 2 * i; j++)
        {
            if (j % 2 == 0)
            {
                cout << n - i;
            }
            else if (j != 2 * n - 2 * i - 1)
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}