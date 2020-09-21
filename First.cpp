#include <iostream>

using namespace std;

int main() {
  int x, s1, s2;
  cin >> x;
  s1 = x * (x + 1);
  s2 = s1 * (s1 - x);
  cout << s2 + s1 + 1;
  return 0;
}
