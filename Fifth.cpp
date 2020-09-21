#include <iostream>

using namespace std;

int main() {
  int number, count = 0;
  cin >> number;
  for(int dividor = 1; dividor <= number; dividor++)
  {
    if(number % dividor == 0)
      count += 1;
  }
  cout << count;
  return 0;
}
