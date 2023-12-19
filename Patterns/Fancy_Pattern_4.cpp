#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the Value : ";
    cin >> n;

    int num = 1;
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
                cout << num;
                num++;
            }
        }
        cout << endl;
    }
    int start = num - n;
    for (int i = 0; i < n; i++)
    {
        int k = start;
        for (int j = 0; j < 2 * n - 2 * i - 1; j++)
        {
            if (j & 1)
            {
                cout << "*";
            }
            else
            {
                cout << k;
                k++;
            }
        }
        start = start - (n - i - 1);
        cout << endl;
    }

    return 0;
}