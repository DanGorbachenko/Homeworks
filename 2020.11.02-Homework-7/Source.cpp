#include<iostream>
#include"ArrayList.h"

using namespace std;

int main()
{
    ArrayList list1, list2;
    list1 += 4; list1 += 1; list1 += 2; list1 += 3; list1 += 4; list1 += 6;
    list2 += 19; list2 += 18; list2 += 15; list2 += 14; list2 += 13; list2 += 12;
    ArrayList list3;
    cout << "list1 = " << list1 << endl;
    cout << "list2 = " << list2 << endl;
    cout << "list3 = " << list3 << endl;
    list1 -= 4;
    list2 -= 12;
    cout << "list1 = " << list1 << endl;
    cout << "list2 = " << list2 << endl;
    list3 = list2;
    cout << "list3 = " << list3 << endl;
    cout << "list3 = list1 + 5" << endl;
    list3 = list1 + 5;
    cout << "list3 = " << list3 << endl;
    ArrayList list4;
    list4 = 20 + list2;
    cout << "list4 = " << list4 << endl;
    ArrayList list5;
    list5 = list4 + list3;
    cout << "list5 = " << list5 << endl;
    ArrayList list6;
    list6 = list5 - 4;
    cout << "list6 = " << list6 << endl;
    ArrayList list7;
    list7 = 4 - list1;
    cout << "list7 = " << list7 << endl;
    return 0;
}

