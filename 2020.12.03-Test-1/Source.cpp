#include<iostream>
#include<cmath>

using namespace std;

double power(double x, int n)
{
    double pow = x;
    for (int i = 2; i <= n; i++)
    {
        pow *= x;
    }
    return pow;
}

int factor(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

double sh(double x, int n)
{
    double result = x;
    double error = power(0.1, n);
    double summ = x;
    int p = 1;
    while (abs(summ) > error)
    {
        p += 2;
        summ = power(x, p) / factor(p);
        result += summ;
    }
    return result;
}

int main()
{
    double x;
    int n;
    cin >> x;
    cin >> n;
    printf("Calculated value is %.10lf\n", sh(x, n));
    printf("C++ value is %.10lf\n", sinh(x));
    return 0;
}
