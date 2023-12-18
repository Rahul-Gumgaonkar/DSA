#include <iostream>

using namespace std;

int main()
{
    int row, col;
    cout << "Enter the Number of Row : ";
    cin >> row;
    cout << "Enter the Number of Col : ";
    cin >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}