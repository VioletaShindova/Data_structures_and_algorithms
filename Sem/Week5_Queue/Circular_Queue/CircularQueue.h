#ifndef QUEUE_HDR
#define QUEUE_HRD
	
#include <iostream>
using namespace std;

template <typename T>
class CircularQueue
{
private:
	T* data;
	size_t capacity;
	size_t count;

	size_t putIter;
	size_t getIter;

	void copyFrom(const CircularQueue<T>& other);
	void moveFrom(const CircularQueue<T>&& other);
	void resize();
	void free();

public:
	CircularQueue() : data(nullptr), capacity(1), count(1), putIter(0), getIter(0) {}
	CircularQueue(const CircularQueue<T>& other);
	CircularQueue(CircularQueue<T>&& other);

	CircularQueue<T>& operator=(const CircularQueue<T>& other);
	CircularQueue<T>& operator=(CircularQueue<T>&& other);
	~CircularQueue();

	bool isEmpty() const;
	void enqueue(const T& el);
	void dequeue();
	const T& peek();
};

template <typename T>
void CircularQueue<T>::copyFrom(const CircularQueue<T>& other)
{
	data = new T[other.capacity];

	for (size_t i = other.getIter; i != other.putIter; (i += 1) %= other.capacity)
	{
		data[i] = other.data[i];
	}
	capacity = other.capacity;
	count = other.count;

	putIter = other.putIter;
	getIter = other.getIter;
}

template <typename T>
void CircularQueue<T>::moveFrom(const CircularQueue<T>&& other)
{
	data = other.data;
	capacity = other.capacity;
	count = other.count;
	putIter = other.putIter;
	getIter = other.getIter;

	other.data = nullptr;
	other.capacity = 0;
	other.count = 0;
	other.putIter = 0;
	other.getIter = 0;
}

template <typename T>
void CircularQueue<T>::resize()
{
	size_t newCapacity = capacity * 2;
	size_t currentCapacity = capacity;
	
	T* temp = new T[newCapacity];

	for (size_t i = 0; i < currentCapacity; i++)
	{
		temp[i] = peek();
		dequeue();
	}

	getIter = 0;
	putIter = capacity;

	count = capacity;
	capacity = newCapacity;

	delete[] data;
	data = temp;
}

template <typename T>
void CircularQueue<T>::free()
{
	delete[] data;
	getIter = putIter = count = capacity = 0;
}

template <typename T>
CircularQueue<T>::CircularQueue(const CircularQueue<T>& other)
{
	copyFrom();
}

template <typename T>
CircularQueue<T>::CircularQueue(CircularQueue<T>&& other)
{
	moveFrom(std::move(other));
}

template <typename T>
CircularQueue<T>& CircularQueue<T>::operator=(const CircularQueue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
CircularQueue<T>& CircularQueue<T>::operator=(CircularQueue<T>&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
CircularQueue<T>::~CircularQueue()
{
	free();
}

template <typename T>
bool CircularQueue<T>::isEmpty() const
{
	return (!data || count == 0);
}

template <typename T>
void CircularQueue<T>::enqueue(const T& el)
{
	if (count == capacity)
	{
		resize();
	}

	data[putIter] = el;
	(++putIter) %= capacity;
	count++;
}

template <typename T>
void CircularQueue<T>::dequeue()
{
	if (count == 0)
	{
		throw std::logic_error("Can't remove an element from an empty queue!");
	}

	count--;
	(++getIter) %= capacity;
}

template <typename T>
const T& CircularQueue<T>::peek()
{
	if (isEmpty())
	{
		throw std::logic_error("Empty queue!");
	}

	count--;
	return data[getIter];
}

#endif //QUEUE_HDR
