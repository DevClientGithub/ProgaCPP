#pragma once

#include <iostream>

using namespace std;

template <typename T, const size_t size>
class Array {
private:
	T data[size]; // Сам массив
public:
	static constexpr size_t noPosition = static_cast<size_t>(-1);

	Array(const initializer_list<T>& items) {
		if (items.size() > size) {
			throw runtime_error("Very more items");
		}

		size_t i = 0;
		for (const T& item : items) {
			this->data[i] = item;
			i++;
		}
	}

	Array() {
		this->fill();
	}

	Array(const Array& other) {
		if (other.length() > size) {
			throw runtime_error("Very more items");
		}

		for (size_t i = 0; i < other.length(); i++) {
			this->data[i] = other.data[i];
		}
	}

	// Длина массива
	size_t length() const {
		return size;
	}

	// Заполнить массив одним типом значения
	Array<T, size>& fill(const T& item = T()) {
		for (size_t i = 0; i < size; i++) {
			this->data[i] = item;
		}
	}

	// Ищет элемент, и возвраещет его индекс.
	size_t find(const T& item) const {
		for (size_t i = 0; i < size; i++) {
			if (this->data[i] == item) {
				return i;
			}
		}

		return this->noPosition;
	}

	bool includes(const T& item) const {
		for (size_t i = 0; i < size; i++) {
			if (this->data[i] == item) {
				return true;
			}
		}

		return false;
	}

	T& operator[](const size_t& index) {
		return this->data[index];
	}
};