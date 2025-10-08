#pragma once

#ifndef __VECTOR_HEADER_INCLUDED_

#define __VECTOR_HEADER_INCLUDED_

#include <memory>
#include <stdexcept>
#include "Iterators.hpp"

namespace GlobalConstants {
	constexpr size_t GROWTH_FACTOR = 2;
}

template<typename T, class Allocator = std::allocator<T>>
class Vector {
public:
	using iterator = vector_iterator<T>; // <=> typedef vector_iterator<T> iterator
	using const_iterator = const_vector_iterator<T>;
	using reverse_iterator = reversed_vector_iterator<T>;

	Vector() = default;

	explicit Vector(size_t size) : _data(_alloc.allocate(size)), _size(size), _capacity(size) 
	{
		//calls def ctors for all elements
		for (size_t i = 0; i < size; i++)
			_alloc.construct(&_data[i]);
	}

	// Constructs the container with count copies of elements with value initial.
	Vector(size_t size, const T& initial) : _data(_alloc.allocate(size)), _size(size), _capacity(size) 
	{
		for (size_t i = 0; i < size; i++)
			_alloc.construct(&_data[i], initial);
	}

	Vector(const Vector<T, Allocator>& other) : _alloc(other._alloc), _size(other._size), _capacity(other._capacity) { copyDynamic(other); }

	Vector& operator=(const Vector<T, Allocator>& other)
	{
		if (this != &other)
		{
			_alloc = other._alloc; 
			_size = other._size; 
			_capacity = other._capacity;
			freeDynamic();
			copyDynamic(other);
		}
		return *this;
	}

	~Vector() noexcept { freeDynamic(); }

	inline size_t size() const noexcept { return _size; }
	inline size_t capacity() const noexcept { return _capacity; }

	void push_back(const T& el);
	void pop_back();

	void resize(size_t newSize);
	void reserve(size_t newCapacity);
	void shrink_to_fit();

	T* data();

	inline bool empty() const { return _size == 0; }

	T& operator[](int idx);
	const T& operator[](int idx) const;

	void erase(const_iterator position); //better to pass the value by copy because it is not that expensive
	void erase(const_iterator first, const_iterator last);

	void clear();

	template<class... Args> //take as much count of arguments as you want and place them in package called Args
	void emplace_back(Args&&... args);

	iterator begin()
	{
		return iterator(_data);
	}

	iterator end()
	{
		return iterator(&_data[_size]);
	}

	const_iterator c_begin() const
	{
		return const_iterator(_data);
	}

	const_iterator c_end() const
	{
		return const_iterator(&_data[_size]);
	}

	reverse_iterator rbegin()
	{
		return (_size > 0) ? reverse_iterator(&_data[_size - 1]) : reverse_iterator(nullptr);
	}

	reverse_iterator rend()
	{
		return (_size > 0) ? reverse_iterator(_data - 1) : reverse_iterator(nullptr);
	}

	T& front()
	{
		return _data[0];
	}

	const T& front() const
	{
		return _data[0];
	}

	T& back()
	{
		return _data[_size - 1];
	}

	const T& back() const
	{
		return _data[_size - 1];
	}
private:
	void freeDynamic();
	void copyDynamic(const Vector<T, Allocator>& other);

	size_t calculate_capacity() const
	{
		if (_capacity == 0)
			return 1;

		return _capacity * GlobalConstants::GROWTH_FACTOR;
	}

	Allocator _alloc = {};

	T* _data = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;
};

template<typename T, class Allocator>
void Vector<T, Allocator>::push_back(const T& el) //can remove the 'inline' part
{
	if (size() == capacity())
		reserve(calculate_capacity());

	_alloc.construct(&_data[_size++], el);
}

template <typename T, class Allocator>
void Vector<T, Allocator>::pop_back()
{
	if (_size == 0)
		return;

	_alloc.destroy(&_data[_size - 1]);
	_size--;
}

template<typename T, class Allocator>
void Vector<T, Allocator>::resize(size_t newSize)
{
	if (newSize < _size)
	{
		for (size_t i = newSize; i < _size; i++)
			_alloc.destroy(&_data[i]);
		_size = newSize;
	}
	else if (newSize > _size)
	{
		if (newSize <= _capacity)
		{
			for (size_t i = _size; i < newSize; i++)
				_alloc.construct(&_data[i]);

			_size = newSize;
		}
		else
		{
			T* new_data = _alloc.allocate(newSize);

			for (size_t i = 0; i < _size; i++)
				_alloc.construct(&new_data[i], std::move(_data[i]));

			for (size_t i = _size; i < newSize; i++)
				_alloc.construct(&new_data[i]);

			_alloc.deallocate(_data, _capacity);

			_data = new_data;
			_capacity = newSize;
			_size = newSize;
		}
	}
}

