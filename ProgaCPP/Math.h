#pragma once

namespace Math {
	constexpr double PI_D = 3.141592653589793; // Число Пи
	constexpr float PI_F = 3.1415927f; // Число Пи

	constexpr double E_D = 2.718281828459045;
	constexpr float E_F = 2.7182817f;

	constexpr double GR_D = 1.618033988749895;
	constexpr float GR_F = 1.6180339f;

	constexpr double TO_RADIAN_D = 0.017453292519943295; // Коэф. конвертации градусов в радианы
	constexpr float TO_RADIAN_F = 0.017453292f; // Коэф.т конвертации градусов в радианы

	double sin(const double& angle, const bool& isRadian = true) {
		const double res = ::sin(isRadian ? angle : angle * TO_RADIAN_D);
		return res;
	}

	float sin(const float& angle, const bool& isRadian = true) {
		const float res = ::sin(isRadian ? angle : angle * TO_RADIAN_F);
		return res;
	}

	double cos(const double& angle, const bool& isRadian = true) {
		const double res = ::cos(isRadian ? angle : angle * TO_RADIAN_D);
		return res;
	}

	float cos(const float& angle, const bool& isRadian = true) {
		const double res = ::cos(isRadian ? angle : angle * TO_RADIAN_F);
		return res;
	}

	double tan(const double& angle, const bool& isRadian = true) {
		const double res = ::tan(isRadian ? angle : angle * TO_RADIAN_D);
		return res;
	}

	float tan(const float& angle, const bool& isRadian = true) {
		const float res = ::tan(isRadian ? angle : angle * TO_RADIAN_F);
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