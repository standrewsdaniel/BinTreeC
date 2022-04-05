//FileName : OrdListClass.h
//Author: Daniel St Andrew
//Date 5/11/21
//Project List 
//
//Purpose: This file contains the specification for an ordered binary search tree class.
//	 The struct definition for the BST ItemType should be placed in the file 
//   ItemType.h, therefore no code change need be made within the implementation 
//   file to change the basic design of a BST item. It contains 13 public and 10 protected methods. 
//   It also contains 3 private data elements.
//
//                       SUMMARY OF METHODS: 
//
//PUBLIC METHODS
//
// OrdListClass(); - Constructor
// ~OrdListClass(); - Deconstructor
// OrdListClass(const OrdListClass& orig); - Copy Constructor
// 
// void FirstPosition(); - Sets currPos to beginning of list
// void NextPosition(); - Sets currPos to the next position in the list
// void LastPosition(); - Sets currPos to the last position in the list
//
// bool IsEmpty(); - Returns true if the list is empty and has no elements
// bool IsFull(); - Returns true if the list is full.
// bool EndOfList(); - Returns true if currPos is at the end of the list
//
// ItemType Retrieve(); - Returns the record of item at currPos
// 
// bool Find(KeyType target); - Finds the position of a target and sets currPos to its location
// void Insert(ItemType newItem); - Inserts a target into ordlist in correct position noted by find
// void Delete(); - Deletes an entry in the list noted by find.
//
// Void Clear(); - Clears List
// int ReturnLength(); - Returns length of the list
//
// bool IsBalanced(); - Returns true if balanced and false if not
// 
// operator=(const OrdListClass &orig)  - Overloads operator and deep copies one list onto another
// operator==(const OrdListClass &orig) - Overloads operator to compare two OrdlistClass objs and returns true if all nodes are the same
// operator!=(const OrdListClass &orig) = Overloads operator to compare two OrdListclass objects and returns false if they are both the same and true if they are not.
//
// int height(node* temp); - Returns the current height of the BST
//
// void CopyLeft(const OrdListClass &orig, node* temp); - Copies the left side of the tree 
// void CopyRight(const OrdListClass &orig, node* temp); - Copies the right side of the tree
//
// bool IsEqual(node* temp, node* orig) - Returns true if the two objs are equal
// 
// void PreordPrint() - Prints the tree in pre order
// 
// void PrintFile(OrdListClass obj); - Prints the list to a file
//
// void PrintScreen(OrdListClass obj) - Prints to the screen
//
//PROTECTED METHODS:
//
// void rClear(node* temp); - Recursive clear, called by wrapper method
//
// node* rInsert(node* currNode, ItemType target); - Recursive Insert, called by wrapper method
//
// node* rDelete(node* currNode, ItemType target); - Recusive delete, called by wrapper method
//
// bool rFind(node* currNode, KeyType target); - Recursive Find, called by wrapper method
//
// void rFirstPos(); - Hidden first pos, called by wrapper method 
//
// void rLastPos(); - Hideen last pos, called by wrapper method
//
// node* minValue(node* node); - Returns the node* of the smallest value in the list
//
// node* NextPos(node* root); - Increments currPos to the next in order successor 
//
// ItemType rRet(); - Hidden retrieve, called by wrapper method
//
// node* Copy(node* root); - Copy a provided node
//
// void rPreOrdPrint(node* root); - Prints bst in pre order recursively
//
//PRIVATE MEMBERS / METHODS: 
//
// Allocate(); - Allocates new space in the BST for a new member
//
// node* root - Stores the root of the list
//
// node* prevPos - Stores the previous position in the list after currPos is incremented
//
// node* currPos - Stores current position in the list

#pragma once
#include "ItemType.h"


class OrdListClass
{
public:
	//PUBLIC METHODS: 

	OrdListClass();        			//constructor
	//Pre: None
	//Post: Instantiates OrdListClass obj
	//Purpose: Instantiate OrdListClass obj

