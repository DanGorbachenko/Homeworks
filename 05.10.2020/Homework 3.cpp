#include<iostream>
#include <cstdlib>
#include<clocale>
#include<ctime>

using namespace std;

void printMenu()
{
	cout << "МЕНЮ" << endl;
	cout << "0 - Выход из программы" << endl;
	cout << "1 - Ввести несколько элемнетов с клавиатуры" << endl;
	cout << "2 - Добавить в массив n случайных чисел в промежутке от a до b(n, a, b вводится с клавиатуры)" << endl;
	cout << "3 - Вывести массив на экран" << endl;
	cout << "4 - Поиск индекса элемента" << endl;
	cout << "5 - Добавление массив к массиву" << endl;
	cout << "6 - Объединение массивов" << endl;
	cout << "7 - Вставка элемента в массив" << endl;
	cout << "8 - Удаление нескольких подряд идущих элементов массива" << endl;
	cout << "9 - Поиск подпоследовательности" << endl;
}

/// <summary>
/// Инициализация массива
/// </summary>
/// <param name="capacity"> вместительность массива </param>
/// <returns> указатель на начало массива</returns>
int* initArray(int capacity = 10)
{
	int* result = new int[capacity + 2]{ 0 };
	*(result + 1) = capacity;
	result += 2;
	return result;
	//return (new int[capacity + 2]{ 0, capacity }) + 2;
}

/// <summary>
/// Освобождение памяти из-под массива
/// </summary>
/// <param name="arr">Указатель</param>
void deleteArray(int* arr)
{
	/*
	arr -= 2;
	delete[] arr;
	*/
	delete[](arr - 2);
}

void expandArray(int*& arr)
{
	int* temp = initArray(2 * (*(arr - 1)));
	for (int i = 0; i < *(arr - 1); ++i)
	{
		*(temp + i) = *(arr + i);
	}
	*(temp - 2) = *(arr - 2);
	deleteArray(arr);
	arr = temp;
}

void addElement(int*& arr, int element)
{
	if (*(arr - 2) == *(arr - 1))
	{
		expandArray(arr);
	}
	*(arr + *(arr - 2)) = element;
	++(*(arr - 2));

}

void addRandomElements(int*& arr, int n, int min, int max)
{
	for (int i = 0; i < n; ++i)
	{
		addElement(arr, rand() % (max - min + 1) + min);
	}
}

void printArray(int* arr)
{
	cout << "[" << *(arr - 2) << "/" << *(arr - 1) << "] {";
	for (int i = 0; i < *(arr - 2); ++i)
	{
		cout << *(arr + i) << (i == *(arr - 2) - 1 ? "}\n" : ", ");
	}
}

/// <summary>
/// Функция поиска первого вхождения элемента в массиве.
/// </summary>
/// <param name="arr">Массив с элементами</param>
/// <param name="element">Искомый элемент</param>
/// <param name="start">Место начала поиска</param>
/// <returns>индекс первого найденного элемента или -1, если элемент не найден</returns>
int search(int* arr, int element, int start = 0)
{
  for(int i = 0; i < *(arr - 2); i++)
  {
    if(*(arr + i) == element)
    {
      return i;
    }
  }
  return -3;
}

/// <summary>
/// Добавление массива элементов.
/// </summary>
/// <param name="arr">Массив, к которому добавляются элементы, расширяется только если не хватило места для элементов из добавляемого массива</param>
/// <param name="addedArr">Массив с добавляемыми элементами</param>
void add(int*& arr, int* addedArr)
{
  for(int i = 0; i < *(addedArr-2); i++)
  {
    addElement(arr, *(addedArr + i));
  }
}

void getNumbers(int n, int*& arr)
{
  int* a = initArray(n);
  *(a - 2) = n;
  *(a - 1) = n;
  for(int i = 0; i < n; i++)
  {
    cout << "Введите " << i + 1 << "-й элемент" << endl;
    cin >> *(a + i);
  }
  add(arr, a);
}

/// <summary>
/// Объединение двух массивов в один.
/// {a1, a2, a3, a4, a5} {b1, b2, b3, b4, b5, b6, b7, b8}
/// </summary>
/// <param name="a">Массив, элементы которого должны стоять на четных местах в результирующем массиве</param>
/// <param name="b">Массив, элементы которого должны стоять на нечетных местах в результирующем массиве</param>
/// <returns>
/// result[-1] = a[-2] + b[-2]
/// {a1, b1, a2, b2, a3, b3, a4, b4, a5, b5, b6, b7, b8}
///</returns>
int* unify(int* a, int* b)
{
  int* result = new int[*(a - 2) + *(b - 2) + 2];
  *result = *(a - 2) + *(b - 2);
  *(result + 1) = *result;
  result += 2;
  int minCapacity = *(a - 2) < *(b - 2) ? *(a - 2) : *(b - 2);
  for(int i = 0; i < minCapacity; i++)
  {
    *(result + 2*i) = *(a + i);
    *(result + 2*i + 1) = *(b + i);
  }
  if(*(a - 2) > *(b - 2))
  {
    for(int i = minCapacity; i < *(a - 2); i++)
    {
      *(result + minCapacity + i) = *(a + i);
    }
  }
  else
  {
    for(int i = minCapacity; i < *(b - 2); i++)
    {
      *(result + minCapacity + i) = *(b + i);
    }
  }
  return result;
}

