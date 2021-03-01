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
		break;
	case '-':
		return 1;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 3;
		break;
	case '%':
		return 4;
		break;
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
		string key1 = argv[1];
		double operand1 = stod(argv[2]);
		string key2 = argv[3];
		double operand2 = stod(argv[4]);
		string key3 = argv[5];
		char op = *argv[6];
		/*if ((key1 != "—operand1") || (key2 != "—operand2") || (key3 != "—operator"))
		{
			cout << "Wrong keys!" << endl;
		}*/
		if ((key1.compare("—operand1\0")) || (key2.compare("—operand2\0")) || (key3.compare("—operator\0")))
		{
			cout << "Wrong keys!" << endl;
		}
		resolveOpNumber(operand1, operand2, op);
	}
	return 0;
}
