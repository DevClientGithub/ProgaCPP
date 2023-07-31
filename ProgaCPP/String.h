#pragma once

#include <iostream>

using namespace std;

// ������ String - ������
class String {
private:
	size_t size; // ������ ������
	char* data; // ������ ������, � ����������
	size_t* counter; // ������� �����

public:
	String(const char* string) : size(strlen(string)), data(new char[this->size + 1]), counter(new size_t(0)) {
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

	// �������� ������ ������
	size_t length() const {
		return this->size;
	}

	// �������� ������ � ������� ��������
	String toLowerCase() {
		char* data = new char[this->size + 1]; // ����� ������

		for (size_t i = 0; i < this->size; i++) {
			data[i] = tolower(this->data[i]);
		}

		data[this->size] = '\0';

		String result = data;
		delete[] data;

		return result;
	}

	// �������� ������ � �������� ��������
	String toUpperCase() {
		char* data = new char[this->size + 1]; // ����� ������

		for (size_t i = 0; i < this->size; i++) {
			data[i] = toupper(this->data[i]);
		}

		data[this->size] = '\0';

		String result = data;
		delete[] data;

		return result;
	}

	// ����������� �������
	String& reverse() {
		for (size_t i = 0; i < this->size / 2; i++) {
			std::swap(this->data[i], this->data[this->size - i - 1]);
		}

		return *this;
	}

	String operator+(const String& string) {
		char* data = new char[this->size + string.size + 1]; // ����� ������ ��� ������������

		size_t i = 0;
		for (; i < this->size; i++) {
			data[i] = this->data[i];
		}

		for (size_t j = 0; j < string.size; j++) {
			data[i++] = string.data[j];
		}

		data[this->size + string.size] = '\0';
		
		String result = data;
		delete[] data;

		return result;
	}

	String operator+(const char* string) {
		const size_t stringSize = strlen(string); // ������ ����� ��������� string
		char* data = new char[this->size + stringSize + 1]; // ����� ������ ��� ������������

		size_t i = 0;
		for (; i < this->size; i++) {
			data[i] = this->data[i];
		}

		for (size_t j = 0; j < stringSize; j++) {
			data[i++] = string[j];
		}

		data[this->size + stringSize] = '\0';

		String result = data; // ��������� - ����� �������
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