	~OrdListClass();				//destructor
	//Pre: OrdListClass obj exists
	//Post: Clears memory taken up by OrdListClass objs
	//Purpose: Deallocate memory used by OrdListClass objs
	OrdListClass(const OrdListClass& orig);	//copy constructor	
	//Pre: Needs another existing OrdListClass item
	//Post: Copy over OrdListClass obj to a new one
	//Purpose: Copy constructor for a new OrdListClass obj
	void  FirstPosition();		//sets currPos  to beginning of list 
	//Pre: List must exist 
	//Post: Sets currPos to the first position and smallest value in the list
	//Purpose: Wrapper method for hidden FirstPos so that the user does not have access to pdms
	void  NextPosition();  		//sets currPos  to next element in list 
	//Pre:List must exist
	//Post: Increments currPos to the next in order successor in the list
	//Purpose: Wrapper method for hidden NextPos so that the user does not have access to pdms
	void  LastPosition();   	//sets currPos  to last element in the list
	//Pre:List must exist
	//Post: Increments currPos to be seated at the last position in the list
	//Purpose: Set currPos to the last position or largest value in the list
	bool  IsEmpty();   		//returns true if OrdList has no elements.
	//Pre:List must exist
	//Post: Returns true or false depending on whether or not the list is empty
	//Purpose: Determine whether or not the list is empty and return true if it is and false if it is not 
	bool  IsFull();   		//returns true if OrdList is full 
	//Pre:List must exist
	//Post: Returns true or false depending on whether or not the list is full, which it never is
	//Purpose: Return false always due to the fact that the list can never be full.
	bool  EndofList();     
	//returns true if currPos specifies end of List. 
	//end of list means nullptr after the last element.
	//Pre:List must exist
	//Post: Returns true if currPos is at the end of the list
	//Purpose: Return true or false depending on whether or not currPos is sitting at the end of the list
	ItemType Retrieve();		
	//returns a record (ItemType) specified by currPos. 
	//Throws RetrieveOnEmpty Exception
	//Pre:List must exist
	//Post: Return the record of an entry at currPos
	//Purpose: Wrapper method for rRet
	bool Find(/*in*/ KeyType target);
	//   --finds position of target within the OrdList. If target is not present, currPos //should point to position immediately where target would have been found and //false will be returned.  If target is present, currPos should point to it and true //should be returned. This method should also set prevPos to the item before  //where the desired item is found.
	//Pre:List must exist
	//Post: Return true if the item is found in the list and false if it is not
	//Purpose: Wrapper method for recursive find
	void Insert(/*in*/ ItemType newItem);
	//   --inserts target into OrdList in correct position(already noted by Find)
	//   --throws DuplicateKey Exception if item already exists in list
	//Pre:List must be instantiated
	//Post:
	//Purpose:
	void Delete();
	//   --Deletes a list entry (already noted by Find)
	//   --throws DeleteOnEmpty exception if list is empty
	//   --throws KeyNotFound exception if currPos = nullptr
	//Pre: None
	//Post: Deletes a list entry (already noted by Find)
	//Purpose: Delete an entry in the list
	void Clear();   		//Clears list.
	//Pre: List must exist
	//Post: Clears list
	//Purpose: Clears all members of the list
	int ReturnLength();  		//traverses list & counts the number of items in the list. 
	//Pre: List must exist
	//Post: Returns the length of the list
	//Purpose: Return length of the current list
	bool IsBalanced(); 		// returns true if the tree is balanced, false otherwise
	//Pre: List must exist
	//Post: Returns true if balanced and false if not
	//Purpose: Determine whether or not the given list is balanced
	int height(node* root, bool balanced);
	// Returns height of current list obj
	//Pre: Needs root and bool var balanced passed in
	//Post: Determines the height of the BST and returns whether or not its balanced in the same call
	//Purpose: Return the height of the BST based off of the pos of the root
	int length;

