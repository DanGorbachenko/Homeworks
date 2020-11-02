#include <iostream>
#include <ctime>
#include "ArrayList.h"

ArrayList::ArrayList(const ArrayList& list)
{
    capacity = list.capacity;
    count = list.count;
    for(int i = 0; i < count; i++)
    {
      data[i] = list.data[i];
    }
}

ArrayList::~ArrayList()
{
    delete[] data;
}

void ArrayList::expand(int addition)
{
    capacity += addition;
}

bool ArrayList::add(int element)
{
    if (capacity == count)
    {
        expand(1);
    }
    count++;
    int* temp = new int[capacity];
    for (int i = 0; i < count - 1; i++)
    {
        *(temp + i) = *(data + i);
    }
    *(temp + count - 1) = element;
    delete[] data;
    data = temp;
    return true;
}

bool ArrayList::add(int index, int element)
{
    if (index < 0 || index >= capacity)
    {
        return false;
    }
    else
    {
        if (capacity == count)
        {
            expand(1);
        }
        count++;
        int* temp = new int[capacity];
        for (int i = 0; i < index; i++)
        {
            *(temp + i) = *(data + i);
        }
        *(temp + index) = element;
        for (int i = index + 1; i < count; i++)
        {
            *(temp + i) = *(data + i - 1);
        }
        delete[] data;
        data = temp;
        return true;
    }
}

bool ArrayList::addAll(ArrayList& list)
{
    if (capacity < count + list.count)
    {
        expand(list.count);
    }
    count += list.count;
    int* temp = new int[capacity];
    for (int i = 0; i < count - list.count; i++)
    {
        *(temp + i) = *(data + i);
    }
    for (int i = count - list.count; i < count; i++)
    {
        *(temp + i) = list.data[i - count + list.count];
    }
    delete[] data;
    data = temp;
    return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
    if (index < 0 || index >= capacity)
    {
        return false;
    }
    else
    {
        if (capacity < count + list.count)
        {
            expand(list.count);
        }
        count += list.count;
        int* temp = new int[capacity];
        for (int i = 0; i < index; i++)
        {
            *(temp + i) = *(data + i);
        }
        for (int i = index; i < index + list.count; i++)
        {
            *(temp + i) = list.data[i - index];
        }
        for (int i = index + list.count; i < count; i++)
        {
            *(temp + i) = *(data + i - list.count);
        }
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
    for (int i = 0; i < count; i++)
    {
        if (element == *(data + i))
        {
          return true;
        }
    }
    return false;
}

int ArrayList::get(int index)
{
    if (index < 0 || index >= count)
    {
        return -1;
    }
    else
    {
        return *(data + index);
    }
}

bool ArrayList::set(int index, int element)
{
    if (index < 0 || index >= capacity)
    {
        return false;
    }
    else
    {
        *(data + index) = element;
        return true;
    }
}

int ArrayList::indexOf(int element)
{
    for (int i = 0; i < count; i++)
    {
        if (element == *(data + i))
        {
            return i;
        }
    }
    return -1;
}

bool ArrayList::isEmpty()
{
    return count == 0 ? true : false;
}

bool ArrayList::remove(int index)
{
    if (index < 0 || index >= count)
    {
        return false;
    }
    else
    {
        count--;
        int* temp = new int[capacity];
        for (int i = 0; i < index; i++)
        {
            *(temp + i) = *(data + i);
        }
        for (int i = index; i < count; i++)
        {
            *(temp + i) = *(data + i + 1);
        }
        delete[] data;
        data = temp;
        return true;
    }
}

bool ArrayList::swap(int index1, int index2)
{
    if (index1 < 0 || index2 < 0 || index1 >= count || index2 >= count)
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

void ArrayList::operator+= (int item)
{
  if (capacity == count)
  {
      expand(1);
  }
  count++;
  int* temp = new int[capacity];
  for (int i = 0; i < count - 1; i++)
  {
      *(temp + i) = *(data + i);
  }
  *(temp + count - 1) = item;
  delete[] data;
  data = temp;
}

void ArrayList::operator-= (int item)
{
  for(int i = count - 1; i >= 0; i--)
  {
    if(data[i] == item)
    {
      remove(i);
      return;
    }
  }
}

ArrayList& ArrayList::operator=(const ArrayList& list)
{
    capacity = list.capacity;
    count = list.count;
    for(int i = 0; i < count; i++)
    {
      data[i] = list.data[i];
    }
    return *this;
}

ArrayList operator+ (const ArrayList& list, int item)
{
  ArrayList result;
  result = list;
  result += item;
  return result;
}

ArrayList operator+ (int item, const ArrayList& list)
{
  ArrayList result;
  result = list;
  result.add(0, item);
  return result;
}

ArrayList operator+ (const ArrayList& list1, const ArrayList& list2)
{
  ArrayList result, temp;
  temp = list1;
  result = list2;
  result.addAll(temp);
  return result;
}

ArrayList operator- (const ArrayList& list, int item)
{
  ArrayList result;
  result = list;
  result -= item;
  return result;
}

ArrayList operator- (int item, const ArrayList& list)
{
  ArrayList result;
  result = list;
  int index = result.indexOf(item);
  result.remove(index);
  return result;
}

std::ostream& operator<<(std::ostream& out, const ArrayList& list)
{
  if(list.count)
  {
    out << "[" << list.count << "/" << list.capacity << "] {";
    for(int i = 0; i < list.count - 1; i++)
    {
      out << *(list.data + i) << ", ";
    }
    out << *(list.data + list.count - 1) << "}";
  }
  else
  {
    out << "[" << list.count << "/" << list.capacity << "] {Array is empty}";
  }
    return out;
}

