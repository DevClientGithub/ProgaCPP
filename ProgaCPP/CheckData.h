#pragma once

#ifndef CHECKDATA_H
#define CHECKDATA_H

#include <iostream>

// ���������� ������� ����� ���������� ��� �� ���-�� ������ � ������
class CheckData {
public:
    template<typename T>
    static void showSize(const T& obj) {
        std::cout << "Size of the object: " << sizeof(obj) << " bytes." << std::endl;
    }
};

/* ������ �������������:
    int i = 1;
    CheckData::showSize(i); */

#endif // CHECKDATA_H