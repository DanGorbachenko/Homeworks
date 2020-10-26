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

void addFromKeyboard(struct ArrayList &list)
{
  int element;
  cout << "Enter an element" << endl;
  cin >> element;
  list.add(element);
}

void printList(struct ArrayList &list)
{
  cout << list.toString() << endl;
}

bool isSimmetric(struct ArrayList list)
{
  for(int i = 0; i < list.length() / 2; i++)
  {
    cout << list.get(i);
    if(list.get(i) != list.get(list.length() - i - 1))
    {
      return false;
    }
  }
  return true;
}

void moveList(struct ArrayList &list, int n)
{
  int *tmp = new int[list.length()];
  if(n >= 0)
  {
    for(int i = 0; i < list.length() - n; i++)
    {
      *(tmp + n + i) = list.get(i);
    }
    for(int i = 0; i < n; i++)
    {
      *(tmp + i) = list.get(i + list.length() - n);
    }
    for(int i = 0; i < list.length(); i++)
    {
      list.set(i, *(tmp + i));
    }
  }
  else
  {
    for(int i = 0; i < -n; i++)
    {
      *(tmp + list.length() + n + i) = list.get(i);
    }
    for(int i = 0; i < list.length() + n; i++)
    {
      *(tmp + i) = list.get(i - n);
    }
    for(int i = 0; i < list.length(); i++)
    {
      list.set(i, *(tmp + i));
    }
  }
}

bool isSimmetricExceptOne(struct ArrayList &list)
{
  bool res;
  int tmp;
  for(int i = 0; i < list.length(); i++)
  {
    tmp = list.get(i);
    list.remove(i);
    res = isSimmetric(list);
    list.add(i, tmp);
    if(res)
    {
      return res;
    }
  }
  return res;
}

int main() {
  struct ArrayList mas;
  mas.add(13);
  mas.add(14);
  mas.add(15);
  mas.add(16);
  mas.add(17);
  mas.add(18);
  mas.add(19);
  mas.add(20);
  addFromKeyboard(mas);
  printList(mas);
  isSimmetric(mas)? cout << "YES" : cout << "NO";
  moveList(mas, -3);
  printList(mas);
  return 0;
}
