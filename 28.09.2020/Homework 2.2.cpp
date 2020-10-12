#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void printMenu()
{
cout << "0 - exit" << endl << "1 - add random numbers to massive" << endl << "2 - reverse massive" << endl;
cout << "3 - change pairs" << endl << "4 - movement right on 1" << endl;
cout << "5 - reverse two parts" << endl;
}

void fillArray(int* arr, int size)
{
srand(time(NULL));
for (int i = 0; i < size; i++)
arr[i] = 10 + rand() % 90;
}

void addRandomNumbers(int n, int a, int b, int*& arr, int size)
{
srand(time(NULL));
int* temp = new int[size + n];
for (int i = 0; i < size; i++)
temp[i] = arr[i];
for (int i = size; i < size + n; i++)
temp[i] = a + rand() % (b - a + 1);
delete[] arr;
arr = temp;
}

void printArray(int* arr, int size)
{
cout << "Current array is {";
for (int i = 0; i < size; i++)
cout << arr[i] << (i == size - 1 ? "}" : ", ");
getchar();
getchar();
}

void reverseMassive(int* arr, int size, int start = 0)
{
for (int i = start; i < start + (size - start) / 2; i++)
{
arr[i] = arr[i] + arr[start + size - i - 1];
arr[start + size - i - 1] = arr[i] - arr[start + size - i - 1];
arr[i] = arr[i] - arr[start + size - i - 1];
}
}

void changePairs(int* arr, int size)
{
for (int i = 1; i < size - 1; i += 2)
{
arr[i] = arr[i] ^ arr[i - 1];
arr[i - 1] = arr[i] ^ arr[i - 1];
arr[i] = arr[i] ^ arr[i + 1];
}
}

void movementRight(int* arr, int size)
{
int tmp = arr[size - 1];
for (int i = size - 1; i > 0; i--)
arr[i] = arr[i - 1];
arr[0] = tmp;
}

void reverseParts(int n, int* arr, int size)
{
reverseMassive(arr, n);
reverseMassive(arr, size, n);
}

void processChoice(int*& arr, int &N, int choice)
{
  int n, a, b;
	switch (choice)
	{
  case 0:
    cout << "Завершение работы программы" << endl;
    break;
  case 1:
    cout << "Enter quantity of numbers to add to massive ";
    cin >> n;
    cout << endl << "Enter bottom boundary of numbers ";
    cin >> a;
    cout << endl << "Enter top boundary of numbers ";
    cin >> b;
    addRandomNumbers(n, a, b, arr, N);
    N += n;
    printArray(arr, N); 
    break;
  case 2:
    reverseMassive(arr, N);
    printArray(arr, N);
    break;
  case 3:
    changePairs(arr, N);
    printArray(arr, N);
    break;
  case 4:
    movementRight(arr, N);
    printArray(arr, N);
    break;
  case 5:
    cout << "Enter index to split parts of massive ";
    cin >> n;
    reverseParts(n, arr, N);
    printArray(arr, N);
    break;
  default:
    cout << "Wrong command! Try another variant" << endl;
    break;
  }
}

int main()
{
int N = 4;
int* arr = new int[N];
int choice = 2, n, a, b;
fillArray(arr, N);
do
	{
	  system("cls");
	  printMenu();
	  cin >> choice;
	  processChoice(arr, N, choice);
	  system("pause");
	} while (choice != 0);
delete[] arr;
return 0;
}