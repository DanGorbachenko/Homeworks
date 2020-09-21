#include <iostream>

using namespace std;

int main() {
  int number, factorial = 1;
  cin >> number;
  for(int dividor = 2; dividor <= number; dividor++)
  {
    factorial *= dividor;
  }
  cout << factorial;
  return 0;
}