/// <summary>
/// Извлечение элемента из массива. Все элементы, стоящие после него, должны быть сдвинуты на 1 влево.
/// </summary>
/// <param name="a">Массив с данными</param>
/// <param name="index">Индекс извлекаемого элемента</param>
/// <returns>элемент, стоявший под индексом index, если index был некорректен - вернуть -1</returns>
int extract(int* a, int index)
{
  if(index > *(a - 2))
  {
    return 1;
  }
  else
  {
    for(int i = index; i < *(a - 2) - 1; i++)
    {
      *(a + i) = *(a + i + 1);
    }
    *(a - 2) -= 1;
    *(a + *(a - 2)) = NULL;
    return 0;
  }
}

/// <summary>
/// Вставка элемента в массив. У вставляемого элемента в итоге должен быть индекс index, все последующие элементы сдвигаются на 1 вправо.
/// </summary>
/// <param name="a">Модифицируемый массив</param>
/// <param name="index">Индекс вставленного элемента</param>
/// <param name="element">Значение элемента</param>
/// <returns>Возвращается 0, если все хорошо и индекс был корректен, 1 - если индес был некорректен</returns>
int insert(int*& a, int index, int element)
{
  if(index > *(a - 2))
  {
    return 1;
  }
  else
  {
    addElement(a, element);
    for(int i = *(a - 2) - 1; i >= index + 1; i--)
    {
      *(a + i) = *(a + i) ^ *(a + i - 1);
      *(a + i - 1) = *(a + i) ^ *(a + i - 1);
      *(a + i) = *(a + i) ^ *(a + i - 1);
    }
    return 0;
  }
}

/// <summary>
/// Удалить последовательность элементов из массива
/// </summary>
/// <param name="a">Модифицируемый массив</param>
/// <param name="startIndex">Начало удаляемого куска</param>
/// <param name="count">Количество удаялемых элементов</param>
/// <returns>0, если все прошло хорошо, 1, если входные данные были некорректными</returns>
int deleteGroup(int* a, int startIndex, int count = 1)
{
  if(startIndex > *(a - 2) || count > *(a - 2) - startIndex)
  {
    return 1;
  }
  else
  {
    for(int i = 1; i <= count; i++)
    {
      extract(a, startIndex);
    }
    return 0;
  }
}

/// <summary>
/// Поиск подпоследовательности в массиве
/// </summary>
/// <param name="a">Массив, в котором ищем подпоследовательность</param>
/// <param name="b">Искомая подпоследовательность</param>
/// <returns>Индекс начала подпоследовательности или -1, если таковой нет</returns>
int subSequence(int* a, int* b)
{

}

int getQuantityNumbers()
{
  int quantity;
  cout << "Введите количество элементов" << endl;
  cin >> quantity;
  return quantity;
}

int getMinNumber()
{
  int minNumber;
  cout << "Введите минимальное число" << endl;
  cin >> minNumber;
  return minNumber;
}

int getMaxNumber()
{
  int maxNumber;
  cout << "Введите максимальное число" << endl;
  cin >> maxNumber;
  return maxNumber;
}

int getElement()
{
  int element;
  cout << "Введите число" << endl;
  cin >> element;
  return element;
}

int getIndex()
{
  int index;
  cout << "Введите индекс" << endl;
  cin >> index;
  return index;
}

void processChoice(int*& arr1, int*& arr2, int choice)
{
  int flag;
	switch (choice)
	{
  case 0:
    cout << "Завершение работы программы" << endl;
    break;
	case 1:
    getNumbers(getQuantityNumbers(), arr1);
		break;
	case 2:
    int n, min, max;
    n = getQuantityNumbers();
    min = getMinNumber();
    max = getMaxNumber();
    addRandomElements(arr1, n, min, max);
		break;
  case 3:
    printArray(arr1);
		break;
  case 4:
    cout << search(arr1, getElement()) << endl;
		break;
  case 5:
    add(arr1, arr2);
		break;
  case 6:
    arr1 = unify(arr1, arr2);
		break;
  case 7:
    flag = insert(arr1, getIndex(), getElement());
    if(!flag)
    {
      cout << "Успешно добавлено" << endl;
    }
    else
    {
      cout << "Нельзя добавить элемент с таким индексом" << endl;
    }
		break;
  case 8:
    flag = deleteGroup(arr1, getIndex(), getQuantityNumbers());
    if(!flag)
    {
      cout << "Успешно удалено" << endl;
    }
    else
    {
      cout << "Нельзя удалить группу элементов с таким индексом" << endl;
    }
		break;
  default:
    cout << "Неправильная команда! Попробуйте еще раз" << endl;
    break;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int* a = initArray(10);
	int* b = initArray(10);

	int choice = 0;
	do
	{
		system("cls");
		printMenu();
		cin >> choice;
		processChoice(a, b, choice);
		system("pause");
	} while (choice != 0);

	deleteArray(a);
	deleteArray(b);
	return EXIT_SUCCESS;
}
