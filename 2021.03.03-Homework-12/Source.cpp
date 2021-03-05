#include<iostream>
#include<cmath>
#include<string>

using namespace std;

template<class T1, class T2>
T1 sum(T1 a, T2 b)
{
	return a + b;
}

template<class T1, class T2>
T1 diff(T1 a, T2 b)
{
	return a - b;
}
template<class T1, class T2>
T1 mult(T1 a, T2 b)
{
	return a * b;
}

template<class T1, class T2>
T1 div(T1 a, T2 b)
{
	return a / b;
}

template<class T1, class T2>
T1 ost(T1 a, T2 b)
{
	return a - b * (trunc(a / b));
}

int operationIndex(char operation)
{
	switch (operation)
	{
	case '+':
		return 0;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 3;
	case '%':
		return 4;
	default:
		return -1;
	}
}

template<class T1, class T2>
T1 calc(T1 a, T2 b, char operation)
{
	T1(*operations[5])(T1, T2) { sum, diff, mult, div, ost };
	return operations[operationIndex(operation)](a, b);
}

template<class T1, class T2>
void resolveOpNumber(T1 operand1, T2 operand2, char op)
{
	cout << operand1 << " " << op << " " << operand2 << " = " << calc(operand1, operand2, op) << endl;
}

int main(int argc, char* argv[])
{
	if (argc != 7)
	{
		cout << "Takes 6 positional arguments but " << argc - 1 << " were given" << endl;
	}
	else
	{
		double operand1, operand2, op;
		for (int i = 1; i <= 5; i += 2)
		{
			if (argv[i] == "—operand1\0")
			{
				operand1 = stod(argv[i + 1]);
			}
			else if (argv[i] == "-operand2\0")
			{
				operand2 = stod(argv[i + 1]);
			}
			else if (argv[i] == "—operator\0")
			{
				op = stod(argv[i + 1]);
			}
			else
			{
				cout << "Wrong keys!";
				return -1;
			}
		}
		resolveOpNumber(operand1, operand2, op);
	}
	return 0;
}
