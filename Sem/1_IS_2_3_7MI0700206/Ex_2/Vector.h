#pragma once

template <typename T = bool>
class Vector
{
	struct Node
	{
		T data;
		Node* next;

		Node(T& data = false) : data(data), next(nullptr) {}
	};

	Node* head = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copy(const Vector& data);
	void move(Vector&& data);
	void free();

	size_t calculate_capacity() const;
	size_t capacity() const;
	size_t size() const;

public:
	Vector() = default;
	Vector(const Vector& other);
	Vector(Vector&& other);

	Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other);
	~Vector();


	void push_back(const T& data);

	void pop_back();

	void Vector<T>::resize(size_t size);

	class VectorIterator;
	class ConstVectorIterator;
	class ReverseVectorIterator;

	VectorIterator begin() { return VectorIterator(head); }
	VectorIterator end() { return VectorIterator(nullptr); }
	ConstVectorIterator cbegin() const { return ConstVectorIterator(head); }
	ConstVectorIterator cend() const { return ConstVectorIterator(nullptr); }

	ReverseVectorIterator rbegin()
	{
		Node* current = head;
		if (!current)
		{
			return ReverseVectorIterator(nullptr);
		}

		while (current->next)
		{
			current = current->next;
		}

		return ReverseVectorIterator(current);
	}

	ReverseVectorIterator rend() { return ReverseVectorIterator(nullptr); }

	void insert(VectorIterator& it, const T& data);
	void insert(const ConstVectorIterator& it, const T& data);
	//void insert(ReverseVectorIterator& it, const T& data);

	void remove(VectorIterator& it);
	//void remove(const ConstVectorIterator& it);
	//remove(ReverseVectorIterator& it);

	void reserve(size_t size);

	void pop_front();

	class VectorIterator
	{
		friend class Vector;
		Node* currentElementPtr;

	public:
		typedef std::forward_iterator_tag iterator_category;

		VectorIterator(Node* currentElementPtr = nullptr) : currentElementPtr(currentElementPtr) {}

		T& operator*() const
		{
			return currentElementPtr->data;
		}

		T* operator->() const
		{
			return &currentElementPtr->data;
		}

		VectorIterator& operator++()
		{
			if (currentElementPtr)
			{
				currentElementPtr = currentElementPtr->next;
			}
			return *this;
		}

		VectorIterator operator++(int)
		{
			VectorIterator copy(*this);
			++(*this);
			return copy;
		}

		VectorIterator& operator--()
		{
			while (currentElementPtr->next)
			{
				currentElementPtr = currentElementPtr->next;
			}
			return currentElementPtr;
		}

		VectorIterator operator--(int)
		{
			VectorIterator copy(*this);
			--(*this);
			return copy;
		}

		VectorIterator operator[](size_t i)
		{
			if (!currentElementPtr || i >= size())
			{
				throw std::logic_error("Index out of range");
			}
			
			currentElementPtr = head;

			while (i-- && currentElementPtr->next)
			{
				currentElementPtr = currentElementPtr->next;
			}

			return &currentElementPtr->data;
		}

		bool operator==(const VectorIterator& other) const
		{
			return (currentElementPtr == other.currentElementPtr);
		}

		bool operator!=(const currentElementPtr) const
		{
			return !(*this == other);
		}
	};

	class ConstVectorIterator
	{
		friend class Vector;

		Node* currentElementPtr;

	public:
		typedef std::forward_iterator_tag iterator_category;

		ConstVectorIterator(Node* currentElementPtr = nullptr) : this->currentElementPtr(currentElementPtr) {}

		const T& operator*() const
		{
			return currentElementPtr->data;
		}

		const T* operator->() const
		{
			return &currentElementPtr->data;
		}

		ConstVectorIterator& operator++()
		{
			if (currentElementPtr)
			{
				return currentElementPtr = currentElementPtr->next;
			}
			return *this;
		}

		ConstVectorIterator operator++(int)
		{
			ConstVectorIterator copy(*this);
			++(*this);
			return copy;
		}

		ConstVectorIterator& operator--()
		{
			Node* current = head;
			while (current->next != currentElementPtr)
			{
				current = current->next;
			}

			return *this;
		}

		ConstVectorIterator operator--(int)
		{
			ConstVectorIterator copy(*this);
			--(*this);
			return copy;
		}

		ConstVectorIterator operator[]() const
		{

			if (!currentElementPtr || i >= size())
			{
				throw std::logic_error("Index out of range");
			}

			currentElementPtr = head;

			while (i-- && currentElementPtr->next)
			{
				currentElementPtr = currentElementPtr->next;
			}

			return &currentElementPtr->data;
		}

		bool operator==(const ConstVectorIterator& other) const
		{
			return (currentElementPtr == other.currentElementPtr);
		}

		bool operator!=(const ConstVectorIterator& other) const
		{
			return !(*this == other);
		}
	};
	
	class ReverseVectorIterator
	{
		friend class Vector;

		Node* currentElementPtr;

	public:
		typedef std::reverse_iterator iterator_category;

		ReverseVectorIterator(Node* currentElementPtr = nullptr) : this->currentElementPtr(currentElementPtr) {}

		const T& operator*() const
		{
			return currentElementPtr->data;
		}

		const T* operator->() const
		{
			return &currentElementPtr->data;
		}

		ReverseVectorIterator& operator++()
		{
			if (currentElementPtr)
			{
				return currentElementPtr = currentElementPtr->next;
			}
			return *this;
		}

		ReverseVectorIterator operator++(int)
		{
			ReverseVectorIterator copy(*this);
			++(*this);
			return copy;
		}

		ReverseVectorIterator& operator--()
		{
			Node* current = head;
			while (current->next != currentElementPtr)
			{
				current = current->next;
			}

			return *this;
		}

		ReverseVectorIterator operator--(int)
		{
			ReverseVectorIterator copy(*this);
			--(*this);
			return copy;
		}

		ReverseVectorIterator operator[]() const
		{

			if (!currentElementPtr || i >= size())
			{
				throw std::logic_error("Index out of range");
			}

			currentElementPtr = head;

			while (i-- && currentElementPtr->next)
			{
				currentElementPtr = currentElementPtr->next;
			}

			return &currentElementPtr->data;
		}

		bool operator==(const ReverseVectorIterator& other) const
		{
			return (currentElementPtr == other.currentElementPtr);
		}

		bool operator!=(const ReverseVectorIterator& other) const
		{
			return !(*this == other);
		}
	};

};

