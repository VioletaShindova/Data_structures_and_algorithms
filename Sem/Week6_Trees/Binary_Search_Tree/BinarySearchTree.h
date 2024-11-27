#pragma once
#include <vector>
#include <stack>
#include <iostream>
#include <functional>


template <class T, typename Compare = std::less<T>>
class BinarySearchTree
{
	struct Node 
	{
		T data;
		Node* left;
		Node* right;

		Node(const T& data, Node* left = nullptr, Node* right = nullptr) : data(data), left(left), right(right) {}
	};

	Node* root = nullptr;
	Compare comp; /// comparator instance
	size_t size = 0;

	Node* copyFrom(Node* current);
	Node** findMinNode(Node** root);
	void free(Node* current);

public:
	BinarySearchTree() = default;
	explicit BinarySearchTree(const Compare& comp) : comp(comp) {}

	//copy constructor
	BinarySearchTree(const BinarySearchTree<T, Compare>& other);

	BinarySearchTree<T, Compare>& operator=(const BinarySearchTree<T, Compare>& other);
	~BinarySearchTree();

	bool insert(const T& data);
	bool contains(const T& data) const;
	bool remove(const T& other);

	size_t getSize() const;
	bool isEmpty() const; 

	T& findMinEl();

	class ForwardIterator 
	{
		std::stack<Node*> nodeStack;

		void pushLeft(Node* node)
		{
			while (node)
			{
				nodeStack.push(node);
				node = node->left;
			}
		}

	public:
		ForwardIterator(Node* root = nullptr)
		{
			pushLeft(root);
		}

		T& operator*() const
		{
			return nodeStack.top()->data;
		}

		ForwardIterator& operator++()
		{
			Node* node = nodeStack.top();
			nodeStack.pop();
			if (node->right)
			{
				pushLeft(node->right);
			}

			return *this;
		}

		ForwardIterator operator++(int)
		{
			ForwardIterator old(*this);
			++(*this);
			return old;
		}

		bool operator==(const ForwardIterator& rhs) const
		{
			return (nodeStack == rhs.nodeStack);
		}

		bool operator!=(const ForwardIterator& other)
		{
			return (nodeStack != other.nodeStack);
		}
	};

	ForwardIterator begin() const
	{
		return ForwardIterator(root);
	}

	ForwardIterator end() const
	{
		return ForwardIterator(nullptr);
	}
};

template <class T, typename Compare>
typename BinarySearchTree<T, Compare>::Node* BinarySearchTree<T, Compare>::copyFrom(Node* current)
{
	if (!current)
		return nullptr;
	Node* newCopy = new Node(current->data);
	newCopy->left = copy(current->left);
	newCopy->right = copy(current->right);

	return newCopy;
}

template <class T, typename Compare>
typename BinarySearchTree<T, Compare>::Node** BinarySearchTree<T, Compare>::findMinNode(Node** root)
{
	if (!(*root))
	{
		return nullptr;
	}

	Node** 
}

template <class T, typename Compare>
void BinarySearchTree<T, Compare>::free(Node* current)
{
	if (!current)
	{
		return;
	}

	free(current->left);
	free(current->right);

	delete current;
}

template <class T, typename Compare>
BinarySearchTree<T, Compare>::BinarySearchTree(const BinarySearchTree<T, Compare>& other)
{
	copyFrom(other);
}

template <class T, typename Compare>
BinarySearchTree<T, Compare>& BinarySearchTree<T,Compare>::operator=(const BinarySearchTree<T, Compare>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return this;
}

template <class T, typename Compare>
BinarySearchTree<T, Compare>::~BinarySearchTree()
{
	free(root);
}

//write a RECURSIVE function
template <class T, typename Compare>
typename BinarySearchTree<T, Compare>::Node** BinarySearchTree<T, Compare>::findMinNode(Node** root)
{
	if (!root)
	{
		return nullptr;
	}

	Node** minNode = &root;

	while ((*minNode)->left)
	{
		minNode = &(*minNode)->left;
	}

	return minNode;
}

template <class T, typename Compare>
size_t BinarySearchTree<T, Compare>::getSize() const
{
	return size;
}

template <class T, typename Compare>
bool BinarySearchTree<T, Compare>::isEmpty() const
{
	return root == nullptr || size == 0;
}

template <class T, typename Compare>
bool BinarySearchTree<T,Compare>::insert(const T& data)
{
	if (!root)
	{
		Node* toAdd = new Node(data);
		root = toAdd;
		return true;
	}

	bool result = false;
	Node* current = root;

	while (!result)
	{
		if (data < current->data)
		{
			if(current->left)
			{
				current = current->left;
			}
			else
			{
				Node* toAdd = new Node(data);
				current->left = toAdd;
				current = toAdd;
			}
		}
		else if (data > current->data)
		{
			if (current->right)
			{
				current = current->right;
			}
			else
			{
				Node* toAdd = new Node(data);
				current->right = toAdd;
				current = toAdd;
			}
		}
		else
		{
			result = true;
		}
	}
	return result;
}

template <class T, typename Compare>
bool BinarySearchTree<T, Compare>::contains(const T& data) const
{

}

template <class T, typename Compare>
bool BinarySearchTree<T, Compare>::remove(const T& other)
{

}

template <class T, typename Compare>
T& BinarySearchTree<T, Compare>::findMinEl()
{
	if (!root)
	{
		return (int)T;
	}

	Node** temp = &root;
	Node** minNode = findMinNode(temp);
	return (*minNode)->data;
}
