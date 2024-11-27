#pragma once
#include <iostream>
	
template <typename T>
class SinglyLinkedList
{
private:
	struct Node 
	{
		T data;
		Node* next;

		Node(const T& data)
		{
			this->data = data;
			next = nullptr;
		}
	};

	Node* head = nullptr;
	Node* tail = nullptr;
	size_t size = 0;

public: 
	SinglyLinkedList() = default;
	SinglyLinkedList(const SinglyLinkedList<T>& other);
	SinglyLinkedList(SinglyLinkedList<T>&& other);
	SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>& other);
	SinglyLinkedList<T>& operator=(SinglyLinkedList<T>&& other);
	~SinglyLinkedList();

	//copy pushs
	void pushFront(const T& el);
	void pushBack(const T& el);

	//move pushs
	void pushFront(T&& el);
	void pushBack(T&& el);

	void popFront();

	const T& front() const;
	const T& back() const;

	T& front();
	T& back();

	size_t getSize() const;
	bool isEmpty() const;

	template<typename U>
	friend SinglyLinkedList<U> concat(SinglyLinkedList<U>& lhs, SinglyLinkedList<U>& rhs);

	void print() const;

	class SllIterator 
	{
		Node* currentELementPtr;

		friend class SinglyLinkedList;

	public:
		//typedef - псевдоним, чрез който не е нужно всеки път да използваме std::forward_iterator_tag, 
		//а само iterator_category
		typedef std::forward_iterator_tag iterator_category;

		//ако при подаването currentELementPtr има стойност, то тя се инициализира на this->currentELementPtr
		//ако няма стойност, автоматично се инициализира с nullptr
		SllIterator(const Node* currentELementPtr = nullptr) : currentELementPtr(currentELementPtr) {}

		Т& operator*()
		{
			return currentELementPtr->data;
		}

		T* operator->()
		{
			return &(currentELementPtr->data);
		}

		//++ prefix 
		SllIterator& operator++()
		{
			if (currentELementPtr)
			{
				currentELementPtr = currentELementPtr->next;
			}
			//*this return the current iterator
			return *this;
		}

		//postfix ++
		//(int) - за маркиране на оператора като постфиксна версия на инкремента
		SllIterator operator++(int)
		{
			SllIterator copy(*this);
			++(*this); //moving the iterator forwards
			return copy; //return the old value of the iterator
		}

		SllIterator& operator+=(size_t s)
		{
			while (s--)
			{
				++(*this);
			}

			return *this;
		}

		SllIterator operator+(int i) const
		{
			SllIterator res(*this);
			res += i;
			return result;
		}

		//we compare whether the two iterators point to the same place
		bool operator==(const SllIterator& rhs) const
		{
			return currentELementPtr == rhs.currentELementPtr;
		}

		//we compare two objects here
		bool operator!=(const SllIterator& rhs) const
		{
			return !(*this == rhs);
		}
	};

	class ConstSllIterator
	{
		Node* currentElementPtr;

		friend class SinglyLinkedList;

	public:

		typedef std::forward_iterator_tag iterator_category;

		//default constructor
		ConstSllIterator(Node* currentElementPtr = nullptr) : currentElementPtr(currentElementPtr) {}
		//copy constructor
		ConstSllIterator(const SinglyLinkedList& nonConstIter) : currentElementPtr(nonConstIter.currentElementPtr) {}

		const T& operator*() const
		{
			return currentElementPtr->data;
		}

		const T* operator->() const
		{
			return &currentElementPtr->data;
		}

		//prefix
		ConstSllIterator& operator++()
		{
			if (currentElementPtr)
			{
				currentElementPtr = currentElementPtr->next;
			}

			return (*this);
		}

		//suffix
		ConstSllIterator operator++(int)
		{
			ConstSllIterator copy(*this);
			++(*this);
			return copy;
		}

		ConstSllIterator& operator+=(size_t size)
		{
			while (size--)
			{
				++(*this);
			}
			return (*this);
		}

		ConstSllIterator operator+(int i)
		{
			ConstSllIterator res(*this);
			res += i;

			return res;
		}

		bool operator==(const ConstSllIterator& rhs) const
		{
			return currentElementPtr == rhs.currentElementPtr;
		}

		bool operator!=(const ConstSllIterator& rhs) const
		{
			return !((*this) == rhs);
		}
	};

	ConstSllIterator begin()
	{
		return SllIterator(head);
	}

	SllIterator end()
	{
		return SllIterator(nullptr);
	}

	//const iterator that points to the beginning
	ConstSllIterator cbegin()
	{
		return ConstSllIterator(head);
	}

	ConstSllIterator cend()
	{
		return ConstSllIterator(nullptr);
	}

	SllIterator insertAfter(const T& el, const ConstSllIterator& it);
	SllIterator removeAfter(const ConstSllIterator& it);

private:
	void copyFrom(const SinglyLinkedList<T>& other);
	void moveFrom(SinglyLinkedList<T>&& other);
	
	void free();
};

template <typename T>
void SinglyLinkedList<T>::pushFront(const T& el)
{
	Node* newNode = new Node(el);

	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}

	size++;
}

