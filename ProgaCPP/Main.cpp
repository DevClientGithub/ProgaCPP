#include <iostream>
#include "String.h"

int main() {
    const char* input = "stonks;sugoma;amogus;pizdec";
    const char* delimiter = ";";

    String str(input);
    String** substrings = str.split(delimiter);

    for (size_t i = 0; substrings[i] != nullptr; ++i) {
        std::cout << "Substring " << i + 1 << ": " << *substrings[i] << std::endl;
        delete substrings[i];
    }

    delete[] substrings;

    return 0;
}
