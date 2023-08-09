#pragma once

#include <cstdlib>
#include <ctime>

constexpr double PI_D = 3.141592653589793; // constexpr как и define не тратят байты в памяти
constexpr double PI_F = 3.1415927f;
constexpr double E_D = 2.718281828459045;
constexpr double E_F = 2.718281828459045f;
constexpr double TO_RADIAN = 0.017453292519943295;

namespace Math {
	int random(const int& min, const int& max) {
		bool isSeeded = false;

		if (!isSeeded) {
			srand(static_cast<unsigned int>(time(0)));
			isSeeded = true;
		}

		return rand() % (max - min + 1) + min;
	}

	int antirandom(const int& a, const int& b) {
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

	double sin(const double& angle, const bool& isRadian = true) {
		const double res = ::sin(isRadian ? angle : angle * TO_RADIAN);
		return res;
	}

};