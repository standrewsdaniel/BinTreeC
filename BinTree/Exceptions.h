//FileName : Exceptions.h
//Author: Daniel St Andrews
//Date 5/11/2021
//Project BST
//
//Purpose: This file contains the Exception Handling declarations for the BST Class.
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
//
//

#pragma once

class NoLastPosException {};

class RetOnEmptyException {};

class DuplicateKeyException {};

class ItemNotFoundException {};

class RetrieveOnEmptyException {};

class NoMinValueException {};