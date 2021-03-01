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
T1 um(T1 a, T2 b)
{
	return a * b;
}
template<class T1, class T2>
T1 del(T1 a, T2 b)
{
	return a / b;
}
template<class T1, class T2>
T1 ost(T1 a, T2 b)
{
	return a - b * (trunc(a / b));
}
template<class T1, class T2>
void calc(T1 a, T2 b, char symb, T1 (*op)(T1, T2))
{
	cout << a << " " << symb << " " << b << " = " << (T1)op(a, b) << endl;
	//return op(a, b);
}
template<class T1, class T2>
int resolveOpNumber(T1 operand1, T2 operand2, char op)
{
	switch (op)
	{
	case '+':
		calc(operand1, operand2, '+', sum);
		return 0;
		break;
	case '-':
		calc(operand1, operand2, '-', diff);
		return 0;
		break;
	case '*':
		calc(operand1, operand2, '*', um);
		return 0;
		break;
	case '/':
		calc(operand1, operand2, '/', del);
		return 0;
		break;
	case '%':
		calc(operand1, operand2, '%', ost);
		return 0;
		break;
	default:
		cout << "Something going wrong" << endl;
		return 1;
	}
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

