#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
	size_t size;
	T* items;
public:
	Vector() {
		this->size = 0;
		this->items = new T[this->size];
	}

	Vector(const initializer_list<T>& items) {
		this->size = items.size();

		this->items = new T[this->size];

		size_t i = 0;
		for (const T& item : items) {
			this->items[i] = item;
			i++;
		}
	}

	Vector(const Vector<T>& items) {
		this->size = items.size;
		this->items = new T[this->size];

		for (size_t i = 0; i < this->size; i++) {
			this->items[i] = items[i];
		}
	}

	Vector<T>& push(const T& item) {
		T* items = this->items;
		this->items = new T[this->size + 1];

		for (size_t i = 0; i < this->size; i++) {
			this->items[i] = items[i];
		}

		this->items[this->size++] = item;

		delete[] items;

		return *this;
	}

	Vector<T>& pop() {
		T* items = this->items;
		this->items = new T[--this->size];

		for (size_t i = 0; i < this->size; i++) {
			this->items[i] = items[i];
		}

		delete[] items;

		return *this;
	}

	size_t length() const noexcept {
		return this->size;
	}

	T& operator[](const size_t& index) {
		if (index >= this->size) {
			return this->items[this->size - 1];
		}

		return this->items[index];
	}
};