#ifndef VECTOR_HEADER
#define VECTOR_HEADER

#include "priorityQueue.hpp"

template<typename T>
class Vector
{
	int size;
	int capacity;
	bool sorted;
	T* arr;

public:
	Vector() : size(0), capacity(64), sorted(false) {}
	Vector(int newCapacity) : size(0), capacity(newCapacity + 1), sorted(false) {}
	Vector(const Vector&);
	Vector& operator=(const Vector&);
	~Vector();

private:
	void create();
	void resize();
	void copy();
	void clear();
	int binarySearch(int left, int right, T& key);

public:
	bool isEmpty() const; 
	bool isFull() const;
	int binarySearch(T& key) const;
	void sort();
	void insert(T toInsert);
	void remove(T toRemove);
	T pop();

};

template<typename T>
void Vector<T>::create()
{
	arr = new T[capacity];
}

template<typename T>
void Vector<T>::resize()
{
	T* newSet = new T[capacity *= 2];
	for (int i = 0; i < size; i++)
		newSet[i] = arr[i];
	delete[] arr;
	arr = newSet;
}

template<typename T>
void Vector<T>::copy()
{

}

template<typename T>
bool Vector<T>::isEmpty() const
{
	return !size;
}
template<typename T>
bool Vector<T>::isFull() const
{
	return size == capacity;
}

template<typename T>
void Vector<T>::insert(T toInsert)
{
	if (isFull()) resize();
	arr[size] = toInsert;
	size++;
}

template<typename T>
void Vector<T>::remove(T toRemove)
{
	int index = binarySearch(toRemove);
	if (index >= 0)
	{
		T temp = arr[index];
		for (; index < size - 2; index++)
		{
			arr[index] = arr[index + 1];
		}
		delete temp;
		size--;
	}
}

template<typename T>
T Vector<T>::pop(){
	T toPop = arr[size - 1];
	arr[--size] = NULL;
	return toPop;
}

template<typename T>
int Vector<T>::binarySearch(T& key) const
{
	return binarySearch(0, size - 1, key);
}

template<typename T>
int Vector<T>::binarySearch(int left, int right, T& key)
{
	if (left > right) return -1;
	
	int mid = (left + right) / 2;
	if (arr[mid] == key)
		return mid;
	
	if (arr[mid] < key)
		return binarySearch(left, mid, key);

	return binarySearch(mid, left, key);
}

void sort();

#endif//VECTOR_HEADER