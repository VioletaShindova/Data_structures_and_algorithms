//#pragma once
//#include <iostream>
//
//template <typename T>
//class DoublyLinkedList
//{
//private:
//	struct Node()
//	{
//		T data;
//		Node* next;
//		Node* prev;
//
//		Node(const T& data)
//		{
//			this->data = data;
//			next = prev = nullptr;
//		}
//	}
//
//	Node* head = nullptr;
//	Node* tail = nullptr;
//	size_t size = 0;
//
//	void copyFrom(const DoublyLinkedList<T>& other);
//	void moveFrom(DoublyLinkedList<T>&& other);
//	void free();
//
//public:
//	DoublyLinkedList() = default;
//	DoublyLinkedList(const DoublyLinkedList<T>& other);
//	DoublyLinkedList(DoublyLinkedList<T>&& other);
//	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);
//	DoublyLinkedList<T>& operator=(DoublyLinkedList<T>&& other);
//	~DoublyLinkedList();
//
//	//copy pushs
//	void pushFront(const T& el);
//	void pushBack(const T& el);
//
//	//move pushs
//	void pushFront(T&& el);
//	void pushBack(T&& el);
//
//	void popFront();
//	void popBack();
//
//	//get data
//	const T& front() const;
//	const T& back() const;
//
//	T& front();
//	T& back();
//
//	size_t getSize() const;
//	bool isEmpty() const;
//
//	void clear();
//	void print() const;
//
//	template <typename U>
//	friend DoublyLinkedList<U> concat(const DoublyLinkedList<U>& lhs, const DoublyLinkedList<U> rhs);
//
//	class DllIterator;
//	class ConstDllIterator;
//
//	DllIterator begin()
//	{
//		return DllIterator(head);
//	}
//
//	DllIterator end()
//	{
//		return DllIterator(nullptr); //tail->next = nullptr
//	}
//
//	ConstDllIterator cbegin()
//	{
//		return ConstDllIterator(head);
//	}
//
//	ConstDllIterator cend()
//	{
//		return ConstDllIterator(nullptr);
//	}
//
//	DllIterator insertAfter(const T& el, const ConstDllIterator& it);
//	DllIterator removeAfter(const DllIterator& it);
//
//	class DllIterator
//	{
//		friend class DoublyLinkedList;
//		Node* currentElementPtr;
//		DoublyLinkedList& list;
//
//	public:
//		typedef std::bidirectional_iterator_tag iterator_category;
//
//		DllIterator(const DoublyLinkedList& list, Node* currentElementPtr = nullptr) : list(list), currentElementPtr(currentElementPtr) {}
//		
//		
//		const T& operator*() const
//		{
//			return currentElementPtr->data;
//		}
//
//		const T* operator->() const
//		{
//			return &currentElementPtr->data;
//		}
//
//		//prefix 
//		DllIterator& operator++()
//		{
//			if (currentElementPtr)
//			{
//				currentElementPtr = currentElementPtr->next;
//			}
//			return *this;
//		}
//
//		//suffix
//		DllIterator operator++(int)
//		{
//			DllIterator copy(*this);
//			++(*this);
//			return copy;
//		}
//
//		DllIterator& operator--()
//		{
//			if (currentElementPtr)
//			{
//				currentElementPtr = currentElementPtr->prev;
//			}
//			else
//			{
//				currentElementPtr = list.tail;
//			}
//			return *this;
//		}
//
//		DllIterator operator--(int)
//		{
//			DllIterator copy(*this);
//			--(*this);
//			return copy;
//		}
//
//		DllIterator& operator+=(size_t s)
//		{
//			while (s--)
//			{
//				++(*this);
//			}
//
//			return *this;
//		}
//
//		DllIterator operator+(int s) const
//		{
//			DllIterator copy(*this);
//
//			return (copy += s);
//			
//		}
//
//		bool operator==(const DllIterator& rhs) const
//		{
//			return (currentElementPtr == rhs.currentElementPtr);
//		}
//
//		bool operator!=(const DllIterator& rhs) const
//		{
//			return !(*this == rhs);
//		}
//	};
//
//	class ConstDllIterator
//	{
//		friend class DoublyLinkedList;
//
//		Node* currentElementPtr;
//		const DoublyLinkedList& list;
//
//	public:
//
//		typedef std::bidirectional_iterator_tag iterator_category;
//
//		ConstDllIterator(const DoublyLinkedList& list, Node* currentElementPtr = nullptr) : this.list(list), currentElementPtr(currentElementPtr){}
//
//		const T& operator*() const
//		{
//			return currentElementPtr->data;
//		}
//
//		const T* operator->() const
//		{
//			return &currentElementPtr->data;
//		}
//
//		//prefix
//		ConstDllIterator& operator++()
//		{
//			if (currentElementPtr)
//			{
//				currentElementPtr = currentElementPtr->next;
//			}
//			else
//			{
//				currentElementPtr = list.tail; //nullptr
//			}
//
//			return *this;
//		}
//
//		//suffix
//		ConstDllIterator operator++(int)
//		{
//			ConstDllIterator copy(*this);
//			++(*this);
//
//			return copy;
//		}
//
//		ConstDllIterator& operator--()
//		{
//			if (currentElementPtr)
//			{
//				currentElementPtr = currentElementPtr->prev;
//			}
//			else
//			{
//				currentElementPtr = list.tail;
//			}
//
//			return *this;
//		}
//
//		ConstDllIterator operator--(int)
//		{
//			ConstDllIterator copy(*this);
//			--(*this);
//			return copy;
//		}
//
//		ConstDllIterator& operator+=(size_t s)
//		{
//			while (s--)
//			{
//				++(*this);
//			}
//			return *this;
//		}
//
//		ConstDllIterator operator+(int i) const
//		{
//			ConstDllIterator copy(*this);
//
//			return copy += i;
//		}
//
//		bool operator==(const ConstDllIterator& rhs)
//		{
//			return (currentElementPtr == rhs.currentElementPtr);
//		}
//
//		bool operator!=(const ConstDllIterator& rhs)
//		{
//			return !(*this == rhs);
//		}
//	};
//};
//
//template <typename T>
//bool DoublyLinkedList<T>::isEmpty() const
//{
//	return size == 0 || head == nullptr;
//}
//
//template <typename T>
//size_t DoublyLinkedList<T>::getSize() const
//{
//	return size;
//}
//
//template <typename T>
//void DoublyLinkedList<T>::pushFront(const T& el)
//{
//	Node* newNode = new Node(el);
//
//	if (isEmpty())
//	{
//		head = tail = newNode;
//	}
//	else
//	{
//		newNode->next = head;
//		head->prev = newNode;
//		newNode->prev = nullptr;
//		head = newNode;
//	}
//	size++;
//}
//
//template <typename T>
//void DoublyLinkedList<T>::pushBack(const T& el)
//{
//	Node* newNode = new Node(el);
//
//	if (isEmpty())
//	{
//		head = tail = newNode;
//	}
//	else
//	{
//		newNode->prev = tail;
//		tail->next = newNode;
//		newNode->next = nullptr;
//		tail = newNode;
//	}
//	size++;
//}
//
//template <typename T>
//void DoublyLinkedList<T>::popFront()
//{
//	if (isEmpty())
//	{
//		throw std::logic_error("Empty list!");
//	}
//	else
//	{
//		Node* toDelete = head;
//		toDelete->next = nullptr;
//		head = head->next;
//		head->prev = nullptr;
//		delete toDelete;
//	}
//	size--;
//}
//
//template <typename T>
//void DoublyLinkedList<T>::popBack()
//{
//	if (isEmpty())
//	{
//		throw std::logic_error("Empty list!");
//	}
//	else
//	{
//		Node* toDelete = tail;
//		tail->prev->next = nullptr;
//		tail = tail->prev;
//		delete toDelete;
//	}
//	size--;
//}
//
//template <typename T>
//const T& DoublyLinkedList<T>::front() const
//{
//	if (!head)
//	{
//		throw std::logic_error("Empty list!");
//	}
//
//	return head->data;
//}
//
//template <typename T>
//const T& DoublyLinkedList<T>::back() const
//{
//	if (!tail)
//	{
//		throw std::logic_error("Empty list!");
//	}
//
//	return tail->data;
//}
//
//template <typename T>
//T& DoublyLinkedList<T>::front()
//{
//	if (!head)
//	{
//		throw std::logic_error("Empty list!");
//	}
//
//	return head->data;
//}
//
//template <typename T>
//T& DoublyLinkedList<T>::back()
//{
//	if (!tail)
//	{
//		throw std::logic_error("Empty list!");
//	}
//
//	return tail->datap;
//}
//
//template <typename T>
//DoublyLinkedList<T> concat(DoublyLinkedList<T>& lhs, DoublyLinkedList<T> rhs)
//{
//	DoublyLinkedList<T> result;
//
//	if (!lhs.head)
//	{
//		result.head = rhs.head;
//		result.tail = rhs.tail;
//	}
//	else if (!rhs.head)
//	{
//		result.head = lhs.head;
//		result.tail = lhs.tail;
//	}
//	else
//	{
//		lhs.tail->next = rhs.head; //that way we connect the two lists
//		result.head = lhs.head;
//		result.tail = rhs.tail;
//	}
//
//	result.size = lhs.size + rhs.size;
//	rhs.size = lhs.size = 0;
//	rhs.tail = rhs.head = lhs.tail = lhs.head = nullptr;
//
//	return result;
//}
//
//template <typename T>
//void DoublyLinkedList<T>::free()
//{
//	Node* iter = head;
//
//	//to delete each node
//	while (iter)
//	{
//		Node* toDelete = iter;
//		delete toDelete;
//		iter = iter->next;
//	}
//
//	head = tail = nullptr;
//	size = 0;
//}
//
//template <typename T>
//void DoublyLinkedList<T>::clear()
//{
//	free();
//}
//
//template <typename T>
//void DoublyLinkedList<T>::print() const
//{
//	if (isEmpty())
//	{
//		throw std::logic_error("Empty list!");
//	}
//
//	Node* iter = head;
//	
//	while (iter)
//	{
//		std::cout << iter->data;
//
//		if (iter != tail)
//		{
//			std::cout << " -> ";
//		}
//		iter = iter->next;
//	}
//}
//
//template <typename T>
//typename DoublyLinkedList<T>::DllIterator DoublyLinkedList<T>::insertAfter(const T& el, const ConstDllIterator& it)
//{
//	if (!it.currentElementPtr)
//	{
//		throw std::logic_error("No element");
//	}
//	else if (it == cbegin())
//	{
//		pushFront(el);
//		return begin();
//	}
//	else if (it == cend())
//	{
//		pushBack(el);
//		return DllIterator(*this, tail)
//	}
//	else
//	{
//		Node* toAdd = new Node(el);
//		Node* nextNode = it.currentElementPtr->next;
//
//		nextNode->prev = toAdd;
//		toAdd->next = nextNode;
//		it.currentElementPtr->next = toAdd;
//		toAdd->prev = it;
//
//		size++;
//		return DllIterator(*this, toAdd);
//	}
//}
//
////--------------------------------------------------------------------------------------------------
//template <typename T>
//typename DoublyLinkedList<T>::DllIterator DoublyLinkedList<T>::removeAfter(const DllIterator& it)
//{
//	if (isEmpty())
//	{
//		throw std::logic_error("Empty list!");
//	}
//	else if (it == cbegin())
//	{
//
//	}
//}
//
//template <typename T>
//const T& DoublyLinkedList<T>::front() const
//{
//	if (isEmpty())
//	{
//		throw std::logic_error("Empty list!");
//	}
//
//	return head->data;
//}
//
//template <typename T>
//const T& DoublyLinkedList<T>::back() const
//{
//	if (isEmpty())
//	{
//		throw std::logic_error("Empty list!");
//	}
//
//	return tail->data;
//}
//
//template <typename T>
//T& DoublyLinkedList<T>::front()
//{
//	if (isEmpty())
//	{
//		throw std::logic_error("Empty list!");
//	}
//
//	return head->data;
//}
//
//template <typename T>
//T& DoublyLinkedList<T>::back()
//{
//	if (isEmpty())
//	{
//		throw std::logic_error("Empty list!");
//	}
//
//	return tail->data;
//}
//
//template <typename T>
//void DoublyLinkedList<T>::copyFrom(const DoublyLinkedList<T>& other)
//{
//	Node* otherIter = other.head;
//
//	while (otherIter != nullptr)
//	{
//		pushBack(otherIter->data);
//		otherIter = otherIter->next;
//	}
//}
//
//template <typename T>
//void DoublyLinkedList<T>::moveFrom(DoublyLinkedList<T>&& other)
//{
//	head = other.head;
//	tail = other.tail;
//	size = other.size;
//
//	other.head = other.tail = nullptr;
//	other.size = 0;
//}
//
//template <typename T>
//DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) : head(nullptr), tail(nullptr)
//{
//	copyFrom(other);
//}
//
//template <typename T>
//DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T>&& other)
//{
//	moveFrom(std::move(other));
//}
//
//template <typename T>
//DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
//{
//	if (this != &other)
//	{
//		free();
//		copyFrom(other);
//	}
//
//	return *this;
//}
//
//template <typename T>
//DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>&& other)
//{
//	if (this != &other)
//	{
//		free();
//		moveFrom(std::move(other));
//	}
//
//	return *this;
//}
//
//template <typename T>
//DoublyLinkedList<T>::~DoublyLinkedList()
//{
//	free();
//}
//	