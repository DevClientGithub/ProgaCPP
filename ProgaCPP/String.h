#pragma once

#include <iostream>

using namespace std;

// Объект String - строка
class String {
private:
	size_t size; // Размер строки
	char* data; // Данные строки, её содержимое
	size_t* counter; // Счётчик копий

public:
	String(const char* string) : size(strlen(string)), data(new char[this->size + 1]), counter(new size_t()) {
		for (size_t i = 0; i < this->size; i++) {
			this->data[i] = string[i];
		}

		this->data[this->size] = '\0';
	}

	String(const char& symbol): size(1), data(new char(symbol)), counter(new size_t()) {}

	String(const String& string): size(string.size), data(string.data), counter(string.counter) {
		(*(this->counter))++;
	}

	String(): size(), data(nullptr), counter(nullptr) {}

	~String() {
		if (*(this->counter) == 0) {
			delete[] this->data;
			delete this->counter;
		}
		else if(*(this->counter) > 0) {
			(*(this->counter))--;
		}
	}

	// Получить длинну строки
	size_t length() const {
		return this->size;
	}

	// Привести строку к нижнему регистру
	String toLowerCase() const {
		char* data = new char[this->size + 1]; // Новая строка

		for (size_t i = 0; i < this->size; i++) {
			data[i] = tolower(this->data[i]);
		}

		data[this->size] = '\0';

		String result = data;
		delete[] data;

		return result;
	}

	// Привести строку к верхнему регистру
	String toUpperCase() const {
		char* data = new char[this->size + 1]; // Новая строка

		for (size_t i = 0; i < this->size; i++) {
			data[i] = toupper(this->data[i]);
		}

		data[this->size] = '\0';

		String result = data;
		delete[] data;

		return result;
	}

	// Перевернуть строчку
	String& reverse() {
		for (size_t i = 0; i < this->size / 2; i++) {
			swap(this->data[i], this->data[this->size - i - 1]);
		}

		return *this;
	}

	String* split(const char& delimiter) {}

	String* split(const char* delimiter) {}

	String* split(const String& delimiter) {}

	bool includes(const String& string) {}

	bool includes(const char* string) {}

	bool includes(const char& symbol) {}

	String& operator=(const char* string) {
		this->~String();

		this->size = strlen(string);
		this->data = new char[this->size + 1];
		this->counter = new size_t(0);

		for (size_t i = 0; i < this->size; i++) {
			this->data[i] = string[i];
		}

		this->data[this->size] = '\0';
		
		return *this;
	}

	String& operator=(const String& string) {
		this->~String();

		this->size = string.size;
		this->data = string.data;
		this->counter = string.counter;
		(*(this->counter))++;

		return *this;
	}

	String operator+(const String& string) {
		String result; // Результат - новая строчка

		char* data = new char[this->size + string.size + 1]; // Новые данные при конкатенации

		size_t i = 0;
		for (; i < this->size; i++) {
			data[i] = this->data[i];
		}

		for (size_t j = 0; j < string.size; j++) {
			data[i++] = string.data[j];
		}

		data[this->size + string.size] = '\0';
		
		result = data; // Результат - новая строчка
		delete[] data;

		return result;
	}

	String operator+(const char* string) {
		String result; // Результат - новая строчка

		const size_t stringSize = strlen(string); // Размер длины аргумента string
		char* data = new char[this->size + stringSize + 1]; // Новые данные при конкатенации

		size_t i = 0;
		for (; i < this->size; i++) {
			data[i] = this->data[i];
		}

		for (size_t j = 0; j < stringSize; j++) {
			data[i++] = string[j];
		}

		data[this->size + stringSize] = '\0';

		result = data; // Результат - новая строчка
		delete[] data;

		return result;
	}

	char operator[](const size_t& index) {
		if (index >= this->size) {
			throw runtime_error("U use very big index");
		}

		return this->data[index];
	}

	friend ostream& operator<<(ostream& stream, const String& string) {
		return stream << string.data;
	}
};