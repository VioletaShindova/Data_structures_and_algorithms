#pragma once

#ifndef __ITERATOR_HEADER_INCLUDED_

#define __ITERATOR_HEADER_INCLUDED_

template<typename T>
class const_vector_iterator {
public:
	explicit const_vector_iterator(T* memPointer) : memPointer{ memPointer } {}
	const_vector_iterator(T* memPointer, size_t push) : memPointer{ memPointer + push } {}

	const T* operator->() const noexcept { return memPointer; }
	const T& operator*() const noexcept { return *(memPointer); }

	const_vector_iterator operator+(int offSet) const
	{
		return { memPointer + offSet };
	}

	const_vector_iterator operator-(int offSet) const
	{
		return { memPointer - offSet };
	}

	int operator-(const const_vector_iterator& other) const 
	{
		return memPointer - other.memPointer;
	}

	friend bool operator==(const const_vector_iterator& lhs, const const_vector_iterator& rhs);
	friend bool operator!=(const const_vector_iterator& lhs, const const_vector_iterator& rhs);

private:
	const T* memPointer;
};

template<typename T>
bool operator==(const const_vector_iterator<T>& lhs, const const_vector_iterator<T>& rhs)
{
	return lhs.memPointer == rhs.memPointer;
}

template<typename T>
bool operator!=(const const_vector_iterator<T>& lhs, const const_vector_iterator<T>& rhs)
{
	return !(lhs == rhs);
}

//--------------------------------------------------------------------------------------------------------

template<typename T>
class vector_iterator {
public:
	vector_iterator(T* memPtr) : memPointer{ memPtr } {}
	vector_iterator(T* memPtr, size_t push) : memPointer{ memPtr + push } {}

	vector_iterator& operator++()
	{
		memPointer++;
		return *this;
	}

	vector_iterator operator++(int)
	{
		vector_iterator temp(*this);
		++(*this);
		return temp;
	}

	vector_iterator& operator--()
	{
		memPointer--;
		return *this;
	}

	vector_iterator operator--(int)
	{
		vector_iterator temp(*this);
		--(*this);
		return temp;
	}

	T* operator->() noexcept { return memPointer; }
	const T* operator->() const noexcept { return memPointer; }

	T& operator*() noexcept { return *(memPointer); }

	friend bool operator==(const vector_iterator& lhs, const vector_iterator& rhs);
	friend bool operator!=(const vector_iterator& lhs, const vector_iterator& rhs);

	vector_iterator& operator+=(int offSet)
	{
		memPointer += offSet;
		return *this;
	}

	vector_iterator& operator-=(int offSet)
	{
		memPointer -= offSet;
		return *this;
	}

	//because of this line the class const_vector_iterator must be defined before vector_iterator
	operator const_vector_iterator<T>() const noexcept { return const_vector_iterator<T>(memPointer); } //implicit casting

private:
	T* memPointer;
};

template<typename T>
bool operator==(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
{
	return lhs.memPointer == rhs.memPointer;
}

template<typename T>
bool operator!=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs)
{
	return !(lhs == rhs);
}

template<typename T>
vector_iterator<T> operator+(const vector_iterator<T>& lhs, int offPosition)
{
	vector_iterator<T> temp(lhs);
	temp += offPosition;
	return temp;
}

template<typename T>
vector_iterator<T> operator-(const vector_iterator<T>& lhs, int offPosition)
{
	vector_iterator<T> temp(lhs);
	temp -= offPosition;
	return temp;
}

//-------------------------------------------------------------------------------------------

template<typename T>
class reversed_vector_iterator {
public:
	reversed_vector_iterator(T* memPtr) : memPointer{ memPtr } {}
	reversed_vector_iterator(T* memPtr, size_t push) : memPointer{ memPtr + push } {}
	
	reversed_vector_iterator& operator++()
	{
		memPointer--;
		return *this;
	}

	reversed_vector_iterator operator++(int)
	{
		reversed_vector_iterator temp(*this);
		++(*this);
		return temp;
	}

	reversed_vector_iterator& operator--()
	{
		memPointer++;
		return *this;
	}

	reversed_vector_iterator operator--(int)
	{
		reversed_vector_iterator temp(*this);
		--(*this);
		return temp;
	}

	reversed_vector_iterator operator+(int offSet)
	{
		return { memPointer - offSet };
	}

	reversed_vector_iterator operator-(int offSet)
	{
		return { memPointer + offSet };
	}

	T* operator->() noexcept { return memPointer; }
	const T* operator->() const noexcept { return memPointer; }

	T& operator*() noexcept { return *(memPointer); }

	friend bool operator==(const reversed_vector_iterator& lhs, const reversed_vector_iterator& rhs);
	friend bool operator!=(const reversed_vector_iterator& lhs, const reversed_vector_iterator& rhs);
private:
	T* memPointer;
};

template<typename T>
bool operator==(const reversed_vector_iterator<T>& lhs, const reversed_vector_iterator<T>& rhs)
{
	return lhs.memPointer == rhs.memPointer;
}

template<typename T>
bool operator!=(const reversed_vector_iterator<T>& lhs, const reversed_vector_iterator<T>& rhs)
{
	return !(lhs == rhs);
}

#endif