/*
Absolute C++ (5e); Ch. 17 "Linked Data Structures"; Project 1
*/

#include "IntList.h"

namespace ncoop {

	// IntList definitions
	IntList::IntList()
	{
		listHead = NULL;
	}

	size_t IntList::size()
	{
		return 0; // stub
	}
	
	IntListNode* IntList::insert(int theData)
	{
		IntListNode(theData, listHead);
		return NULL; // stub
	}
	
	IntListNode* IntList::remove(int theData)
	{
		return NULL; // stub
	}


	// IntListNode definitions
	IntListNode::IntListNode()
	{
		nextNode = NULL;
	}
	
	IntListNode::IntListNode(int theData, IntListNode* theNextNode)
	{
		data = theData;
		nextNode = theNextNode;
	}
	
	int IntListNode::getData()
	{
		return data;
	}
	
	IntListNode* IntListNode::getNextNode()
	{
		return nextNode;
	}
	
	void IntListNode::setData(int newData)
	{
		data = newData;
	}
	
	void IntListNode::setNextNode(IntListNode* newListNode)
	{
		nextNode = newListNode;
	}

} // ncoop
