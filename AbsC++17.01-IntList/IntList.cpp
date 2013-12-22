/*
Absolute C++ (5e); Ch. 17 "Linked Data Structures"; Project 1
*/

#include "IntList.h"

namespace ncoop {

	// IntList definitions
	IntList::IntList()
	{ // default constructor sets head to null
		listHead = new ListNode;
	}

	IntList::IntList(const IntList& original)
	{ // copy constructor makes a deep copy of the original list
		listHead = new ListNode;
		*this = original;
	}
	
	IntList::~IntList()
	{ // destructor deletes every node and then the head
	}
	
	size_t IntList::size()
	{ // return number of nodes in the list
		size_t count(0);
		thisNode* = listHead;
		while (thisNode->next != NULL)
		{
			count++;
		}
		return count; // stub
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
	{ // default constructor
		nextNode = NULL;
	}
	
	IntListNode::IntListNode(int theData, IntListNode* theNextNode)
	{ // constructor specifies data to be added
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
