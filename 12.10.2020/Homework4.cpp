#pragma once
#include<iostream>

using namespace std;

struct ArrayList {
	int count;
	int capacity;
	int* data;
		
	//конструкторы
	ArrayList()
  {
    capacity = 10;
    count = 0;
    data = new int[10];
  }

	ArrayList(int cap)
  {
    capacity = cap;
    count = 0;
    data = new int[cap];
  }
		
	//деструктор
	~ArrayList()
  {
    delete[] data;
  }

	//методы					   
	/// <summary>
	/// добавляет элемент в конец
	/// </summary>
	/// <param name="element">добавляемый элемент</param>
	/// <returns></returns>
	bool add(int element)
  {
    if(capacity == count)
    {
      capacity++;
    }
    count++;
    int* temp = new int[capacity];
    for (int i = 0; i < count - 1; i++)
      temp[i] = data[i];
    temp[count - 1] = element;
    delete[] data;
    data = temp;
    return true;
  }

	/// <summary>
	/// добавляет элемент в позицию index, все последующие элементы сдвигаются на 1 вправо
	/// </summary>
	/// <param name="index">индекс вставляемого элемента</param>
	/// <param name="element">вставляемый элемент</param>
	/// <returns>true, если все прошло хорошо, false - если возникли проблемы</returns>
	bool add(int index, int element)
  {
    if(index < 0 || index >= capacity)
      return false;
    else
    {
      if(capacity == count)
      {
        capacity++;
      }
      count++;
      int* temp = new int[capacity];
      for (int i = 0; i < index; i++)
        temp[i] = data[i];
      temp[index] = element;
      for (int i = index + 1; i < count; i++)
        temp[i] = data[i - 1];
      delete[] data;
      data = temp;
      return true; 
    }
  }
	
	/// <summary>
	/// добавляет все элементы из списка list в конец
	/// </summary>
	/// <param name="list">добавляемый список</param>
	/// <returns>true, если получилось добавить, false - если не получилось</returns>
	bool addAll(ArrayList& list)
  {
    if(capacity < count + list.count)
    {
      capacity = count + list.count;
    }
    count += list.count;
    int* temp = new int[capacity];
    for (int i = 0; i < count - list.count; i++)
      temp[i] = data[i];
    for (int i = count - list.count; i < count; i++)
      temp[i] = list.data[i - count + list.count];
    delete[] data;
    data = temp;
    return true;
  }

	
	/// <summary>
	/// добавляет все элементы из списка list, начиная с позиции index.
	/// все последующие элементы сдвигаются вправо
	/// </summary>
	/// <param name="list">добавляемый список</param>
	/// <returns>true, если получилось добавить, false - если не получилось</returns>
	bool addAll(int index, ArrayList& list)
  {
    if(index < 0 || index >= capacity)
      return false;
    else
    {
      if(capacity < count + list.count)
      {
        capacity = count + list.count;
      }
      count += list.count;
      int* temp = new int[capacity];
      for (int i = 0; i < index; i++)
        temp[i] = data[i];
      for (int i = index; i < index + list.count; i++)
        temp[i] = list.data[i - index];
      for (int i = index + list.count; i < count; i++)
        temp[i] = data[i - list.count];
      delete[] data;
      data = temp;
      return true;
    }
  }

	/// <summary>
	/// удалить все элементы из списка
	/// </summary>
	void clear()
  {
    count = 0;
    delete[] data;
    data = new int[capacity];
  }
	
	/// <summary>
	/// содержится ли элемент в списке
	/// </summary>
	/// <param name="element">искомый элемент</param>
	/// <returns>true - содержится, false - не содержится</returns>
	bool contains(int element)
  {
    for(int i = 0; i < count; i++)
    {
      if(element == *(data + i))
        return true;
    }
    return false;
  }

	/// <summary>
	/// получить элемент по индексу
	/// </summary>
	/// <param name="index">индекс запрашиваемого элемента</param>
	/// <returns>data[index], если индекс корректен, -1 - если индекс некорректен</returns>
	int get(int index)
  {
    if(index < 0 || index >= count)
      return -1;
    else
      return *(data + index);
  }

	/// <summary>
	/// поиск элемента в списке
	/// </summary>
	/// <param name="element">искомый элемент</param>
	/// <returns>индекс элемента, если он найден, -1 - если не найден</returns>
	int indexOf(int element)
  {
    for(int i = 0; i < count; i++)
    {
      if(element == *(data + i))
        return i;
    }
    return -1;
  }
	
	/// <summary>
	/// проверка списка на пустоту
	/// </summary>
	/// <returns>true - если список пуст, false - если есть хотя бы 1 элемент</returns>
	bool isEmpty()
  {
    return count == 0 ? true : false;
  }

	/// <summary>
	/// Вывод списка в формате [count/capacity] {el1, el2, el3, ...}
	/// </summary>
	void print()
  {
    printf("[%d/%d] {", count, capacity);
    if (count)
    {
      for(int i = 0; i < count - 1; i++)
      {
        printf("%d ", *(data + i));
      }
      printf("%d}\n", *(data + count - 1));
    }
    else
    {
      printf("Array is empty}\n");
    }
  }

	/// <summary>
	/// удаление элемента из списка
	/// </summary>
	/// <param name="index">индекс удаляемого элемента</param>
	/// <returns>true - все прошло хорошо, false - возникли проблемы</returns>
	bool remove(int index)
  {
    if(index < 0 || index >= count)
      return false;
    else
    {
      count--;
      int* temp = new int[capacity];
      for (int i = 0; i < index; i++)
        temp[i] = data[i];
      for (int i = index; i < count; i++)
        temp[i] = data[i + 1];
      delete[] data;
      data = temp;
      return true; 
    }
  }

	/// <summary>
	/// поменять местами элементы
	/// </summary>
	/// <param name="index1">индекс первого элемента</param>
	/// <param name="index2">индекс второго элемента</param>
	/// <returns>true - все прошло хорошо, false - возникли проблемы</returns>
	bool swap(int index1, int index2)
  {
    if(index1 < 0 || index2 < 0 || index1 >= count || index2 >= count)
    {
      return false;
    }
    else
    {
      *(data + index1) = *(data + index1) ^ *(data + index2);
      *(data + index2) = *(data + index1) ^ *(data + index2);
      *(data + index1) = *(data + index1) ^ *(data + index2);
      return true;
    }
  }

};
