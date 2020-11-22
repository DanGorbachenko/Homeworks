#include<iostream>
#include "LinkedList.h"

using namespace std;

void printList(LinkedList list)
{
	cout << "PRINTED LIST : " << list << endl << endl;
}

int main()
{
	LinkedList list;
	cout << list << endl;
	list.addToHead(5);
	cout << list << endl;
	list.addToHead(6);
	cout << list << endl;
	list.addToTail(8);
	cout << list << endl;
	list.add(2, 9);
	cout << list << endl;

	LinkedList* banana;
	banana = new LinkedList();
	(*banana).add(0, 4);
	banana->add(0, 5);
	cout << *banana << endl << endl;

	cout << "LIST" << list << endl;
	cout << list.get(5) << endl;
	cout << list.get(2) << endl;
	list.set(3, 4);
	cout << list << endl;
	list.set(4, 65);
	cout << list << endl;

	cout << "list[2] = " << list[2] << endl;
	list[1] = 12354;
	cout << "list[1] = " << list[1] << endl;
	cout << list << endl;
	list[-12] = -12;
	list[5123] = 1;
	list[list.length()] = 78;
	cout << list << endl;
	printList(list);

	cout << "Index of element: " << list.indexOf(9) << endl;

	LinkedList list2 = list;
	cout << endl << "New list2" << endl;
	printList(list2);

	/*cout << list.extractHead() << endl;
	printList(list);

	cout << list.extractTail() << endl;
	printList(list);

	cout << list.extract(1) << endl;
	printList(list);

	list -= 1;
	printList(list);

	cout << list.contains(1235) << endl;*/

	list2.swap(0, 2);
	printList(list2);

	return 0;
}