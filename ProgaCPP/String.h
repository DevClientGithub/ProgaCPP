#pragma once
#include <iostream>
#include <ostream>

class String {
private:
	char* data; // Строка
	size_t size; // Длина строки
public:
    String(const char* str) {
        size = strlen(str);
        data = new char[size + 1];
        for (size_t i = 0; i < size; i++) {
            data[i] = str[i];
        }
        data[size] = '\0';
    }

    ~String() {
        delete[] data;
    }
    // Узнать длину строки
    size_t length() const {
        return size;
    }
    // Сделать всю строку маленькой (Через маленькие символы)
    void toLowerCase() {
        for (int i = 0; i < size; i++) {
            data[i] = std::tolower(static_cast<unsigned char>(data[i]));
        }
    }
    // Сделать всю строку большой (Через большие символы)
    void toUpperCase() {
        for (int i = 0; i < size; i++) {
            data[i] = std::toupper(static_cast<unsigned char>(data[i]));
        }
    }
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }
};