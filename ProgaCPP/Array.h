#pragma once

#include <iostream>

using namespace std;

// ����� �������, ��������� 2 generic ��������. 1 - ��� ��� ���������. 2 - ������ �������.
template <typename T, const size_t size>
class Array {
private:
	T items[size]; // �������� ������ �������.
public:
	Array(initializer_list<T> items) {
		if (items.size() > size) {
			throw runtime_error("Very more items");
		}

		size_t i = 0;
		for (const T& item : items) {
			this->items[i] = item;
			i++;
		}
	}

	Array() {
		this->clear();
	}

	Array(const Array& other) {
		if (other.length() > size) {
			throw runtime_error("Very more items");
		}

		for (size_t i = 0; i < other.length(); i++) {
			this->items[i] = other.items[i];
		}
	}

	// ����� ������������ ������ �������.
	size_t length() const {
		return size;
	}

	// ����� ����������� ������ ������� ����������.
	void clear() {
		for (size_t i = 0; i < size; i++) {
			this->items[i] = T();
		}
	}

	Array<T, size>& fill(const T& item) {
		for (size_t i = 0; i < size; i++) {
			this->items[i] = item;
		}
	}

	T& operator[](const size_t& index) {
		if (index >= size) {
			return this->items[size - 1];
		}

		return this->items[index];
	}
};