#pragma once
#include <iostream>
#include <ostream>

class String {
private:
	char* data; // Строка
	size_t size; // Длина строки
    size_t* counter = new size_t(0); // Количество копий этой строки

public:
    String(const char* str) {
        this->size = strlen(str);

        this->data = new char[this->size + 1];

        for (size_t i = 0; i < this->size; i++) {
            this->data[i] = str[i];
        }

        this->data[this->size] = '\0';
    }

    String(const String& other) {
        this->data = other.data;
        this->size = other.size;

        (*(this->counter))++;
    }

    ~String() {
        if (this->counter == 0) {
            delete[] this->data;
            delete this->counter;
        }
        else {
            (*(this->counter))--;
        }
    }
    // Узнать длину строки
    size_t length() const noexcept {
        return this->size;
    }
    // Сделать всю строку маленькой (Через маленькие символы)
    void toLowerCase() {
        for (int i = 0; i < size; i++) {
            this->data[i] = std::tolower(static_cast<unsigned char>(this->data[i]));
        }
    }
    // Сделать всю строку большой (Через большие символы)
    void toUpperCase() {
        for (int i = 0; i < size; i++) {
            this->data[i] = std::toupper(static_cast<unsigned char>(this->data[i]));
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }
};