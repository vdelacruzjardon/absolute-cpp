/*
Absolute C++ (5e); Ch. 17 "Linked Data Structures"; Project 1
*/

#ifndef INT_LIST_H
#define INT_LIST_H

namespace ncoop {
	
    class IntListNode {
    public:
		IntListNode();
		IntListNode(int theData, IntListNode* theNextNode);
		
		int getData();
		IntListNode* getNextNode();
		
		void setData(int newData);
		void setNextNode(IntListNode* newListNode);

    private:
		int data;
		IntListNode* nextNode;

    }; // class IntListNode

    class IntList {
	public:
		IntList();

		size_t size();
		IntListNode* insert(int theData);
		IntListNode* remove(int theData);
	
	private:
		IntListNode* listHead;
	
	}; // class IntList
	
} // ncoop

#endif // INT_LIST_H
