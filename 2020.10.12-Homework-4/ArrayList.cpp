#pragma once
#include<iostream>

using namespace std;

struct ArrayList {
	int count;
	int capacity;
	int* data;
		
	
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
		
	
	~ArrayList()
  {
    delete[] data;
  }

	
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

	
	void clear()
  {
    count = 0;
    delete[] data;
    data = new int[capacity];
  }
	
	
	bool contains(int element)
  {
    for(int i = 0; i < count; i++)
    {
      if(element == *(data + i))
        return true;
    }
    return false;
  }

	
	int get(int index)
  {
    if(index < 0 || index >= count)
      return -1;
    else
      return *(data + index);
  }

	
	int indexOf(int element)
  {
    for(int i = 0; i < count; i++)
    {
      if(element == *(data + i))
        return i;
    }
    return -1;
  }
	
	
	bool isEmpty()
  {
    return count == 0 ? true : false;
  }

	
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
