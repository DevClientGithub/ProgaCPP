#pragma once

#include <cstdlib>
#include <ctime>

double PI_D = 3.141592653589793;
double PI_F = 3.141592653589793f;

namespace Math {
	int random(int min, int max) {
		bool isSeeded = false;
		if (!isSeeded) {
			srand(static_cast<unsigned int>(time(0)));
			isSeeded = true;
		}
		return rand() % (max - min + 1) + min;
	}

	int antirandom(int a, int b) {
		int randomValue = random(a, b);
		return a + b - randomValue;
	}

	template<typename T>
	void dupeData(T*& variable, const size_t& size) {
		T* newVariable = new int[size * 2];

		for (int i = 0; i < size; i++) {
			newVariable[i] = variable[i];
		}

		delete[] variable;
		variable = newVariable;
	}

};