#include<iostream>
#include<cmath>


using namespace std;



void printBits1(int s)
{
	int bitlength = sizeof(s) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned int bit = s;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}

void printBits2(long s)
{
	int bitlength = sizeof(s) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned long bit = s;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}

void printBits3(long long s)
{
	int bitlength = sizeof(s) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned long long bit = s;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}

void printBits4(float s)
{
	int bitlength = sizeof(s) * 8;
	int newS = trunc(s);
	unsigned int bit;
	for (int i = 0; i < bitlength; ++i)
	{
		bit = newS;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
	cout << '.';
	float decimal = s - (float)trunc(s);
	for (int i = 0; i < 6; ++i)
	{
		if (decimal < 1 / pow(2, i + 1))
		{
			cout << '0';
		}
		else
		{
			cout << '1';
			decimal -= 1 / pow(2, i + 1);
		}
	}
}


void printBits5(double  s)
{
	int bitlength = sizeof(s) * 8;
	long long newS = (long long)s;
	unsigned long long bit;
	for (int i = 0; i < bitlength; ++i)
	{
		bit = newS;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
	cout << '.';
	double decimal = s - (double)trunc(s);
	for (int i = 0; i < 12; ++i)
	{
		if (decimal < 1 / pow(2, i + 1))
		{
			cout << '0';
		}
		else
		{
			cout << '1';
			decimal -= 1 / pow(2, i + 1);
		}
	}
}


void printBits6(long double  s)
{
	int bitlength = sizeof(s) * 8;
	long long newS = (long long)s;
	unsigned long long bit;
	for (int i = 0; i < bitlength; ++i)
	{
		bit = newS;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
	cout << '.';
	long double decimal = s - (long double)trunc(s);
	for (int i = 0; i < 12; ++i)
	{
		if (decimal < 1 / pow(2, i + 1))
		{
			cout << '0';
		}
		else
		{
			cout << '1';
			decimal -= 1 / pow(2, i + 1);
		}
	}
}

int main()
{
	float s;
	cin >> s;
	cout << "INT  :" << "  ";
	printBits1(s);
	cout << endl;

	cout << "LONG  :" << "  ";
	printBits2(s);
	cout << endl;

	cout << "LONG LONG  :" << "  ";
	printBits3(s);
	cout << endl;

	cout << "FLOAT  :" << "  ";
	printBits4(s);
	cout << endl;

	cout << "DOUBLE  :" << "  ";
	printBits5(s);
	cout << endl;

	cout << "LONG DOUBLE  :" << "  ";
	printBits6(s);
	cout << endl;


	return 0;
}