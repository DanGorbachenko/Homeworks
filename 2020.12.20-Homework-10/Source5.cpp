#include<iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int* a = new int[N * N]{ 0 };
    int delta = 0;
    int el = 0;
    while (true)
    {
        for (int i = (N + 1) * delta; i <= N * (delta + 1) - 1 - delta; i++)
        {
            a[i] = ++el;
        }
        delta++;
        for (int i = delta + 1; i <= N - delta + 1; i++)
        {
            a[N * i - delta] = ++el;
        }
        if (el >= N * N)
        {
            break;
        }
        for (int i = N * (N + 1 - delta) - 1 - delta; i >= N * (N - delta) - 1 + delta; i--)
        {
            a[i] = ++el;
        }
        if (el >= N * N)
        {
            break;
        }
        for (int i = (N - delta - 1) * N + delta - 1; i >= delta * N + delta - 1; i-=N)
        {
            a[i] = ++el;
        }
    }

    for (int i = 0; i < N * N; ++i)
    {
        printf("%3d%c", a[i], ((i + 1) % N == 0 ? '\n' : ' '));
    }

    return 0;
}

