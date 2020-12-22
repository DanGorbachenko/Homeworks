#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int** data = new int*[n];
    for (int i = 0; i < n; ++i)
    {
        data[i] = new int[n] {0};
    }
    int delta = 0;
    int el = 0;
    while (true)
    {
        for (int i = delta; i < n - delta; i++)
        {
            data[delta][i] = ++el;
        }
        delta++;
        for (int i = delta; i < n - delta + 1; i++)
        {
            data[i][n - delta] = ++el;
        }
        if (el >= n * n)
        {
            break;
        }
        for (int i = n - delta - 1; i >= delta - 1; i--)
        {
            data[n - delta][i] = ++el;
        }
        if (el >= n * n)
        {
            break;
        }
        for (int i = n - delta - 1; i >= delta; i--)
        {
            data[i][delta - 1] = ++el;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%4d ", data[i][j]);
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++i)
    {
        delete[] data[i];
    }
    delete[] data;

    return 0;
}


