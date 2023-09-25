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

	double rectangleArea(const double& length, const double& width) {
		return length * width;
	}

	double sigmoid(const double& x) {
		return 1.0 / (1.0 + Math::exp(-x));
	}

	float sigmoid(const float& x) {
		return 1.0f / (1.0f + Math::exp(-x));
	}

	// Ограничивает значение value между минимальным (min) и максимальным (max) значениями.
	double Clamp(const double& value, const double& min, const double& max) {
		if (value < min) {
			return min;
		}
		else if (value > max) {
			return max;
		}
		return value;
	}

	// Выполняет линейную интерполяцию между двумя значениями a и b. (t - ставь 0.5 если хочешь получить половину от числа)
	double Lerp(const double& a, const double& b, double t) {
		return a + t * (b - a);
	}

	double min(const double& a, const double& b) {
		return (a < b) ? a : b;
	}

	double max(const double& a, const double& b) {
		return (a > b) ? a : b;
	}

	double round(const double& x) {
		return std::round(x);
	}

	float round(const float& x) {
		return std::round(x);
	}

	double random(double min, double max) {
		static bool initialized = false;
		if (!initialized) {
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
			initialized = true;
		}

		return min + (max - min) * (static_cast<double>(std::rand()) / RAND_MAX);
	}
	
	// Возвращает наименьшее целое число, которое больше или равно заданному числу с плавающей запятой двойной точности. <--- Это документация от майрокософт
	double Ceiling(double x) {
		int intPart = static_cast<int>(x);
		if (x == intPart) {
			return x;
		}
		else if (x > 0) {
			return intPart + 1.0;
		}
		else {
			return intPart;
		}
	}

	// Возвращает наибольшее целое число, которое меньше или равно заданному числу с плавающей запятой двойной точности. <--- Тоже у майкрософт спиздил
	double Floor(double x) {
		int intPart = static_cast<int>(x);
		if (x == intPart) {
			return x;
		}
		else if (x > 0) {
			return intPart;
		}
		else {
			return intPart - 1.0;
		}
	}

	// Возвращает целое число, обозначающее знак числа двойной точности с плавающей запятой. <--- Тоже по словам майкрософта
	double Sign(double x) {
		if (x > 0) {
			return 1;
		}
		else if (x < 0) {
			return -1;
		}
		else {
			return 0;
		}
	}

	double cbrt(double x) {
		return std::pow(x, 1.0 / 3.0);
	}
};