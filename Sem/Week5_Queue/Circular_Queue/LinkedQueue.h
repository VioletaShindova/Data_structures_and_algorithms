#pragma once

template <typename T>
class LinkedQueue
{
	struct Node
	{
		T data;
		Node* next;

		Node(const T& data)
		{
			this->data = data;
			this->next = nullptr;	
		}
	};

	Node* head;
	Node* tail;

	void copyFrom(const LinkedQueue& other);
	void free();
	
public:
	LinkedQueue() : head(nullptr), tail(nullptr) {}
	LinkedQueue(const LinkedQueue<T>& other);
	LinkedQueue<T>& operator=(const LinkedQueue<T>& other);
	~LinkedQueue();

	void enqueue(const T&);
	void dequeue();
	const T& peek() const;

	bool isEmpty() const;
};

template <typename T>
void LinkedQueue<T>::copyFrom(const LinkedQueue& other)
{
	Node* iter = other.head;
	while (iter->next)
	{
		enqueue(iter->data);
		iter = iter->next;
	}
}

template <typename T>
void LinkedQueue<T>::free()
{
	Node* iter = head;
		
	while (iter)
	{
		Node* toDelete = iter;
		iter = iter->next;
		delete toDelete;
	}

	head = tail = nullptr;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& other)
{
	copyFrom(other);
}

template <typename T>
LinkedQueue<T>&  LinkedQueue<T>::operator=(const LinkedQueue<T>& other)
{
	if (this != other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	free();
}

template <typename T>
void  LinkedQueue<T>::enqueue(const T& data)
{
	Node* toAdd = new Node(data);
	if (isEmpty())
	{
		head = tail = toAdd;
	}

	else
	{
		tail->next = toAdd;
		tail = toAdd;
	}
}

template <typename T>
void  LinkedQueue<T>::dequeue()
{
	if (isEmpty())
	{
		throw std::runtime_error("This list is empty!");
	}
	else if (head == tail)
	{
		T el = head->data;
		delete head;

		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* temp = head->next;
		delete head;

		head = temp;
	}
}

//return the front element without deleting it
template <typename T>
const T& LinkedQueue<T>::peek() const
{
	if (isEmpty())
	{
		throw std::runtime_error("This list is empty!");
	}

	return head->data;
}

template <typename T>
bool  LinkedQueue<T>::isEmpty() const
{
	return ((head == nullptr) && (tail == nullptr));
}