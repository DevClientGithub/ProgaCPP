#pragma once

#include <iostream>

// ����� �������, ��������� 2 generic ��������. 1 - ��� ��� ���������. 2 - ������ �������.
template <typename T, const size_t size>
class Array {
private:
	T items[size]; // �������� ������ �������.
public:
	Array(std::initializer_list<T> items) {
		if (items.size() > size) {
			throw std::runtime_error("Error");
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
		if(other.length() > size) {
			throw std::runtime_error("Error");
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

	T& operator[](const size_t& index) {
		if (index >= size) {
			return this->items[size - 1];
		}

		return this->items[index];
	}
};