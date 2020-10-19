#include <iostream>
#include "ArrayList.h"

using namespace std;

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
