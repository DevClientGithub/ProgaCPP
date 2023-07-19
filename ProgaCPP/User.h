#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// ���� �������� ����� ������� ������� 228

/*11010000 10011110 100000 11010000 10110010 
11010000 10110101 11010000 
10111011 11010000 10111000 11010000 10111010 
11010000 10111000 11010000 10111001 100000 11010000 
10110000 11010001 10000101 11010001 10000011 11010000 
10110101 11010001 10000010 11010001 10001100 100000 11010000 10111010 11010000 
10110000 11010000 10111010 11010000 10111110 11010000 10111001 100000 11010000 10111010 
11010001 10000000 11010001 10000011 11010001 10000010 11010000 10111110 11010000 
10111001 100000 11010001 10000000 11010000 10110000 11010000 10110111 11010001 
10000000 11010000 10110000 11010000 10110001 100000 11010001 10001101 11010001 10000010 
11010000 10111110 11010000 10111001 100000 11010001 10000101 11010001 10000011 11010000 10111001 
11010000 10111101 11010000 10111000 100000 11010000 10110100 11010000 10110000 11010000 10111001 
100000 11010000 10110001 11010000 10111011 11010001 10001111 11010001 10000010 11010001 10001100 
100000 11010001 10000001 11010000 10111000 11010000 10111011 11010001 10001011 100000 11010001 10001101 
11010001 10000010 11010000 10111110 11010000 10111001 100000 11010000 10111111 11010001 10000000 11010000 
10111110 11010000 10110011 11010001 10000000 11010000 10110000 11010000 10111100 11010000 10111100 11010000 
10110101 100000 11010001 10000111 11010001 10000010 11010000 10111110 11010000 10110001 100000 11010001 
10000000 11010000 10110000 11010000 10110001 11010000 10111110 11010001 10000010 11010000 10110000 11010000 
10111011 11010000 10111110 100000 11010000 10110111 11010000 10110000 11010000 10110101 11010000 10110001 
11010000 10111000 11010001 10000001 11010001 10001100 100000 11010000 10111000 100000 11010000 10111111 
11010000 10111010 100000 11010000 10111101 11010000 10110101 100000 11010000 10110010 11010000 10110111 
11010000 10111110 11010001 10000000 11010000 10110010 11010000 10110000 11010000 
10111011 11010001 10000001 11010001 10001111*/

// � ���� ��� ��� ����� ����� ����, �� � ��� �� ���� ������� �����
// ���������� ��������������
class User {
public:
    User(const std::string& name, int id) : name(name), id(id) {}

    std::string getName() const { return name; }
    int getId() const { return id; }

private:
    std::string name;
    int id;
};

class Database {
public:
    // ���������� ����� ������ � ����
    void addUser(const User& user) {
        records.push_back(user);
    }

    // �������� ������ �� ���� �� �����
    void removeUserByName(const std::string& name) {
        records.erase(std::remove_if(records.begin(), records.end(),
            [name](const User& user) {
                return user.getName() == name;
            }),
            records.end());
    }

    // ����� ������ � ���� �� �����
    User* findUserByName(const std::string& name) {
        auto it = std::find_if(records.begin(), records.end(),
            [name](const User& user) {
                return user.getName() == name;
            });

        if (it != records.end()) {
            return &(*it);
        }

        return nullptr;
    }

private:
    std::vector<User> records;
};