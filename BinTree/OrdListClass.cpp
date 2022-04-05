//FileName : OrdListClass.cpp
//Author: Daniel St Andrews
//Date 5/11/2021
//Project BST 
//
//Purpose: This file contains the definitions for methods of an expandable ordered binary search tree
//   class. Duplicates are not allowed to be inserted into the list.
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
#include "ItemType.h"
#include "OrdListClass.h"
#include "Exceptions.h"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

OrdListClass::OrdListClass()
{
	length = 0;
	root = nullptr;
	currPos = nullptr;
	prevPos = nullptr;
};

OrdListClass::~OrdListClass()
{
	Clear();
}

OrdListClass::OrdListClass(const OrdListClass& orig) 
{
	Copy(orig.root);
}

node* OrdListClass::Copy(node* root)
{
	if (root != nullptr)
	{
		node* temp = new node;
		temp->data = root->data;
		temp->left = Copy(root->left);
		temp->right = Copy(root->right);
		return temp;
	}
	else
	{
		return nullptr;
	}
}

void OrdListClass::FirstPosition()
{
	rFirstPos();
}

void OrdListClass::rFirstPos()
{
	if (currPos == nullptr)
	{
		throw NoLastPosException();
	}
	node* temp = root;
	if (root == nullptr)
	{
		throw RetOnEmptyException();
	}
	temp = temp->left;
	while (temp->left != nullptr)
	{
		prevPos = temp;
		temp = temp->left;
	}
	currPos = temp;
}


void OrdListClass::LastPosition()
{
	rLastPos();
}


void OrdListClass::rLastPos()
{
	if (currPos == nullptr)
	{
		throw NoLastPosException();
	}
	node* temp = currPos;
	temp = temp->right;
	while (temp->right != nullptr)
	{
		temp = temp->right;
	}
	currPos = temp;
}

void OrdListClass::NextPosition()
{
	rNextPos();
}

node* OrdListClass::minValue(node* currNode)
{
	if (currNode != nullptr)
	{
		while (currNode->left != nullptr)
		{
			currNode = currNode->left;
		}
		return currNode;
	}
	else
	{
		throw NoMinValueException();
	}
}

void OrdListClass::rNextPos()
{
	node* temp = root;
	node* tempPrev = root;
	if (currPos->data.key < root->data.key)
	{
		if (currPos->right != nullptr)
		{
			prevPos = currPos;
			currPos = currPos->right;
			while (currPos->left != nullptr)
			{
				prevPos = currPos;
				currPos = currPos->left;
			}
		}
		else
		{
			while (temp->data.key > currPos->data.key)
			{
				temp = temp->left;
			}
			while (temp->data.key < currPos->data.key)
			{
				temp = temp->right;
			}
			if (temp->data.key > currPos->data.key)
			{
				prevPos = currPos;
				currPos = temp;
			}
			else if (temp->data.key == currPos->data.key)
			{
				if (prevPos->data.key < currPos->data.key)
				{
					temp = root;
					while (temp->left->data.key > currPos->data.key)
					{
						temp = temp->left;
					}
					prevPos = currPos;
					currPos = temp;
				}
				else if (prevPos->data.key > currPos->data.key)
				{
					temp = prevPos;
					prevPos = currPos;
					currPos = temp;
				}
			}
		}
	}
	else
	{
		if (currPos->right != nullptr)
		{
			prevPos = currPos;
			currPos = currPos->right;
			while (currPos->left != nullptr)
			{
				currPos = currPos->left;
			}
		}
		else
		{
			while (temp->data.key < currPos->data.key)
			{
				tempPrev = temp;
				temp = temp->right;
			}
			while (temp->data.key > currPos->data.key)
			{
				tempPrev = temp;
				temp = temp->left;
			}
			if (temp->data.key == currPos->data.key)
			{
				prevPos = currPos;
				currPos = tempPrev;
			}
		}
	}
	temp = nullptr;
	tempPrev = nullptr;
	delete temp;
	delete tempPrev;
}

