#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    int arg;
    cout << "Enter the value of arg: ";
    cin >> arg;
    char a[n][n];
    int lineCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = ' ';
        }
    }
    for (int i = 0; i < n; i++)
    {
        if((i%(arg+1))==0)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = '*';
            }
            lineCount++;
        }
        else
        {
            for (int k = 0; k < arg; k++)
            {
                if (lineCount % 2 != 0)
                    a[i][n - 1] = '*';
                else
                    a[i][0] = '*';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}