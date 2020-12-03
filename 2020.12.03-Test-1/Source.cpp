#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

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
    double error = pow(0.1, n);
    double summ = x;
    int p = 1;
    while (abs(summ) > error)
    {
        p += 2;
        summ = pow(x, p) / factor(p);
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
    cout << "Calculated value is " << setprecision(n) << sh(x, n) << endl;
    cout << "True value is " << setprecision(n) << sinh(x) << endl;
    return 0;
}