bool OrdListClass::EndofList()
{
	node* temp = root;
	temp = temp->right;
	while (temp->right != nullptr)
	{
		temp = temp->right;
	}
	if (currPos == temp)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool OrdListClass::IsEmpty()
{
	return(root == nullptr);
}

bool OrdListClass::IsFull()
{
	return false;
}

node* OrdListClass::Allocate()
{
	node* temp = new node;
	temp->left = nullptr;
	temp->right = nullptr;
	return temp;
}

ItemType OrdListClass::Retrieve()
{
	return rRet();
};

ItemType OrdListClass::rRet()
{
	if (currPos == nullptr)
	{
		throw RetrieveOnEmptyException();
	}
	else
	{
		return currPos->data;
	}
}

void OrdListClass::Clear()
{
	if (!IsEmpty())
	{
		rClear(root);
	}
}

void OrdListClass::rClear(node* currNode)
{
	if (currNode->left != nullptr)
	{
		rClear(currNode->left);
	}
	if (currNode->right != nullptr)
	{
		rClear(currNode->right);
	}
	delete currNode;
}

void OrdListClass::Insert(ItemType target)
{
	root = rInsert(root, target);
}

node* OrdListClass::rInsert(node* currNode, ItemType target)
{
	if (currNode == nullptr)
	{
		// New node must go here
		node* newNode = Allocate();
		newNode->data = target;
		length++;
		prevPos = currPos;
		currPos = newNode;
		return(newNode);
	}
	else if (currNode->data.key == target.key)
	{
		throw DuplicateKeyException();
	}
	else
	{
		if (target.key < currNode->data.key)
		{
			// Item needs to go to the left 
			currNode->left = rInsert(currNode->left, target);
		}
		else
		{
			// Item needs to go to the right
			currNode->right = rInsert(currNode->right, target);
		}
		return(currNode);
	}
}

void OrdListClass::Delete()
{
	ItemType target = Retrieve();
	root = rDelete(root, target);
}

node* OrdListClass::rDelete(node* currNode, ItemType target)
{
	if (currNode == nullptr)
	{
		throw ItemNotFoundException();
	}
	else if (currNode->data.key == target.key)
	{
		bool leftChild = (currNode->left != nullptr);
		bool rightChild = (currNode->right != nullptr);

		if (!leftChild && !rightChild)
		{
			delete currNode;
			return nullptr;
		}
		else if (!leftChild)
		{
			node* temp = currNode->right;
			delete currNode;
			return temp;
		}
		else if (!rightChild)
		{
			node* temp = currNode->left;
			delete currNode;
			return temp;
		}
		else
		{
			node* temp = currNode;
			temp = temp->right;
			while (temp->right != nullptr)
			{
				temp = temp->right;
			}
			currNode->data = temp->data;
			currNode->left = rDelete(currNode->left, temp->data);
			return currNode;
		}
	}
	else
	{
		if (target.key < currNode->data.key)
		{
			currNode->left = rDelete(currNode->left, target);
		}
		else
		{
			currNode->right = rDelete(currNode->right, target);
		}

		return currNode;
	}
} // END OF rDELETE


bool OrdListClass::Find(KeyType target)
{
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		return rFind(root, target);
	}
}

bool OrdListClass::rFind(node* currNode, KeyType target)
{
	bool result;
	if (currNode == nullptr)
	{
		result = false;
		return result;
	}
	else if (currNode->data.key == target)
	{
		currPos = currNode;
		result = true;
		return result;
	}
	else
	{
		if (target < currNode->data.key)
		{
			return(rFind(currNode->left, target));
		}
		else
		{
			return(rFind(currNode->right, target));
		}
	}
} // END OF RFIND

int OrdListClass::ReturnLength()
{
	return length;
} // END OF RETURNLENGTH

int OrdListClass::height(node* root, bool balanced)
{
	if (root == nullptr)
	{
		return 0;
	}
	int leftHeight = height(root->left, balanced);
	int rightHeight = height(root->right, balanced);
	int crHeight = std::max(leftHeight, rightHeight) + 1;

	if (abs(leftHeight - rightHeight) > 1)
	{
		balanced = false;
	}

	return crHeight;
} // END OF HEIGHT

bool OrdListClass::IsBalanced()
{
	bool balanced = true;
	height(root, balanced);
	return balanced;
} // END OF ISBALANCED


void OrdListClass::operator=(const OrdListClass& orig)
{
	node* temp = orig.root;
	CopyLeft(orig, temp);
	temp = orig.root;
	CopyRight(orig, temp);
	LastPosition();
}

void OrdListClass::CopyLeft(const OrdListClass &orig, node* temp)
{
	// For use in deep copy

	if (temp == nullptr)
	{
		return;
	}
	else
	{
		Insert(temp->data);
		if (temp->left != nullptr)
		{
			temp = temp->left;
			CopyLeft(orig, temp);
		}
		if (temp->right != nullptr)
		{
			temp = temp->right;
			CopyLeft(orig, temp);
		}
	}

}

void OrdListClass::CopyRight(const OrdListClass& orig, node* temp)
{
	// For use in deep copy
	if (temp != orig.root)
	{
		Insert(temp->data);
	}
	if (temp->right != nullptr)
	{
		temp = temp->right;
		CopyRight(orig, temp);
	}
	if (temp->left != nullptr)
	{
		temp = temp->left;
		CopyRight(orig, temp);
	}
}

bool OrdListClass::IsEqual(node* temp, node* orig)
{
	if (temp == nullptr && orig == nullptr)
	{
		return true;
	}
	else if ((temp != nullptr && orig == nullptr) || (temp == nullptr && orig != nullptr))
	{
		return false;
	}
	else
	{
		if (temp->data.key == orig->data.key && IsEqual(temp->left, orig->left) && IsEqual(temp->right, orig->right))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool OrdListClass::operator==(const OrdListClass& orig)
{
	node* temp = root;
	node* nodeOrig = orig.root;
	return IsEqual(temp, nodeOrig);
}

bool OrdListClass::operator!=(const OrdListClass& orig)
{
	node* temp = root;
	node* nodeOrig = orig.root;
	return !IsEqual(temp, nodeOrig);
}

void OrdListClass::PreOrdPrint()
{
	rPreOrdPrint(root);
}

void OrdListClass::rPreOrdPrint(node* root)
{
	ofstream dout;
	dout.flush();
	dout.open("out.txt");

	while (!EndofList())
	{
		dout << root->data.key << " ";
		rPreOrdPrint(root->left);
		rPreOrdPrint(root->right);
	}

	dout.close();
}

void OrdListClass::PrintScreen(OrdListClass obj)
{
	obj.FirstPosition();

	while (!obj.EndofList())
	{
		cout << obj.Retrieve().key << endl;
		obj.NextPosition();
	}
	cout << obj.Retrieve().key << endl;

}

void OrdListClass::PrintFile(OrdListClass obj)
{
	//Pre Order Traversal
	obj.PreOrdPrint();
}
