#pragma once

#include <iostream>

// Объект String - строка
class String {
private:
	size_t size; // Размер строки
	char* data; // Данные строки, её содержимое

	size_t* counter = new size_t(0); // Счётчик копий
public:
	String(const char* string) : size(strlen(string)), data(new char[this->size + 1]) {
		for (size_t i = 0; i < this->size; i++) {
			this->data[i] = string[i];
		}

		this->data[this->size] = '\0';
	}

	String(const String& string): size(string.size), data(string.data), counter(string.counter) {
		(*(this->counter))++;
	}

	~String() {
		if (*(this->counter) == 0) {
			delete[] this->data;
			delete this->counter;
		}
		else {
			(*(this->counter))--;
		}
	}

	// Получить длинну строки
	size_t length() const {
		return this->size;
	}

	// Привести строку к нижнему регистру
	const char* toLowerCase() {
		char* data = new char[this->size + 1]; // Новая строка

		for (size_t i = 0; i < this->size; i++) {
			data[i] = tolower(this->data[i]);
		}

		data[this->size] = '\0';

		return data;
	}

	// Привести строку к верхнему регистру
	const char* toUpperCase() {
		char* data = new char[this->size + 1]; // Новая строка

		for (size_t i = 0; i < this->size; i++) {
			data[i] = toupper(this->data[i]);
		}

		data[this->size] = '\0';

		return data;
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string) {
		return stream << string.data;
	}
};