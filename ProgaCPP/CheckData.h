#pragma once

#ifndef CHECKDATA_H // Ётот ifndef €вл€етс€ заменной #pragma once
#define CHECKDATA_H // “очнее, старым способом добитьс€ такого же результата*

#include <iostream>

// ѕоказывает сколько весит переменна€ или же что-то другое в байтах
class CheckData {
public:
    template<typename T>
    static void showSize(const T& obj) {
        std::cout << "Size of the object: " << sizeof(obj) << " bytes." << std::endl;
    }
};

/* ѕример использовани€:
    int i = 1;
    CheckData::showSize(i); */

#endif // CHECKDATA_H