template <typename T>
void Vector<T>::copy(const Vector& data)
{
	free();
	Node* current = data.head;
	while (current)
	{
		push_back(current->data);
		current = current->next;
	}
	size = data.size;
	capacity = data.capacity;
}

template <typename T>
void Vector<T>::move(Vector&& data)
{
	free();
	head = data.head;
	size = data.size;
	capacity = data.capacity;

	head = nullptr;
	size = capacity = 0;
}

template <typename T>
void Vector<T>::free()
{
	Node* current = head;
	while (current)
	{
		Node* toDelete = current;
		current = current->next;
		delete toDelete;
	}

	head = nullptr;
	this->size = this->capacity = 0;
}

template <typename T>
size_t Vector<T>::calculate_capacity() const
{
	if (capacity() == 0)
		return 1;
	return capacity() * Constants::GROWTH_FACTOR;

}

template <typename T>
size_t Vector<T>::capacity() const
{
	return this->capacity;
}

template <typename T>
size_t Vector<T>::size() const
{
	return this->size;
}

template <typename T>
Vector<T>::Vector(const Vector& other)
{
	copy(other);
}

template <typename T>
Vector<T>::Vector(Vector&& other)
{
	move(std::move(other));
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
	if (this != other)
	{
		free();
		copy(other);
	}

	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other)
{
	if (this != other)
	{
		move(std::move(other));
	}

	return *this;
}

