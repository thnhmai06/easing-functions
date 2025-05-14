#pragma once
#include <cmath>
#include <map>

#include "easing.h"

constexpr double PI = 3.14159265359;
constexpr double c1 = 1.70158;
constexpr double c2 = c1 * 1.525;
constexpr double c3 = c1 + 1;
constexpr double c4 = (2 * PI) / 3;
constexpr double c5 = (2 * PI) / 4.5;
constexpr double n1 = 7.5625;
constexpr double d1 = 2.75;

double easeInSine(double x) {
	return 1 - cos((PI * x) / 2);
}

double easeOutSine(double x) {
	return sin((PI * x) / 2);
}

double easeInOutSine(double x) {
	return -(cos(PI * x) - 1) / 2;
}

double easeInQuad(double x) {
	return x * x;
}

double easeOutQuad(double x) {
	return 1 - pow(1 - x, 2);
}

double easeInOutQuad(double x) {
	if (x < 0.5) {
		return 2 * x * x;
	}
	else {
		return 1 - pow(-2 * x + 2, 2) / 2;
	}
}

double easeInCubic(double x) {
	return x * x * x;
}

double easeOutCubic(double x) {
	return 1 - pow(1 - x, 3);
}

double easeInOutCubic(double x) {
	return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
}

double easeInQuart(double x) {
	return pow(x, 4);
}

double easeOutQuart(double x) {
	return 1 - pow(1 - x, 4);
}

double easeInOutQuart(double x) {
	return x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;
}

double easeInQuint(double x) {
	return pow(x, 5);
}

double easeOutQuint(double x) {
	return 1 - pow(1 - x, 5);
}

double easeInOutQuint(double x) {
	return x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
}

double easeInExpo(double x) {
	return x == 0 ? 0 : pow(2, 10 * x - 10);
}

double easeOutExpo(double x) {
	return x == 1 ? 1 : 1 - pow(2, -10 * x);
}

double easeInOutExpo(double x) {
	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5 ? pow(2, 20 * x - 10) / 2
		: (2 - pow(2, -20 * x + 10)) / 2;
}

double easeInCirc(double x) {
	return 1 - sqrt(1 - pow(x, 2));
}

double easeOutCirc(double x) {
	return sqrt(1 - pow(x - 1, 2));
}

double easeInOutCirc(double x) {
	return x < 0.5
		? (1 - sqrt(1 - pow(2 * x, 2))) / 2
		: (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
}

double easeInBack(double x) {
	return c3 * x * x * x - c1 * x * x;
}

double easeOutBack(double x) {
	return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
}

double easeInOutBack(double x) {
	return x < 0.5
		? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		: (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}

double easeInElastic(double x) {
	return x == 0
		? 0
		: x == 1
		? 1
		: -pow(2, 10 * x - 10) * sin((x * 10 - 10.75) * c4);
}

double easeOutElastic(double x) {
	return x == 0
		? 0
		: x == 1
		? 1
		: pow(2, -10 * x) * sin((x * 10 - 0.75) * c4) + 1;
}

double easeInOutElastic(double x) {
	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5
		? -(pow(2, 20 * x - 10) * sin((20 * x - 11.125) * c5)) / 2
		: (pow(2, -20 * x + 10) * sin((20 * x - 11.125) * c5)) / 2 + 1;
}

double easeOutBounce(double x) {
	if (x < 1 / d1) {
		return n1 * x * x;
	}
	else if (x < 2 / d1) {
		return n1 * (x -= 1.5 / d1) * x + 0.75;
	}
	else if (x < 2.5 / d1) {
		return n1 * (x -= 2.25 / d1) * x + 0.9375;
	}
	else {
		return n1 * (x -= 2.625 / d1) * x + 0.984375;
	}
}

double easeInBounce(double x) {
	return 1 - easeOutBounce(1 - x);
}

double easeInOutBounce(double x) {
	return x < 0.5
		? (1 - easeOutBounce(1 - 2 * x)) / 2
		: (1 + easeOutBounce(2 * x - 1)) / 2;
}

easingFunction getEasingFunction(easing_functions function)
{
	static std::map< easing_functions, easingFunction > easingFunctions;
	if (easingFunctions.empty())
	{
		easingFunctions.insert(std::make_pair(EaseInSine, easeInSine));
		easingFunctions.insert(std::make_pair(EaseOutSine, easeOutSine));
		easingFunctions.insert(std::make_pair(EaseInOutSine, easeInOutSine));
		easingFunctions.insert(std::make_pair(EaseInQuad, easeInQuad));
		easingFunctions.insert(std::make_pair(EaseOutQuad, easeOutQuad));
		easingFunctions.insert(std::make_pair(EaseInOutQuad, easeInOutQuad));
		easingFunctions.insert(std::make_pair(EaseInCubic, easeInCubic));
		easingFunctions.insert(std::make_pair(EaseOutCubic, easeOutCubic));
		easingFunctions.insert(std::make_pair(EaseInOutCubic, easeInOutCubic));
		easingFunctions.insert(std::make_pair(EaseInQuart, easeInQuart));
		easingFunctions.insert(std::make_pair(EaseOutQuart, easeOutQuart));
		easingFunctions.insert(std::make_pair(EaseInOutQuart, easeInOutQuart));
		easingFunctions.insert(std::make_pair(EaseInQuint, easeInQuint));
		easingFunctions.insert(std::make_pair(EaseOutQuint, easeOutQuint));
		easingFunctions.insert(std::make_pair(EaseInOutQuint, easeInOutQuint));
		easingFunctions.insert(std::make_pair(EaseInExpo, easeInExpo));
		easingFunctions.insert(std::make_pair(EaseOutExpo, easeOutExpo));
		easingFunctions.insert(std::make_pair(EaseInOutExpo, easeInOutExpo));
		easingFunctions.insert(std::make_pair(EaseInCirc, easeInCirc));
		easingFunctions.insert(std::make_pair(EaseOutCirc, easeOutCirc));
		easingFunctions.insert(std::make_pair(EaseInOutCirc, easeInOutCirc));
		easingFunctions.insert(std::make_pair(EaseInBack, easeInBack));
		easingFunctions.insert(std::make_pair(EaseOutBack, easeOutBack));
		easingFunctions.insert(std::make_pair(EaseInOutBack, easeInOutBack));
		easingFunctions.insert(std::make_pair(EaseInElastic, easeInElastic));
		easingFunctions.insert(std::make_pair(EaseOutElastic, easeOutElastic));
		easingFunctions.insert(std::make_pair(EaseInOutElastic, easeInOutElastic));
		easingFunctions.insert(std::make_pair(EaseInBounce, easeInBounce));
		easingFunctions.insert(std::make_pair(EaseOutBounce, easeOutBounce));
		easingFunctions.insert(std::make_pair(EaseInOutBounce, easeInOutBounce));

	}

	auto it = easingFunctions.find(function);
	return it == easingFunctions.end() ? nullptr : it->second;
}
