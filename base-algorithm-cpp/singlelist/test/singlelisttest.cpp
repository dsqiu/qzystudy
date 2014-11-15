#include <iostream>
#include <stdlib.h>
using namespace std;
#include "SingleList.h"
int main(int argc, char *argv[])
{
	SingleList<int> list;
	for (int i = 0; i < 20; i++) {
		list.Insert(i * 3,i);
	}
	for (int i = 0; i < 5; i++) {
		list.Insert(3,i*3);
	}
	std::cout << "the Length of the list is" << list.Length() << std::endl;
	list.Print();
	list.Remove(5);
	std::cout << "the Length of the list is" << list.Length() << std::endl;
	list.RemoveAll(3);
	std::cout << "the Length of the list is" << list.Length() << std::endl;
	list.Print();
	std::cout << "The third element is" << list.Get(3) << std::endl;
	cout << *list.Find(18,1) << endl;

	list.Find(100);

	list.MakeEmpty();
	std::cout << "the Length of the list is " << list.Length() << std::endl;
	list.Print();

	return 0;
}
