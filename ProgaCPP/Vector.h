#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
	size_t size;
	T* items;
public:
	Vector() : size(), items(new T[this->size]) {}

	Vector(const size_t& length) : size(length), items(new T[this->size]) {}

	Vector(const initializer_list<T>& items) : size(items.size()), items(new T[this->size]) {
		size_t i = 0;
		for (const T& item : items) {
			this->items[i++] = item;
		}
	}

	Vector(const Vector<T>& items) : size(items.size), items(new T[this->size]) {
		for (size_t i = 0; i < this->size; i++) {
			this->items[i] = items.items[i];
		}
	}

	~Vector() {
		delete[] this->items;
	}

	// Добавить элемент в конец
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

	// Удалить элемент из конца
	Vector<T>& pop() {
		T* items = this->items;
		this->items = new T[--this->size];

		for (size_t i = 0; i < this->size; i++) {
			this->items[i] = items[i];
		}

		delete[] items;

		return *this;
	}

	// Добавить элемент в начало
	Vector<T>& unshift(const T& item) {
		T* items = this->items;
		this->items = new T[++this->size];

		this->items[0] = item;

		for (size_t i = 1; i < this->size; i++) {
			this->items[i] = items[i - 1];
		}

		delete[] items;

		return *this;
	}

	// Удалить элемент из начала
	Vector<T>& shift() {
		T* items = this->items;
		this->items = new T[this->size - 1];

		for (size_t i = 1; i < this->size; i++) {
			this->items[i] = items[i];
		}

		this->size--;
		delete[] items;

		return *this;
	}

	// Перевернуть массив
	Vector<T>& reverse() {
		for (size_t i = 0; i < this->size / 2; ++i) {
			T temp = this->items[i];

			this->items[i] = this->items[this->size - 1 - i];
			this->items[this->size - 1 - i] = temp;
		}

		return *this;
	}

	// Заполнить массив 1 значением
	Vector<T>& fill(const T& item) {
		for (size_t i = 0; i < this->size; i++) {
			this->items[i] = item;
		}

		return *this;
	}

	// Очистить массив
	void clear() {
		this->size = 0;
		this->~Vector();
	}

	// Проверка на: есть ли тот или иной элемент в массива
	bool inculdes(const T& item) const {
		for (size_t i = 0; i < this->size; i++) {
			if (this->items[i] == item) {
				return true;
			}
		}

		return false;
	}

	// Поиск индекса того или иного элемента
	size_t find(const T& item) const {
		for (size_t i = 0; i < this->size; i++) {
			if (this->items[i] == item) {
				return i;
			}
		}

		return -1; // При возврате оно не будет -1 А будет конч огромным числом
	}

	// Длина массива
	size_t length() const noexcept {
		return this->size;
	}

	T& operator[](const size_t& index) {
		return this->items[index]; // Плевать на проверку что: ВДРУГ ОНО УХОДИТ ЗА ГРАНИЦЫ
		// Разраб пусть сам чекает чтоб индекс не выходил за границы массива
	}

	Vector<T>& operator=(const Vector<T>& items) {
		this->~Vector();

		this->size = items.size;
		this->items = new T[this->size];

		for (size_t i = 0; i < items.size; i++) {
			this->items[i] = items.items[i];
		}

		return *this;
	}
};