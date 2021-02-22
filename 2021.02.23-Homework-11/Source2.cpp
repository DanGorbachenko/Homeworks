#include<iostream>

using namespace std;

double average(int n, ...)
{
	double result = 0;
	for (int i = 0; i < n; ++i)
	{
		int* ptr = &n + 1 + i;
		result += *ptr;
	}
	return result / n;
}

int main()
{
	cout << average(6, 1, 2, 3, 4, 5, 6) << endl;
	cout << average(3, 5, 7, 9) << endl;
	return 0;
}