#pragma once

#include <cstdlib>
#include <ctime>

constexpr double PI_D = 3.141592653589793; // constexpr как и define не тратят байты в памяти
constexpr float PI_F = 3.1415927f;
constexpr double E_D = 2.718281828459045;
constexpr float E_F = 2.7182817f;
constexpr double GR_D = 1.618033988749895;
constexpr float GR_F = 1.6180339f;
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

	double cos(const double& angle, const bool& isRadian = true) {
		const double res = ::cos(isRadian ? angle : angle * TO_RADIAN);
		return res;
	}

	double tan(const double& angle, const bool& isRadian = true) {
		const double res = ::tan(isRadian ? angle : angle * TO_RADIAN);
		return res;
	}

	double exp(const double& x) {
		const double res = ::exp(x);
		return res;
	}

	double log(const double& x) {
		const double res = ::log(x);
		return res;
	}

	double sqrt(const double& x) {
		const double res = ::sqrt(x);
		return res;
	}

	double pow(const double& base, const double& exponent) {
		const double res = ::pow(base, exponent);
		return res;
	}

	double abs(const double& x) {
		const double res = ::fabs(x);
		return res;
	}

	double hypotenuse(const double& a, const double& b) {
		return ::sqrt(a * a + b * b);
	}

	double angleBetweenVectors(const double& x1, const double& y1, const double& x2, const double& y2) {
		const double dotProduct = x1 * x2 + y1 * y2;
		const double magnitudesProduct = hypotenuse(x1, y1) * hypotenuse(x2, y2);
		const double angleInRadians = ::acos(dotProduct / magnitudesProduct);
		return angleInRadians;
	}

	double circleArea(const double& radius) {
		return PI_D * radius * radius;
	}
};