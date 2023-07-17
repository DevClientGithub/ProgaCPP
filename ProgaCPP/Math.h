#pragma once

#include <cstdlib>
#include <ctime>

class Math {
public:
    static int add(int a, int b) {
        return a + b;
    }

    static int sub(int a, int b) {
        return a - b;
    }

    static int random(int min, int max) {
        static bool isSeeded = false;
        if (!isSeeded) {
            srand(static_cast<unsigned int>(time(0)));
            isSeeded = true;
        }
        return rand() % (max - min + 1) + min;
    }

    static int antirandom(int a, int b) {
        int randomValue = random(a, b);
        return a + b - randomValue;
    }
};