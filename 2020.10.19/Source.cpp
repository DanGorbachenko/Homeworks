#include <iostream>
#include <ctime>
#include "ArrayList.h"

using namespace std;

void addPositive10(struct ArrayList &list)
{
  srand(time(NULL));
  for(int i = 1; i <= 10; i++)
  {
    list.add(10 + rand() % 90);
  }
  cout << list.toString() << endl;
}

void addNegative10(struct ArrayList &list)
{
  srand(time(NULL));
  for(int i = 1; i <= 10; i++)
  {
    list.add(- 10 - rand() % 90);
  }
  cout << list.toString() << endl;
}

int getMin(struct ArrayList &list)
{
  int minElement = list.get(0);
  for(int i = 1; i < list.length(); i++)
  {
    if(minElement > list.get(i))
    {
      minElement = list.get(i);
    }
  }
  return minElement;
}

int getMax(struct ArrayList &list)
{
  int maxElement = list.get(0);
  for(int i = 1; i < list.length(); i++)
  {
    if(maxElement < list.get(i))
    {
      maxElement = list.get(i);
    }
  }
  return maxElement;
}

void swapMinMax(struct ArrayList &list)
{
  int minElement = getMin(list);
  int maxElement = getMax(list);
  int minIndex, maxIndex;
  minIndex = list.indexOf(minElement);
  for(int i = list.length() - 1; i >= 0 ; i--)
  {
    if(list.get(i) == maxElement)
    {
      maxIndex = i;
    }
  }
  list.swap(minIndex, maxIndex);
  cout << list.toString() << endl;
}

void shuffle(struct ArrayList &list)
{
  srand(time(NULL));
  for(int i = 0; i < list.length(); i++)
  {
    list.swap(i, rand() % (list.length() - 1));
  }
  cout << list.toString() << endl;
}

void changeNegatives(struct ArrayList &list)
{
  for(int i = 0; i < list.length(); i++)
  {
    if(list.get(i) < 0)
    {
      list.set(i, 0);
    }
  }
  cout << list.toString() << endl;
}

int main() {
  struct ArrayList mas;
  mas.add(13);
  addPositive10(mas);
  addNegative10(mas);
  swapMinMax(mas);
  shuffle(mas);
  changeNegatives(mas);
  return 0;
}
