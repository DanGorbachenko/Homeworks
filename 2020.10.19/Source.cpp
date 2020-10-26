#include <iostream>
#include "ArrayList.h"

using namespace std;

char* addPositive10()
{
  if(capacity < count + 10)
  {
    expand(10 - capacity + count);
  }
  srand(time(NULL));
  int* temp = new int[capacity];
  for (int i = 0; i < count; i++)
    *(temp + i) = *(data + i);
  for(int i = count; i < capacity; i++)
  {
    *(temp + i) = 10 + rand() % 90;
  }
  count += 10;
  delete[] data;
  data = temp;
  return toString();
}

char* addNegative10()
{
  if(capacity < count + 10)
  {
    expand(10 - capacity + count);
  }
  srand(time(NULL));
  int* temp = new int[capacity];
  for (int i = 0; i < count; i++)
    *(temp + i) = *(data + i);
  for(int i = count; i < capacity; i++)
  {
    *(temp + i) = -10 - rand() % 90;
  }
  count += 10;
  delete[] data;
  data = temp;
  return toString();
}

int* bubbleSort()
{
  int *temp = data;
  for(int i = 0; i < capacity - 1; i++)
  {
    for(int j = 0; j < capacity - i; j++)
    {
      if(*(temp + j) > *(temp + j + 1))
      {
        *(temp + j) = *(temp + j) ^ *(temp + j + 1);
        *(temp + j + 1) = *(temp + j) ^ *(temp + j + 1);
        *(temp + j) = *(temp + j) ^ *(temp + j + 1);
      }
    }
  }
  return temp;
}

int getMin()
{
  int *temp = bubbleSort();
  return *temp;
}

int getMax()
{
  int *temp = bubbleSort();
  return *(temp + capacity);
}

char* shuffle()
{
  int *temp = new int[count];
  for(int i = 0; i < count; i++)
  {
    *(temp + i) = 0;
  }
  srand(time(NULL));
  int index;
  bool flag = true;
  for(int i = 0; i < count; i++)
  {
    while(flag)
    {
      index = rand() % count;
      if(*(temp + index) == 0)
      {
        *(temp + index) = *(data + i);
        flag = false;
      }
    }
    flag = true;
  }
  delete[] data;
  data = temp;
  return toString(); 
}

void changeNegatives()
{
  for(int i = 0; i < count; i++)
  {
    if(*(data + i) < 0)
    {
      *(data + i) = 0;
    }
  }
}

int main() {
  struct ArrayList mas;
  mas.add(13);
  mas.add(14);
  mas.add(15);
  cout << mas.toString() << endl;
  cout << mas.addPositive10() << endl;
  cout << mas.shuffle() << endl;
  return 0;
}
