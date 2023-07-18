#pragma once
#include <iostream>
#include <cstdlib>
#define errorC std::cout << "[ERROR]: " // Упрощение std::cout << "[ERROR]: "
#define warnC std::cout << "[WARN]: " // Упрощение std::cout << "[WARN]: "

// Вот эти 2 хуйни сверху кста, я сделал для того чтоб потом в будущем мозг не ебать
// Я знаю что от части это какая-то хуйня, и лучше без этого, но похуй:D

// Выход из программы
void quit() {
	exit(0);
}

// Пока что не ебу что тут будет
class SavePc {
	// Пока тут нихуя нет но скоро будет
};