// Increase the capacity of the vector (the total number 
// of elements that the vector can hold without requiring reallocation) 
// to a value that's greater or equal to `n`. If `n` is greater than
// the current capacity(), new storage is allocated, otherwise the function does nothing. 
template<typename T, class Allocator>
void Vector<T, Allocator>::reserve(size_t newCapacity)
{
	if (newCapacity <= capacity())
		return;

	T* temp = _alloc.allocate(newCapacity);

	for (size_t i = 0; i < _size; i++)
		_alloc.construct(&temp[i], _data[i]);

	_alloc.deallocate(_data, _capacity);

	_data = temp;
	_capacity = newCapacity;
}

// Requests the container to reduce its capacity to fit its size.
// This may cause a reallocation, but has no effect on the vector size and cannot alter its elements.
template<typename T, class Allocator>
void Vector<T, Allocator>::shrink_to_fit()
{
	if (_size != _capacity)
	{
		T* temp = _alloc.allocate(_size);

		for (size_t i = 0; i < _size; i++)
			_alloc.construct(&temp[i], _data[i]);

		_alloc.deallocate(_data, _capacity);
		_data = temp;
		_capacity = _size;
	}
}

template <typename T, class Allocator>
T* Vector<T, Allocator>::data()
{
	return _data;
}

template<typename T, class Allocator>
T& Vector<T, Allocator>::operator[](int idx)
{
	if (idx < 0 || idx >= _size)
		throw std::invalid_argument("Invalid index\n");

	return _data[idx];
}

template<typename T, class Allocator>
const T& Vector<T, Allocator>::operator[](int idx) const
{
	if (idx < 0 || idx >= _size)
		throw std::invalid_argument("Invalid index\n");

	return _data[idx];
}

template<typename T, class Allocator>
void Vector<T, Allocator>::erase(const_iterator position)
{
	erase(position, position + 1);
}

// Erases the specified range from the container.
template<typename T, class Allocator>
void Vector<T, Allocator>::erase(const_iterator first, const_iterator last)
{
	int deleted_count = last - first;

	if (deleted_count <= 0)
		return;

	int begin_offset = first - c_begin();
	int end_offset = last - c_begin();

	if (last != c_end())
	{
		size_t construct_idx = begin_offset;
		for (size_t i = end_offset; i < size(); i++)
		{
			_data[construct_idx] = std::move(_data[i]); //since i don't have move op=, it will be called copy op=
			++construct_idx;
		}
	}

	for (size_t i = size() - deleted_count; i < size(); i++)
		_alloc.destroy(&_data[i]);

	_size -= deleted_count;
}

template<typename T, class Allocator>
void Vector<T, Allocator>::clear()
{
	for (size_t i = 0; i < size(); i++)
		_alloc.destroy(&_data[i]);

	_size = 0;
}

template<typename T, class Allocator>
void Vector<T, Allocator>::freeDynamic()
{
	for (size_t i = 0; i < _size; i++)
		_alloc.destroy(&_data[i]);
	_alloc.deallocate(_data, _capacity);
	_data = nullptr;
}

template<typename T, class Allocator>
void Vector<T, Allocator>::copyDynamic(const Vector<T, Allocator>& other)
{
	_data = _alloc.allocate(other._capacity);

	for (size_t i = 0; i < other._size; i++)
		_alloc.construct(&_data[i], other._data[i]);
}

// Appends a new element to the end of the container. 
// The element is constructed through placement-new in-place.
template<typename T, class Allocator>
template<class ...Args>
inline void Vector<T, Allocator>::emplace_back(Args && ...args)
{
	if (size() == capacity())
		reserve(calculate_capacity());

	_alloc.construct(&_data[_size++], std::forward<Args>(args)...); //treat the argument like rvalue if it's a rvalue and call move assignment op
																	//if it has one or just treat it like an lvalue and call copy assignment op
}

#endif //__VECTOR_HEADER_INCLUDED_
