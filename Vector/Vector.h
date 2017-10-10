#pragma once

#include <iostream>
#include <algorithm>
#include <new>

using namespace std;

namespace DSAA
{
	const int SPARE_CAPACITY = 100;

	template <typename Object>
	class Vector
	{
	public:
		// default constructor
		explicit Vector(int initSize = 0)
			: _size{ initSize }, _capacity{ initSize + SPARE_CAPACITY }
		{
			_objects = new Object[_capacity];
			
			std::cout << "In default constructor"<< std::endl;
		}

		// copy constructor
		Vector(const Vector& rhs)
			: _size(rhs._size), _capacity(rhs._capacity), _objects(nullptr)
		{
			_objects = new Object[_capacity];
			for (int k = 0; k < _size; ++k)
				_objects[k] = rhs._objects[k];

			std::cout << "In copy constructor" << std::endl;
		}

		// copy assignment
		Vector& operator= (const Vector& rhs)
		{
			Vector copy = rhs;
			std::swap(*this, copy);

			std::cout << "In copy assignment" << std::endl;

			return *this;
		}

		// move constructor
		Vector(Vector&& rhs)
			: _size(rhs._size), _capacity(rhs._capacity), _objects(rhs._objects)
		{
			rhs._size = 0;
			rhs._capacity = 0;
			rhs._objects = nullptr;

			std::cout << "In move constructor" << std::endl;
		}

		//move assignment
		Vector& operator= (Vector&& rhs)
		{
			_size = 0;
			_capacity = 0;
			delete _objects;

			this->_size = rhs._size;
			this->_capacity = rhs._capacity;
			this->_objects = rhs._objects;

			rhs._size = 0;
			rhs._capacity = 0;
			rhs._objects = nullptr;

			std::cout << "In move assignment" << std::endl;

			return *this;
		}

		void resize(int newSize)
		{
			if (newSize > theCapacity)
				reserve(newSize * 2);
			_size = newSize;
			
		}

		void reserve(int newCapacity)
		{
			if (newCapacity < _size)
				return;

			Object* newArray = new Object[newCapacity];
			for (int k = 0; k < _size; ++k)
				newArray[k] = std::move(object[k]);

			_capacity = newCapacity;
			std::swap(_objects, newArray);
			delete[] newArray;
		}

		int size() const
		{
			return _size;
		}

		int capacity() const
		{
			return _capacity;
		}

	private:
		int _size;
		int _capacity;
		Object* _objects;
	};

}