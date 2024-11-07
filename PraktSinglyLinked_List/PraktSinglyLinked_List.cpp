#include <iostream>
#include "FwdList.h"
using namespace std;

int main()
{
	FwdList<int> list1;
	for (size_t i = 0; i < 5; i++) {
		list1.addHead(rand() % 30);
	}
	cout << "List 1:" << endl;
	list1.print();

	FwdList<int> list2;
	for (size_t i = 0; i < 5; i++) {
		list2.addHead(rand() % 30);
	}
	cout << "List 2:" << endl;
	list2.print();

	
	cout << "Cloning List 1:" << endl;
	FwdList<int> clonedList = list1.clone();
	clonedList.print();

	
	cout << "List 1 + List 2:" << endl;
	FwdList<int> combinedList = list1 + list2;
	combinedList.print();

	
	cout << "List 1 * List 2 (common elements):" << endl;
	FwdList<int> intersectionList = list1 * list2;
	intersectionList.print();

}
