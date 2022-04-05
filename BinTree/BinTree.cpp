//FileName : BinTree.cpp
//Author: Daniel St Andrews
//Date 5/11/2021
//Project BST
//
//Purpose: This file contains the client side code for a testable Ordered binary search class. 
//
//Assumptions:
//
//
//Exception Handling:
//This class can throw the following exceptions:
//	
//NoLastPosException - Thrown if there is no lastposition in the list, and the list is empty.
//RetOnEmptyException - If the list is empty and retrieve is called then this is thrown 
//DuplicateKeyException - Thrown if the key being inserted is already in the list
//ItemNotFoundException - Thrown if the list is empty and find is called.
//NoMinValueException - Exception to handle errors in the minvalue function where there is only one element or the list is empty.
//
#pragma once
#include <iostream>
#include <fstream>
#include "OrdListClass.h"
#include "Exceptions.h"

using namespace std;

int main()
{
	OrdListClass list;
	OrdListClass myList;

	ItemType data;
	ItemType item;
	data.key = 0;
	
	list.Insert(data);
	list.Delete();
	list.Insert(data);

	for (int i = 0; i < 17; i++)
	{
		switch (i)
		{
		case 0: item.key = 25; break;
		case 1: item.key = 20; break;
		case 2: item.key = 22; break;
		case 3: item.key = 10; break;
		case 4: item.key = 12; break;
		case 5: item.key = 15; break;
		case 6: item.key = 5; break;
		case 7: item.key = 8; break;
		case 8: item.key = 1; break;
		case 9: item.key = 36; break;
		case 10: item.key = 30; break;
		case 11: item.key = 28; break;
		case 12: item.key = 40; break;
		case 13: item.key = 38; break;
		case 14: item.key = 48; break;
		case 15: item.key = 45; break;
		case 16: item.key = 50; break;
		}
		myList.Insert(item);
	}

	if (!(myList.IsEmpty()))
	{
		myList.FirstPosition();
			while (myList.EndofList() == false)
			{
				cout << myList.Retrieve().key << " ";
				
				myList.NextPosition();
			}
			cout << myList.Retrieve().key << endl;
	}

	if (myList!=list)
	{
		// Should go here
		cout << "Not Equal" << endl;
	}
	else
	{
		cout << "Equal" << endl;
	}

	if (myList == list)
	{
		cout << "Equal" << endl;
	}
	else
	{
		// Should go here
		cout << "Not equal" << endl;
	}

	list = myList;

	if (!(list.IsEmpty()))
	{
		list.FirstPosition();
		while (list.EndofList() == false)
		{
			cout << list.Retrieve().key << " ";

			list.NextPosition();
		}
		cout << list.Retrieve().key << endl;
	}
		

	myList.PrintFile(myList);
	myList.PrintScreen(myList);
	
	myList.Clear();
	list.Clear();

}
