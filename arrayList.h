/*
 * arrayList.h
 *
 *  Created on: Mar 26, 2019
 *      Author: smohammed730
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include <iostream>
using namespace std;

template <class elemType>
class ArrayList{
public:
	ArrayList(const unsigned int=10, const double=0.5);
	bool isEmpty() const;
	bool isFull() const;
	unsigned int listSize() const;
	unsigned int maxListSize() const;
	void print() const;
	bool isItemAtEqual(const unsigned int, const elemType &) const;
	void insertAt(const unsigned int, const elemType &);
	void insertEnd(const elemType&);
	void removeAt(const unsigned int);
	elemType retreiveAt(const unsigned int) const;
	void replaceAt(const unsigned int, const elemType &);
	void clearList();
	ArrayList &operator=(const ArrayList &);
	virtual ~ArrayList();
	unsigned int seqSearchIter(const elemType& element);
	unsigned int seqSearchRec(const elemType& element);
private:
	void grow();
	unsigned int size;
	unsigned int maxSize;
	double factor;
	elemType* array;
};



template<class elemType>
ArrayList<elemType>::ArrayList(const unsigned int maxSize, const double factor) {
	if(factor <= 0.0){
		cout << "Growth factor must be greater than 0." << endl;
	}
	this->maxSize = maxSize;
	this->size = 0;
	this->factor = factor;
	this->array = new elemType[maxSize];
}

template<class elemType>
void ArrayList<elemType>::grow() {
	unsigned int newMaxSize = this->maxSize * (1.0 + this->factor);
	if(newMaxSize == this->maxSize){
		// Must grow by at least 1
		newMaxSize += 1;
	}
	elemType* tmp = new elemType[newMaxSize];
	for(unsigned int i=0; i < this->size; ++i){
		tmp[i] = this->array[i];
	}
	delete[] this->array;
	this->array = tmp;
	this->maxSize = newMaxSize;
}

//This function is O(1)
template<class elemType>
bool ArrayList<elemType>::isEmpty() const {
	 return this->size == 0;
}

//This function is O(1)
template<class elemType>
bool ArrayList<elemType>::isFull() const {
	return this->size == this->maxSize;
}

//This function is O(1)
template<class elemType>
unsigned int ArrayList<elemType>::listSize() const {
	return this->size;
}

//This function is O(1)
template<class elemType>
unsigned int ArrayList<elemType>::maxListSize() const {
	return this->maxSize;
}

//This function is O(n)
template<class elemType>
void ArrayList<elemType>::print() const {
	for(unsigned int i = 0; i < this->size; i++){
		cout << this->array[i] << ", ";
	}
	cout << endl;
}

//This function is O(1)
template<class elemType>
bool ArrayList<elemType>::isItemAtEqual(const unsigned int position, const elemType &element) const {
	if(position >= this->size){
		cout << "Position is out of bounds." << endl;
	}
	return element == this->array[position];
}

//This function is O(n)
template<class elemType>
void ArrayList<elemType>::insertAt(const unsigned int position, const elemType &element) {
	if(position > this->size){
		cout << "Position is out of bounds." << endl;
	}
	if (this->isFull()){
		unsigned int newMaxSize = this->maxSize * (1.0 + this->factor);
		if(newMaxSize == this->maxSize){
			newMaxSize += 1;
		}
		elemType* tmp = new elemType[newMaxSize];
		for(unsigned int i=0; i < position; ++i){
			tmp[i] = this->array[i];
		}
		this->array[position] = element;
		for(unsigned int i=position; i < this->size; ++i){
			tmp[i+1] = this->array[i];
		}
		delete[] this->array;
		this->array = tmp;
		this->maxSize = newMaxSize;
		this->size++;
		return;
	}
	for(int i=this->size; i > (int)position; i--){
		this->array[i] = this->array[i-1];
	}
	this->array[position] = element;
	this->size++;
}

//This function is O(1)
template<class elemType>
void ArrayList<elemType>::insertEnd(const elemType &element) {
	if (this->isFull()){
		this->grow();
	}
	this->array[this->size++] = element;
}

//This function is O(n)
template<class elemType>
void ArrayList<elemType>::removeAt(const unsigned int position) {
	if(position >= this->size){
		cout << "Position is out of bounds." << endl;
	}
	for(unsigned int i=position; i < this->size-1; i++){
		this->array[i] = this->array[i+1];
	}
	this->size--;
}

//This function is O(1)
template<class elemType>
elemType ArrayList<elemType>::retreiveAt(const unsigned int position) const {
	if(position >= this->size){
		cout << "Position is out of bounds." << endl;
	}
	return this->array[position];
}

//This function is O(1)
template<class elemType>
void ArrayList<elemType>::replaceAt(const unsigned int position, const elemType &element) {
	if(position >= this->size){
		cout<< "Position is out of bounds." <<endl;
	}
	this->array[position] = element;
}

//This function is O(1)
template<class elemType>
void ArrayList<elemType>::clearList() {
	size = 0;
}

//This function is O(n)
template<class elemType>
ArrayList<elemType>& ArrayList<elemType>::operator =(const ArrayList<elemType>& rhs) {
	if (rhs.size > this->maxSize){
		this->maxSize = rhs.maxSize;
		delete[] this->array;
		this->array = new elemType[this->maxSize];
	}
	for(unsigned int i = 0; i < rhs.size; i++){
		this->array[i] = rhs.array[i];
	}
	this->size = rhs.size;
	this->factor = rhs.factor;
	return *this;
}

//This function is O(1)
template<class elemType>
inline ArrayList<elemType>::~ArrayList() {
	delete[] this->array;
}

template <class elemType>
unsigned int ArrayList<elemType>::seqSearchIter(const elemType& element)
{
	for(int i = 0; i < maxSize; i++)
	{
		if(array[i] == element)
		{
			return *array[i];
		}
		else
		{
			cout << "No element in the array matches your search!" << endl;
		}
	}
}

template <class elemType>
unsigned int ArrayList<elemType>::seqSearchRec(const elemType& element)
{
	if(size <= 0)
	{

	}else{
		return ((array[element] && seqSearchRec(element - 1)));
	}
}

#endif /* ARRAYLISTT_H_ */

