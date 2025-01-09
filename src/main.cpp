#include <iostream>
#include "../include/linear_single_list.h"

using namespace std;

int main()
{
	LinearSingleList myList;

	// Создаем список: 0 1 2 3 4 5 6
	for (int i = 0; i < 7; i++)
	{
		myList.addLast(i);
	}

	cout << "Исходный список: ";
	myList.printList();

	// Добавляем 10 перед 3
	myList.addBefore(10, 3);
	cout << "После добавления 10 перед 3: ";
	myList.printList();

	// Добавляем 20 после 4
	myList.addAfter(20, 4);
	cout << "После добавления 20 после 4: ";
	myList.printList();

	// Добавляем 30 на позицию 2
	myList.addAtPosition(30, 2);
	cout << "После добавления 30 на позицию 2: ";
	myList.printList();

	return 0;
}