template <typename T>
void SinglyLinkedList<T>::pushBack(const T& el)
{
	Node* newNode = new Node(el);

	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	size++;
}

template <typename T>
void SinglyLinkedList<T>::pushFront(T&& el)
{
	Node* newNode = new Node(std::move(el));

	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}

	size++;
}

template <typename T>
void SinglyLinkedList<T>::pushBack(T&& el);

template <typename T>
void popFront()
{
	if (isEmpty())
	{
		throw std::logic_error("Empty list!");
	}

	if(head == tail)
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		Node* toDelete = head;
		head = head->next
	}
	size--;
}

template <typename T>
const T& SinglyLinkedList<T>::front() const
{
	if (!head)
	{
		throw std::logic_error("Empty list!");
	}

	return head->data;
}

template <typename T>
const T& SinglyLinkedList<T>::back() const
{
	if (!tail)
	{
		throw std::logic_error("Empty list!");
	}

	return tail->data;
}
template <typename T>
T& SinglyLinkedList<T>::front()
{
	if (!head)
	{
		throw std::logic_error("Empty list!");
	}

	return head->data;
}

template <typename T>
T& SinglyLinkedList<T>::back()
{
	if (!tail)
	{
		throw std::logic_error("Empty list!");
	}

	return tail->data;
}

template<typename T>
SinglyLinkedList<T> concat(SinglyLinkedList<T>& lhs, SinglyLinkedList<T>& rhs)
{
	SinglyLinkedList<T> result;

	if (!lhs.head)
	{
		result.head = rhs.head;
		result.tail = rhs.tail;
	}
	else if (!rhs.head)
	{
		result.head = lhs.head;
		result.tail = lhs.tail;
	}
	else
	{
		lhs.tail->next = rhs.head;
		result.head = lhs.head;
		result.tail = rhs.tail;
	}

	result.size = lhs.size + rhs.size;
	lhs.size = rhs.size = 0;
	rhs.head = rhs.tail = lhs.head = lhs.tail = nullptr;

	return result;
}

template <typename T>
typename SinglyLinkedList<T>::SllIterator SinglyLinkedList<T>::insertAfter(const T& el, const typename SinglyLinkedList<T>::ConstSllIterator& it)
{
	if (it == end())
	{
		return end();
	}

	Node* newNode = new Node(el);
	Node* itNode = it.currentElementPtr;
	
	newNode->next = itNode->next;
	itNode->next = newNode;

	size++;

	return SinglyLinkedList<T>::SllIterator(newNode);
}

template <typename T>
typename SinglyLinkedList<T>::SllIterator SinglyLinkedList<T>::removeAfter(const typename SinglyLinkedList<T>::ConstSllIterator& it)
{
	if (it == end() || getSize() == 1)
	{
		return end();
	}

	Node* toDelete = (it + 1).currentElementPtr;

	Node* newNext = toDelete->next;

	it.currentElementPtr->next = newNext;

	size--;

	if (toDelete == tail)
	{
		tail = it.currentElementPtr;
	}

	//unnecessary because after calling delete toDelete, the memory for the object that toDelete points to will be freed
	//toDelete->next = nullptr;
	delete toDelete;

	return SinglyLinkedList<T>::SllIterator(newNext);
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() const
{
	return getSize() == 0;
	//return (!head && !tail || size == 0);
}

template <typename T>
size_t SinglyLinkedList<T>::getSize() const
{
	return size;
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other)
{
	copyFrom(other);
}

//SinglyLinkedList<T>&& other is a temporary (rvalue) reference to an object that is used 
//for moving the data to the current object
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList<T>&& other)
{
	moveFrom(std::move(other));
}

//copy 
template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& other)
{
	if (this != &other)
	{
		//Това действие предотвратява изтичане на памет (memory leak), 
		//защото ако не се освободят старите ресурси, ще останат ненужни копия на заделената памет.
		free();
		copyFrom(other);
	}

	return *this;
}

template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(SinglyLinkedList<T>&& other)
{
	if (this != &other)
	{
		free();
		moreFrom(std::move(other));
	}

	return *this;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	free();
}

template <typename T>
void SinglyLinkedList<T>::copyFrom(const SinglyLinkedList<T>& other)
{
	Node* iter = other.head;

	while (iter)
	{
		pushBack(iter->data);
		iter = iter->next;
	}
}

template <typename T>
void SinglyLinkedList<T>::moveFrom(SinglyLinkedList<T>&& other)
{
	head = other.head;
	tail = other.tail;
	size = other.size;

	other.head = other.tail = nullptr;
	other.size = 0;
}

template <typename T>
void SinglyLinkedList<T>::free()
{
	Node* iter = head;

	while (iter)
	{
		Node* toDelete = iter;
		iter = iter->next;
		delete toDelete;
	}
	head = tail = nullptr;
	size = 0;
}

template <typename T>
void SinglyLinkedList<T>::print() const 
{
	Node* iter = head;

	while (iter)
	{
		std::cout << iter->data << ' ';

		if (iter->next)
		{
			std::cout << "->" << ' ';
		}

		iter = iter->next;
	}
	std::cout << std::endl;
}