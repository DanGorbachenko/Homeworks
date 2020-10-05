#include <iostream>
#include <math.h>

using namespace std;

int main() {
  int number;
  bool flag;
  cin >> number;
  for(int i = 2; i <= number; i++)
  {
    flag = true;
    for(int dividor = 2; dividor <= sqrt(number); dividor++)
    {
      if(i % dividor == 0 && dividor < i)
      {
        flag = false;
        break;
      }
    }
    if(flag)
      cout << i << endl;
  }
  return 0;
}