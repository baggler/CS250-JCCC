#include "project1_LinkedList.hpp"

Node::Node() : m_ptrNext(nullptr), m_ptrPrev(nullptr)
{
}

LinkedList::LinkedList() : m_ptrFirst(nullptr), m_ptrLast(nullptr), m_itemCount(0)
{
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Clear()
{
	while (!IsEmpty())
	{
		PopFront();
	}
}

void LinkedList::PushFront( CustomerData newData )
{
	Node* newNode = new Node;
	newNode->m_data = newData;
	m_itemCount++;

	if (m_ptrFirst == nullptr && m_ptrLast == nullptr)
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}

	else
	{
		m_ptrFirst->m_ptrPrev = newNode;
		newNode->m_ptrNext = m_ptrFirst;
		m_ptrFirst = newNode;
	}
}

void LinkedList::PushBack( CustomerData newData )
{
	Node* newNode = new Node;
	newNode->m_data = newData;
	m_itemCount++;

	if (m_ptrFirst == nullptr && m_ptrLast == nullptr)
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}

	else
	{
		m_ptrLast->m_ptrNext = newNode;
		newNode->m_ptrPrev = m_ptrLast;
		m_ptrLast = newNode;
	}
}

void LinkedList::PushIndex(CustomerData newData, int index)
{
	// Creating a walking pointer and a newNode pointer to hold the data passed in.
	Node* ptrCurrent = m_ptrFirst;
	Node* newNode = new Node;
	newNode->m_data = newData;
	// Counter to keep track of which index we are at while traversing the list
	int counter = 0;
	//Error checking input
	if (index < 0 || index > m_itemCount)
	{
		throw out_of_range("Index is out of the list's range!");
	}
	//Check if list is empty, if it is assign first & last ptr's to newNode
	else if (m_ptrFirst == m_ptrLast)
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
		return;
	}
	//Check to see if the given insert index is zero, if it is call PushFront and pass it the data.
	else if (index == 0)
	{
		PushFront(newData);
		return;
	}
	//Check to see if the insert index is at the last node, if it is call PushBack and pass it the data.
	else if (index == m_itemCount)
	{
		PushBack(newData);
		return;
	}
	// Begin traversing the list, once the desired index is reach, ptrCurrent will hold that address.
	while (counter != index)
	{
		ptrCurrent = ptrCurrent->m_ptrNext;
		counter++;
	}
	//Once the index is found, insert the newNode and update all the pointer and itemCount.
	ptrCurrent->m_ptrPrev->m_ptrNext = newNode;
	newNode->m_ptrPrev = ptrCurrent->m_ptrPrev;
	newNode->m_ptrNext = ptrCurrent;
	ptrCurrent->m_ptrPrev = newNode;
	m_itemCount++;
}

void LinkedList::PopFront() noexcept
{
	if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	else
	{
		Node* ptrSecond = m_ptrFirst->m_ptrNext;
		ptrSecond->m_ptrPrev = nullptr;
		delete m_ptrFirst;
		m_ptrFirst = ptrSecond;
		m_itemCount--;
	}
}

void LinkedList::PopBack() noexcept
{
	if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrLast;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	else
	{
		Node* ptrSecondToLast = m_ptrLast->m_ptrPrev;
		ptrSecondToLast->m_ptrNext = nullptr;
		delete m_ptrLast;
		m_ptrLast = ptrSecondToLast;
		m_itemCount--;
	}
}

void LinkedList::RemoveIndex(int index)
{
	int counter = 0;
	Node* ptrCurrent = m_ptrFirst;
	//Check that the index is valid, greater then zero and not bigger then the list size
	if (index < 0 || index > m_itemCount)
	{
		throw out_of_range("Index is out of the list's range");
	}
	//Check if the list is empty, if it is just ignore the call and return.
	else if (m_ptrFirst == nullptr)
	{
		return;
	}
	//Check if the index is the first node, if it is call PopFront function and return to exit
	else if (index == 0)
	{
		PopFront();
		return;
	}
	//Check if the index is the last node, if it is call PopBack function and return to exit
	else if (index == m_itemCount)
	{
		PopBack();
		return;
	}
	//Index is not first or last, start traversing list and find the index.
	while (counter != index)
	{
		ptrCurrent = ptrCurrent->m_ptrNext;
		counter++;
	}
	//Index to be removed has been found, reassign the ptrPrev and PtrNext pointers
	ptrCurrent->m_ptrNext->m_ptrPrev = ptrCurrent->m_ptrPrev;
	ptrCurrent->m_ptrPrev->m_ptrNext = ptrCurrent->m_ptrNext;
	m_itemCount--;
}

CustomerData LinkedList::GetFront()
{
	// Return the data in the node the header/first pointer is point at
	if (m_ptrFirst == nullptr)
		throw logic_error("Object does not contain data!");
	return (m_ptrFirst->m_data);
}

CustomerData LinkedList::GetBack()
{
	// Return the data in the node that last pointer is pointing at
	if (m_ptrLast == nullptr)
		throw logic_error("Object does not contain data!");
	return (m_ptrLast->m_data);
}

CustomerData& LinkedList::operator[]( const int index )
{	
	// Error Checking for valid index entry
	if (index < 0 || index >= m_itemCount )
	{
		throw out_of_range("index is out of range!");
	}
	// Index is valid, begin traversing list
	int counter = 0;
	Node* ptrCurrent = m_ptrFirst;

	while (counter != index)
	{
		//Go to next item
		ptrCurrent = ptrCurrent->m_ptrNext;
		counter++;
	}
	return (ptrCurrent->m_data);
}

bool LinkedList::IsEmpty()
{
	//if (m_itemCount == 0)
	return (m_itemCount == 0);
}

int LinkedList::Size()
{
	return m_itemCount;
}

