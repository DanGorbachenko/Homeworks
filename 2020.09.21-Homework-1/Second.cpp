#include <iostream>

using namespace std;

int main() {
  int a, b, n = 1;
  cin >> a;
  cin >> b;
  while(a - b > b)
  {
    a -= b;
    n++;
  }
 cout <<n;
  return 0;
}