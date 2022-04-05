//FileName : ItemType.h
//Author: Daniel St Andrews
//Date 5/11/2021
//Project BST
//
//Purpose: This file contains the class declarations for the ItemType Definitions of the program.
//
//Assumptions:
//	None
//
//Exception Handling:
//	None

#pragma once

typedef int KeyType;
struct ItemType
{
	KeyType key;
	// Key for the BST list
};

struct node {
	ItemType data;
	// Information stored as an ItemType
	node* left, * right;
	// Child nodes of root node descending from BSTClass 
};