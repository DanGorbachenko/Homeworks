#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void printMenu()
{
cout << "0 - exit" << endl << "1 - add a number to massive" << endl << "2 - output massive" << endl;
cout << "3 - find index of the biggest element" << endl << "4 - find the smallest element" << endl;
cout << "5 - calculate sum of all elements" << endl << "6 - output reversed massive" << endl;
}

void fillArray(int* arr, int size)
{
srand(time(NULL));
for (int i = 0; i < size; i++)
arr[i] = 10 + rand() % 90;
}

void addNumber(int number, int* &arr, int size)
{
int* temp = new int[size + 1];
for (int i = 0; i < size; i++)
temp[i] = arr[i];
temp[size] = number;
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

int findMaxIndex(int* arr, int size)
{
int maxI = 0, maxElement = arr[0];
for (int i = 1; i < size; i++)
if (arr[i] > maxElement)
{
maxElement = arr[i];
maxI = i;
}
return maxI + 1;
}

int findMinElement(int* arr, int size)
{
int minElement = arr[0];
for (int i = 1; i < size; i++)
if (arr[i] < minElement)
minElement = arr[i];
return minElement;
}

int calculateSum(int* arr, int size)
{
int summ = 0;
for (int i = 0; i < size; i++)
summ += arr[i];
return summ;
}

void reverseMassive(int* arr, int size)
{
cout << "Current reversed array is {";
for (int i = size - 1; i >= 0; i--)
cout << arr[i] << (i == 0 ? "}" : ", ");
}

void processChoice(int*& arr, int &N, int choice)
{
  int number;
	switch (choice)
	{
  case 0:
    cout << "Завершение работы программы" << endl;
    break;
  case 1:
    cout << "Enter a number to add to massive ";
    cin >> number;
    addNumber(number, arr, N++);
    break;
  case 2:
    printArray(arr, N);
    break;
  case 3:
    cout << "Index of maximum element is " << findMaxIndex(arr, N);
    break;
  case 4:
    cout << "Minimum element is " << findMinElement(arr, N);
    break;
  case 5:
    cout << "Sum of all elements is " << calculateSum(arr, N);
    break;
  case 6:
    reverseMassive(arr, N);
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
int choice = 2, number;
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