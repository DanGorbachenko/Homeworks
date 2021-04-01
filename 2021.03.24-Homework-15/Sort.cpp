#include <iostream>

using namespace std;

void countingSort(int arr[], int size)
{
	int maxElement = arr[0];
	int minElement = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > maxElement)
		{
			maxElement = arr[i];
		}
		if (arr[i] < minElement)
		{
			minElement = arr[i];
		}
	}
	int *tmp = new int[maxElement - minElement + 1]{0};
	for (int i = 0; i < size; i++)
	{
		tmp[arr[i] - minElement]++;
	}
	int i = 0;
	for (int j = minElement; j <= maxElement; j++)
	{
		while (tmp[j - minElement])
		{
			arr[i++] = j;
			tmp[j - minElement]--;
		}
	}
	delete tmp;
}

void quickSort(int arr[], int left, int right)
{
	int tmp;
	int current = arr[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (arr[i] < current) { i++; }
		while (arr[j] > current) { j--; }
		if (i <= j)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			i++;
			j--;
		}
	}
	if (left < j)
	{
		quickSort(arr, left, j);
	}
	if (right > i)
	{
		quickSort(arr, i, right);
	}
}

void merge(int arr1[], int size1, int arr2[], int size2, int arr3[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (k < size1 + size2)
	{
		if (i == size1)
		{
			arr3[k++] = arr2[j++];
			continue;
		}
		if (j == size2)
		{
			arr3[k++] = arr1[i++];
			continue;
		}
		if (arr1[i] < arr2[j])
		{
			arr3[k++] = arr1[i++];
		}
		else
		{
			arr3[k++] = arr2[j++];
		}
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	const int N = 10;
	int arr1[N];
	int arr2[N];
	int arr3[2 * N];
	for (int i = 0; i < N; i++)
	{
		arr1[i] = -90 + rand() % 190;
		arr2[i] = -90 + rand() % 190;
	}
	cout << "Before sorting for first array:" << endl;
	printArray(arr1, N);
	cout << endl;
	countingSort(arr1, N);
	cout << "After counting sort for first array:" << endl;
	printArray(arr1, N);
	cout << endl << endl;
	cout << "Before sorting for second array:" << endl;
	printArray(arr2, N);
	cout << endl;
	quickSort(arr2, 0, N - 1);
	cout << "After quick sort for second array:" << endl;
	printArray(arr2, N);
	cout << endl << endl;
	cout << "Merging two sorted arrays into one:" << endl;
	merge(arr1, N, arr2, N, arr3);
	printArray(arr3, 2 * N);
	return 0;
}