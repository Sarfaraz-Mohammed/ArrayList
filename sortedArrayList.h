/*
 * sortedArrayList.h
 *
 *  Created on: Mar 26, 2019
 *      Author: smohammed730
 */

#ifndef SORTEDARRAYLIST_H_
#define SORTEDARRAYLIST_H_

#include <iostream>
using namespace std;

template <class elemType>
class sortedArrayList{
private:
	int length;
	int maxSize;
	elemType *list;
public:
	sortedArrayList(int size = 100);
	bool isEmpty() const;
	bool isFull() const;
	int listSize() const;
	int maxListSize() const;
	void print();
	bool insert(const elemType& item);
	bool remove(const elemType& item);
	void clearList();
	virtual ~sortedArrayList();
	unsigned int binSearchIter(const elemType& element);
	unsigned int binSearchRec(const elemType& element);
};

#endif /* SORTEDARRAYLIST_H_ */

//constructor
template <class elemType>
sortedArrayList<elemType>::sortedArrayList(int size = 100)
{
	length = 0;
	maxSize = size;
	list = 0;
}

//is Empty
template <class elemType>
bool sortedArrayList<elemType>::isEmpty() const
{
	return(length == 0);
}

//is Full
template <class elemType>
bool sortedArrayList<elemType>::isFull() const
{
	return (length == maxSize);
}

//listSize
template <class elemType>
int sortedArrayList<elemType>::listSize() const
{
	return length;
}

//maxListSize
template <class elemType>
int sortedArrayList<elemType>::maxListSize() const
{
	return maxSize;
}

//print
template <class elemType>
void sortedArrayList<elemType>::print()
{
	for(unsigned int i = 0; i < this->length; i++){
		cout << this->list[i] << ", ";
	}
	cout << endl;
}

//insert
template <class elemType>
bool sortedArrayList<elemType>::insert(const elemType& item)
{
	int first = 0;
	int last = length - 1;
	int mid;
	bool found = false;

	if(length == 0)
	{
		list[0] = item;
		length++
	}else if(length == maxSize)
	{

	}else
	{
		while(first <= last && !found)
		{
			mid = (first + last) / 2;
			if(list[mid] == item)
			{
				found = true;
			}else if(list[mid] > item)
			{
				last = mid - 1;
			}else
			{
				first = mid + 1;
			}

			if(found)
			{
				cout << "The item is already in the list!" <<endl;
			}else
			{
				if(list[mid] < item)
				{
					mid++;
					insertAt(mid, item);
				}

			}

		}
	}

}

//remove
template <class elemType>
bool sortedArrayList<elemType>::remove(const elemType& item)
{

}

//clearList
template <class elemType>
void sortedArrayList<elemType>::clearList()
{
	length = 0;
}

//destructor
template<class elemType>
inline sortedArrayList<elemType>::~sortedArrayList()
{
	delete[] list;
}

template <class elemType>
unsigned int sortedArrayList<elemType>::binSearchIter(const elemType& element)
{
	int first = 0;
	int last = length - 1;
	int mid;
	bool found = false;

	while(first <= last && !found)
	{
		mid = (first + last) / 2;
		if(list[mid] == element)
		{
			found = true;
		}else if(list[mid] > element)
		{
			last = mid - 1;
		}else
		{
			first = mid + 1;
		}

		if(found)
		{
			return mid;
		}else
		{
			return -1;
		}
	}


}

template <class elemType>
unsigned int sortedArrayList<elemType>::binSearchRec(const elemType& element)
{
	if(length <= 0)
		{

		}else{
			return ((list[element] && binSearchRec(element - 1)));
		}
}

