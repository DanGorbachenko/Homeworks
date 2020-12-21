#include<iostream>

using namespace std;

int main()
{
    int N;
    cin>>N;
    int* a = new int[N * N]{ 0 };
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            a[i * N + j] = i + j + 1;
        }
    }

    for (int i = 0; i < N * N; ++i)
    {
        printf("%2d%c", a[i], ((i + 1) % N == 0 ? '\n' : ' '));
    }
    delete[] a;

    return 0;
}

