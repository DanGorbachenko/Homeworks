#include<iostream>

using namespace std;

void swap(int& a, int& b);
void fillArray(int* a, int len);
void inputArray(int* a, int len);
void printArray(int* a, int len);
void mixArray(int* a, int len);
bool isSorted(int* a, int len, bool ascending = true);
void bubbleSort(int* a, int len, int& swapCount, int& ifCount);
void insertionSort(int* a, int len, int& swapCount, int& ifCount);
void selectionSort(int* a, int len, int& swapCount, int& ifCount);
void fillAscending(int* a, int len);
void fillDecending(int* a, int len);

int main()
{
	for (int len = 5; len <= 20; len += 5)
	{
		int* a = new int[len];
		fillArray(a, len);
		printArray(a, len);
		
		int bubbleSwap = 0;
		int bubbleIf = 0;
		cout << endl << "Bubble sort for length = " << len << endl;
		for (int i = 1; i <= 998; i++)
		{
			mixArray(a, len);
			//printArray(a, len);
			bubbleSort(a, len, bubbleSwap, bubbleIf);
			//printArray(a, len);
		}
		fillAscending(a, len);
		bubbleSort(a, len, bubbleSwap, bubbleIf);
		fillDecending(a, len);
		bubbleSort(a, len, bubbleSwap, bubbleIf);
		cout << "bubbleSwap: " << bubbleSwap / 1000 << "      bubbleIf: " << bubbleIf / 1000 << endl;

		int insertionSwap = 0;
		int insertionIf = 0;
		cout << endl << "Insertion sort for length = " << len << endl;
		for (int i = 1; i <= 998; i++)
		{
			mixArray(a, len);
			//printArray(a, len);
			insertionSort(a, len, insertionSwap, insertionIf);
			//printArray(a, len);
		}
		fillAscending(a, len);
		insertionSort(a, len, bubbleSwap, bubbleIf);
		fillDecending(a, len);
		insertionSort(a, len, bubbleSwap, bubbleIf);
		cout << "insertionSwap: " << insertionSwap / 1000 << "      insertionIf: " << insertionIf / 1000 << endl;

		int selectionSwap = 0;
		int selectionIf = 0;
		cout << endl << "Selection sort for length = " << len << endl;
		for (int i = 1; i <= 998; i++)
		{
			mixArray(a, len);
			//printArray(a, len);
			selectionSort(a, len, selectionSwap, selectionIf);
			//printArray(a, len);
		}
		fillAscending(a, len);
		selectionSort(a, len, bubbleSwap, bubbleIf);
		fillDecending(a, len);
		selectionSort(a, len, bubbleSwap, bubbleIf);
		cout << "selectionSwap: " << selectionSwap / 1000 << "      selectionIf: " << selectionIf / 1000 << endl << endl << endl;

		delete[] a;
	}

	return 0;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void fillArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 90 + 10;
	}
}

void inputArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cin >> a[i];
	}
}

void printArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void mixArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		swap(a[i], a[rand() % len]);
	}
}

bool isSorted(int* a, int len, bool ascending)
{
	for (int i = 0; i < len - 1; ++i)
	{
		//1 2 3 4 5 3
		if (a[i] > a[i + 1] == ascending)
		{
			return false;
		}
	}
	return true;
}

void bubbleSort(int* a, int len, int& swapCount, int& ifCount)
{
	//cout << endl;
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			ifCount++;
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				swapCount++;
				//printArray(a, len);
			}
		}
	}
	//cout << endl;
}

void insertionSort(int* a, int len, int& swapCount, int& ifCount)
{
	for (int i = 1; i < len; ++i)
	{
		int t = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > t)
		{
			ifCount++;
			swapCount++;
			a[j] = a[j - 1];
			--j;
		}
		a[j] = t;
		//printArray(a, len);
	}
}

void selectionSort(int* a, int len, int& swapCount, int& ifCount)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int index = i;
		for (int j = i + 1; j < len; ++j)
		{
			ifCount++;
			if (a[j] < a[index])
			{
				index = j;
			}
		}
		swapCount++;
		swap(a[i], a[index]);
		//printArray(a, len);
	}
}

void fillAscending(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = i;
	}
}

void fillDecending(int* a, int len)
{
	for (int i = len - 1; i >= 0; --i)
	{
		a[i] = i;
	}
}