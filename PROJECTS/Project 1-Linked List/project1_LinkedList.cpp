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
	Node* ptrCurrent = m_ptrFirst;
	Node* newNode = new Node;
	newNode->m_data = newData;

	int counter = 0;

	if (index < 0 || index > m_itemCount)
	{
		throw out_of_range("out of bounds index");
	}

	else if (m_itemCount - index == 0)
	{
		PushFront(newData);
	}

	else if (m_itemCount == index)
	{
		PushBack(newData);
	}

	else
	{
		while (counter != index)
		{
			ptrCurrent = ptrCurrent->m_ptrNext;
			counter++;

			if (counter == index)
			{
				ptrCurrent->m_ptrPrev->m_ptrNext = newNode;
				newNode->m_ptrPrev = ptrCurrent->m_ptrPrev;
				newNode->m_ptrNext = ptrCurrent;
				ptrCurrent->m_ptrPrev = newNode;
				m_itemCount++;
			}
		}
	}
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
	Node* ptrCurrent = m_ptrFirst;
	int counter = 0;
	while (counter != index)
	{
		ptrCurrent = ptrCurrent->m_ptrNext;
		counter++;
		if (counter == index)
		{
			ptrCurrent->m_ptrNext->m_ptrPrev = ptrCurrent->m_ptrPrev;
			ptrCurrent->m_ptrPrev->m_ptrNext = ptrCurrent->m_ptrNext;
			m_itemCount--;
		}
	}
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