template <typename T>
Vector<T>::~Vector()
{
	free();
}

//добавя елемент в края на вектора.
template <typename T>
void Vector<T>::push_back(const T& data)
{
	Node* toAdd = newNode(data);
	if (!head)
	{
		head = toAdd;
	}
	else
	{
		Node* current = head;
		while (current->next)
		{
			current = current->next;
		}

		current->next = toAdd;
	}
	
	size++;
	capacity--;
}

//премахва последния елемент във вектора.
template <typename T>
void Vector<T>::pop_back()
{
	if (!head)
	{
		throw std::logic_error("Empty vector!");
	}

	Node* current = head;
	while (current->next)
	{
		current = current->next;
	}
	delete current;

	size--;
	capacity++;
}

template <typename T>
void Vector<T>::resize(size_t size)
{
	if (size < (this->size))
	{
		Node* current = head;
		size_t count = 1;

		while ((count < size) && current->next)
		{
			current = current->next;
			count++;
		}

		Node* toDelete = current->next;
		current->next = nullptr;
		while (toDelete)
		{
			Node* next = toDelete->next;
			delete toDelete;
			toDelete = next;
		}

		this->size = size;
	}
	else if (size > (this->size))
	{
		Node* current = head;

		if (!current)
		{
			head = new Node();
			current = head;
			this->size = 1;
		}

		while (current->next)
		{
			current = current->next;
		}

		for (size_t i = (this->size); i < size; i++)
		{
			current->next = new Node();
			current = current->next;
		}

		this->size = size;
	}

	capacity = std::max(capacity, size);
}

template <typename T>
void Vector<T>::insert(VectorIterator& it, const T& data)
{
	Node* toAdd = new Node(data);
	if (!head)
	{
		head = toAdd;
	}

	if (!it->next)
	{
		resize((size_t)(this->size) + 1);
	}

	Node* current = head;
	while (current != it)
	{
		if (current->next == it)
		{
			toAdd->next = current->next->next;
			it->next = toAdd;
			size++;
			capacity--;
			return;
		}
		current = current->next;
	}
	return;
}


//добавя елемент на позицията, посочена от итератора.
template <typename T>
void Vector<T>::insert(const ConstVectorIterator& it, const T& data)
{
	Node* toAdd = new Node(data);
	if (!head)
	{
		head = toAdd;
	}

	if (!it->next)
	{
		resize((size_t)(this->size) + 1);
	}

	Node* current = head;
	while (current != it)
	{
		if (current->next == it)
		{
			toAdd->next = current->next->next;
			it->next = toAdd;
			size++;
			capacity--;
			return;
		}
		current = current->next;
	}
	return;
}

template <typename T>
void Vector<T>::reserve(size_t size)
{
	if (size <= capacity)
	{
		return;
	}

	size_t additionalNodes = n - capacity;
	Node* current = head;

	if (!current)
	{
		head = new Node();
		current = head;
		additionalNodes--;
		this->size = 0;
	}

	while (current->next)
	{
		current = current->next;
	}

	for (size_t i = 0; i < additionalNodes; i++)
	{
		current->next = new Node();
		current = current->next;
	}

	capacity = size; 
}

//премахва елемент от позицията, посочена от итератора.
template <typename T>
void Vector<T>::remove(VectorIterator& it)
{
	if (!head)
	{
		throw std::logic_error("Empty vector!");
	}

=
	Node* current = head;
	while (current != it)
	{
		if (current->next == it)
		{
			current->next = current->next->next;
			delete current->next;
				
			return;
		}
		current = current->next;
	}
	resize((size_t)(this->size) - 1);
}

//премахва първия елемент във вектора.
template <typename T>
void Vector<T>::pop_front()
{
	if (!head)
	{
		throw std::logic_error("Empty vector!");
	}

	Node* current = head;
	if (size == 1)
	{
		head = nullptr;
	}
	else
	{
		head = current->next;
	}

	delete current;
	size--;
	capacity++;
}