#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the Value of N : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            cout << " ";
        }
        int num = 1;
        for (int j = 0; j < 2 * i + 1; j++)
        {

            if (j == 0 || j == 2 * i || (i == n - 1 && j % 2 == 0))
            {
                cout << num;
            }
            else
            {
                cout << " ";
            }
            if (j % 2 == 0)
            {
                num++;
            }
        }
        cout << endl;
    }
    return 0;
}