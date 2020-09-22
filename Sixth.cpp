#include <iostream>

using namespace std;

int main() {
  int number, factorial = 1;
  cin >> number;
  for(int n = 2; n <= number; n++)
  {
    factorial *= n;
  }
  cout << factorial;
  return 0;
}
