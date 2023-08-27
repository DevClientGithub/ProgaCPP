#pragma once

#include <iostream>

using namespace std;

template <typename T, const size_t size>
class Array {
private:
	T items[size]; // Сам массив
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

	// Длина массива
	size_t length() const {
		return size;
	}

	// Быстрая сортировка 1
	Array quickSortRecursive(T arr[size], int low, int high) {
		if (low < high) {
			T pivot = arr[(low + high) / 2];
			int i = low;
			int j = high;

			while (i <= j) {
				while (arr[i] < pivot)
					++i;
				while (arr[j] > pivot)
					--j;
				if (i <= j) {
					std::swap(arr[i], arr[j]);
					++i;
					--j;
				}
			}

			if (low < j)
				quickSortRecursive(arr, low, j);
			if (i < high)
				quickSortRecursive(arr, i, high);
		}

		Array result;
		std::copy(arr, arr + size, result.items);
		return result;
	}

	Array quickSort(T arr[size]) {
		Array result = quickSortRecursive(arr, 0, size - 1);
		return result;
	}

	// Пузырьковая сортировка
	void bubbleSort() {
		for (size_t i = 0; i < size - 1; ++i) {
			for (size_t j = 0; j < size - i - 1; ++j) {
				if (this->items[j] > this->items[j + 1]) {
					swap(this->items[j], this->items[j + 1]);
				}
			}
		}
	}

	// Заполнить массив стандартными значениями
	void clear() {
		for (size_t i = 0; i < size; i++) {
			this->items[i] = T();
		}
	}

	// Заполнить массив одним типом значения
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