#include<iostream>
#include<string>
#include<fstream>

using namespace std;

bool isDigit(char c);                        
bool isSign(char c);                  
bool isNatural(string str, int& index);
bool isExponent(string str, int& index);
bool isMantissa(string str, int& index);
bool isReal(string str, int& index);

int main()
{
	string real;
	ifstream fin("in.txt");
	while (!fin.eof())
	{
		fin >> real;
	}
	int index = 0;
	
	if (isReal(real, index)) 
	{
		cout << "=)";
	}
	else
	{
		cout << "=(";
	}
	fin.close();
	return 0;
}

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool isSign(char c)
{
	return c == '+' || c == '-';
	
}

bool isNatural(string str, int& index)
{
	if (isDigit(str[index]))
	{
		while (isDigit(str[++index]));
		return true;
	}
	return false;
}

bool isExponent(string str, int& index) 
{
	if (str[index] == 'E' || str[index] == 'e')
	{
		if (isSign(str[++index]) || isDigit(str[index]))
		{
			if (isSign(str[index]))
			{
				index++;
			}
			while (isNatural(str, index));
			return true;
		}
		return false;
	}
	return false;
}

bool isMantissa(string str, int& index) 
{
	if (isSign(str[index]) || isDigit(str[index]))
	{
		if (isSign(str[index]))
		{
			index++;
		}
		while (isNatural(str, index));
		if (str[index] == '.' && isDigit(str[++index]))
		{
			while (isNatural(str, index));
			return true;
		}
		return false;
	}
	return false;
}

bool isReal(string str, int& index)
{
		while (isMantissa(str, index));
		while (isExponent(str, index));
		return (str[index] == '\0');
}
