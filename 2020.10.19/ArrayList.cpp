#include <iostream>
#include <ctime>
#include "ArrayList.h"

ArrayList::~ArrayList()
{
  delete[] data;
}

int ArrayList::numLength(int number)
{
  int result = 1;
	while (number > 9)
	{
		number /= 10;
		result++;
	}
	return result;
}

void ArrayList::expand(int addition)
{
  capacity += addition;
}

void ArrayList::addSymbolToStr(int &index, char symbol)
{
  str[index] = symbol;
	++index;
}

void ArrayList::addNumberToStr(int &index, int number)
{
  if(number < 0)
  {
    *(str + index) = '-';
    number = -number;
    index++;
  }
  int length = numLength(number);
	for (int i = 0; i < length; ++i)
	{
		int digit = number % 10;
		*(str + index + length - 1 - i) = '0' + digit;
		number /= 10;
	}
	index += length;
}

bool ArrayList::add(int element)
{
  if(capacity == count)
  {
    expand(1);
  }
  count++;
  int* temp = new int[capacity];
  for (int i = 0; i < count - 1; i++)
    *(temp + i) = *(data + i);
  *(temp + count - 1) = element;
  delete[] data;
  data = temp;
  //std::cout << length() << "In add" << std::endl;
  return true;
}

bool ArrayList::add(int index, int element)
{
  if(index < 0 || index >= capacity)
    return false;
  else
  {
    if(capacity == count)
    {
      expand(1);
    }
    count++;
    int* temp = new int[capacity];
    for (int i = 0; i < index; i++)
      *(temp + i) = *(data + i);
    *(temp + index) = element;
    for (int i = index + 1; i < count; i++)
      *(temp + i) = *(data + i - 1);
    delete[] data;
    data = temp;
    return true; 
  }
}

bool ArrayList::addAll(ArrayList& list)
{
  if(capacity < count + list.count)
  {
    expand(list.count);
  }
  count += list.count;
  int* temp = new int[capacity];
  for (int i = 0; i < count - list.count; i++)
    *(temp + i) = *(data + i);
  for (int i = count - list.count; i < count; i++)
    *(temp + i) = list.data[i - count + list.count];
  delete[] data;
  data = temp;
  return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
  if(index < 0 || index >= capacity)
    return false;
  else
  {
    if(capacity < count + list.count)
    {
      expand(list.count);
    }
    count += list.count;
    int* temp = new int[capacity];
    for (int i = 0; i < index; i++)
      *(temp + i) = *(data + i);
    for (int i = index; i < index + list.count; i++)
      *(temp + i) = list.data[i - index];
    for (int i = index + list.count; i < count; i++)
      *(temp + i) = *(data + i - list.count);
    delete[] data;
    data = temp;
    return true;
  }
}

void ArrayList::clear()
{
  count = 0;
  delete[] data;
  data = new int[capacity];
}

bool ArrayList::contains(int element)
{
  for(int i = 0; i < count; i++)
  {
    if(element == *(data + i))
      return true;
  }
  return false;
}

int ArrayList::get(int index)
{
  if(index < 0 || index >= count)
    return -1;
  else
    return *(data + index);
}

bool ArrayList::set(int index, int element)
{
  if(index < 0 || index >= capacity)
    return false;
  else
  {
    *(data + index) = element;
    return true;
  }
}

int ArrayList::indexOf(int element)
{
  for(int i = 0; i < count; i++)
  {
    if(element == *(data + i))
      return i;
  }
  return -1;
}

bool ArrayList::isEmpty()
{
  return count == 0 ? true : false;
}

char* ArrayList::toString()
{
  if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
  int lenstr = 6 + numLength(capacity) + numLength(count);
  for(int i = 0; i < count; i++)
  {
    lenstr += (numLength(*(data + i)) + 2);
  }
  lenstr -= 2;
  str = new char[lenstr];
  int index = 0;
  addSymbolToStr(index, '[');
  addNumberToStr(index, count);
  addSymbolToStr(index, '/');
  addNumberToStr(index, capacity);
  addSymbolToStr(index, ']');
  addSymbolToStr(index, ' ');
  addSymbolToStr(index, '{');
  for(int i = 0; i < count - 1; i++)
  {
    addNumberToStr(index, *(data + i));
    addSymbolToStr(index, ',');
    addSymbolToStr(index, ' ');
  }
  addNumberToStr(index, *(data + count - 1));
  addSymbolToStr(index, '}');
  return str;
}

bool ArrayList::remove(int index)
{
  if(index < 0 || index >= count)
    return false;
  else
  {
    count--;
    int* temp = new int[capacity];
    for (int i = 0; i < index; i++)
      *(temp + i) = *(data + i);
    for (int i = index; i < count; i++)
      *(temp + i) = *(data + i + 1);
    delete[] data;
    data = temp;
    return true; 
  }
}

bool ArrayList::swap(int index1, int index2)
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

int ArrayList::length()
{
  return count;
}