	// OPERATOR METHODS
	void operator = (const OrdListClass& orig);
	//performs a deep copy of orderedList  
	//Pre: Needs two OrdListClass objs to exist
	//Post: Deep copies one obj to the other
	//Purpose: performs a deep copy on two ordlistclass objs and assigns one to the other
	bool operator == (const OrdListClass& rtOp);
	//returns true if applying operator keys are equivalent to those keys in rtOp, false otherwise
	//Pre: Needs two OrdListClass objs to compare
	//Post: Returns true if both BSTs have the same nodes
	//Purpose: Return true or false depending on if two bsts are the same or not
	bool operator != (const OrdListClass& rtOp);
	//returns true if applying operator keys are not equivalent to those keys in rtOp, false otherwise
	//Pre: Requires two OrdListClass objs to exist in order to compare
	//Post: Returns false if the two are the same and true if theyre different
	//Purpose: Return true or false depending on if the two OrdListClass objs are the same
	void CopyLeft(const OrdListClass &orig, node* temp);
	//Pre: Needs an ordListClass obj as well as a root node
	//Post: Copies the left side of the bst
	//Purpose: Copy the left side of a given bst
	void CopyRight(const OrdListClass& orig, node* temp);
	//Pre: Needs an ordListClass obj as well as a root node
	//Post: Copies the right side of the bst
	//Purpose: Copy the right side of a given bst
	bool IsEqual(node* temp, node* orig);
	//Pre: Needs nodes to compare to be passed in
	//Post: Returns true or false depending on whether or not the two nodes are equal
	//Purpose: Return true if nodes are equal and false if they are not
	// PRINT ASSIST METHODS

	void PreOrdPrint();
	//Pre: List Must Exist
	//Post: Print the list in a pre order traversal 
	//Purpose: Performs a pre order traversal on the BST
	void PrintFile(OrdListClass obj);
	//Pre: List must exist
	//Post: Prints the contents of the BST to a file
	//Purpose: Output BST to a file
	void PrintScreen(OrdListClass obj);
	//Pre: Needs OrdListClass obj passed in
	//Post: Prints the contents of the BST to the screen in order
	//Purpose: Print the BST to the screen
protected:

	void rClear(node* temp);
	//Pre: Needs a node* passed in
	//Post: Clears the list without giving user access to pdms
	//Purpose: Clear the list
	node* rInsert(node* currNode, ItemType target);
	//Pre: Needs root note and target passed in
	//Post: Inserts an item in the list 
	//Purpose:Insert a new item into the list
	node* rDelete(node* currNode, ItemType target);
	//Pre: Needs root node and target passed in
	//Post: Deletes item specified by target
	//Purpose: Recursively delete an item from the lsit
	bool rFind(node* currNode, KeyType target);
	//Pre: Needs the current node or root passed in and then the target passed in as well
	//Post: Returns true or false depending on if the target is in the specified list
	//Purpose: Returns true or false if the item is contained in the BST or not
	void rFirstPos();
	//Pre: List must exist
	//Post: Moves currPos to the first position in the list
	//Purpose: Sets currPos to the smallest value in the BST
	void rLastPos();
	//Pre: List must exist
	//Post: Moves currPos to last position in the list
	//Purpose: Move currPos to the last position in the list
	void rNextPos();
	//Pre: List must exist
	//Post: Increments currPos to the in order successor in the list
	//Purpose: Increment currPos to the next position in the list
	node* minValue(node* node);
	//Pre: Pass in starting node / root
	//Post: Returns node* of the smallest value in the bst
	//Purpose: Find smallest value in BST and return it
	ItemType rRet();
	//Pre: List must exist
	//Post: Returns the current item at CurrPos
	//Purpose: Provide call for wrapper method Retrieve, returns currPos
	node* Copy(node* root);
	//Pre: Pass in node to be copied
	//Post: Copy a given node
	//Purpose: Return copy of a given node 
	void rPreOrdPrint(node* root);
	//Pre: List must exist and node* root must be passed in
	//Post: Prints BST in pre order traversal
	//Purpose: Traverse the list in pre order.

private:
	node* root;
	node* prevPos;
	node* currPos;

	node* Allocate();
	//Pre: None
	//Post: Allocates space in the list for a new entry
	//Purpose: Make pointers to a left and right child for a node in the list

};