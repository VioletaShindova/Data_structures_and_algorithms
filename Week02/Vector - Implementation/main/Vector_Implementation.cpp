// Vector_Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.hpp"
#include "Iterators.hpp"
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

struct Entity 
{
	int x;
	Entity() = default;
	explicit Entity(int x) : x{ x } {}
	~Entity() noexcept { x = -1; }

	friend bool operator==(const Entity& lhs, const Entity& rhs);
	friend bool operator!=(const Entity& lhs, const Entity& rhs);
};

bool operator==(const Entity& lhs, const Entity& rhs)
{
	return lhs.x == rhs.x;
}

bool operator!=(const Entity& lhs, const Entity& rhs)
{
	return !(lhs == rhs);
}

void test_Default()
{
	Vector<Entity> entities;

	entities.push_back(Entity(3));
	assert(entities.size() == 1);
	assert(entities.capacity() == 1);
	assert(entities.data() != nullptr);

	entities.push_back(Entity(4));
	entities.push_back(Entity(1));
	entities.push_back(Entity(5));

	Entity frontEl = entities.front();
	const Entity backEl = entities.back();

	using iterator = vector_iterator<Entity>;
	using const_iterator = const_vector_iterator<Entity>;

	iterator c_beg = entities.begin();
	const_iterator c_end = entities.c_end();

	const_iterator c_curr = c_beg + 2;

	assert(*c_curr == Entity(1));
}

int main()
{
	test_Default();
}
