#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	char c;
	fstream fbin;
	fbin.open("in.txt", ios::binary | ios::in);
	if (!fbin)
	{
		cout << "File not found!" << endl;
	}
	cout << "Before moderating:" << endl;
	while (fbin.read((char*)&c, sizeof(char)))
	{
		cout << c;
	}
	fbin.close();

	fbin.open("in.txt", ios::binary | ios::in | ios::out);
	cout << endl << "After moderating:" << endl;
	while (fbin.read((char*)&c, sizeof(char)))
	{
		c = toupper(c);
		if ((c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U') || (c == 'Y'))
		{
			fbin.seekg(-(int)sizeof(char), ios::cur);
			c = '#';
			fbin.write((char*)&c, sizeof(char));
			fbin.seekg(fbin.tellg(), ios::beg);
		}
	}
	fbin.close();

	fbin.open("in.txt", ios::binary | ios::in);
	while (fbin.read((char*)&c, sizeof(char)))
	{
		cout << c;
	}
	fbin.close();

	return 0;
}
