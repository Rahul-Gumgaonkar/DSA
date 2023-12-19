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
        int num = i + 1;
        for (int j = 0; j < i + 1; j++)
        {
            cout << num;
            num++;
        }

        num = i + 1;
        for (int j = 0; j < i; j++)
        {
            cout << num;
            num++;
        }
        cout << endl;
    }

    return 0;
}