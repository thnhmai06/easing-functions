#include <numbers>
#include <unordered_map>

#include "easing.h"

constexpr double pi = std::numbers::pi;
constexpr double c1 = 1.70158;
constexpr double c2 = c1 * 1.525;
constexpr double c3 = c1 + 1;
constexpr double c4 = (2 * pi) / 3;
constexpr double c5 = (2 * pi) / 4.5;
constexpr double n1 = 7.5625;
constexpr double d1 = 2.75;

static double easeInSine(const double x)
{
	return 1 - cos((pi * x) / 2);
}

static double easeOutSine(const double x)
{
	return sin((pi * x) / 2);
}

static double easeInOutSine(const double x)
{
	return -(cos(pi * x) - 1) / 2;
}

static double easeInQuad(const double x)
{
	return x * x;
}

static double easeOutQuad(const double x)
{
	return 1 - pow(1 - x, 2);
}

static double easeInOutQuad(const double x)
{
	if (x < 0.5) 
		return 2 * x * x;
	return 1 - pow(-2 * x + 2, 2) / 2;
}

static double easeInCubic(const double x)
{
	return x * x * x;
}

static double easeOutCubic(const double x)
{
	return 1 - pow(1 - x, 3);
}

static double easeInOutCubic(const double x)
{
	return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
}

static double easeInQuart(const double x)
{
	return pow(x, 4);
}

static double easeOutQuart(const double x)
{
	return 1 - pow(1 - x, 4);
}

static double easeInOutQuart(const double x)
{
	return x < 0.5 ? 8 * x * x * x * x : 1 - pow(-2 * x + 2, 4) / 2;
}

static double easeInQuint(const double x)
{
	return pow(x, 5);
}

static double easeOutQuint(const double x)
{
	return 1 - pow(1 - x, 5);
}

static double easeInOutQuint(const double x)
{
	return x < 0.5 ? 16 * x * x * x * x * x : 1 - pow(-2 * x + 2, 5) / 2;
}

static double easeInExpo(const double x)
{
	return x == 0 ? 0 : pow(2, 10 * x - 10);
}

static double easeOutExpo(const double x)
{
	return x == 1 ? 1 : 1 - pow(2, -10 * x);
}

static double easeInOutExpo(const double x)
{
	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5 ? pow(2, 20 * x - 10) / 2
		: (2 - pow(2, -20 * x + 10)) / 2;
}

static double easeInCirc(const double x)
{
	return 1 - sqrt(1 - pow(x, 2));
}

static double easeOutCirc(const double x)
{
	return sqrt(1 - pow(x - 1, 2));
}

static double easeInOutCirc(const double x)
{
	return x < 0.5
		? (1 - sqrt(1 - pow(2 * x, 2))) / 2
		: (sqrt(1 - pow(-2 * x + 2, 2)) + 1) / 2;
}

static double easeInBack(const double x)
{
	return c3 * x * x * x - c1 * x * x;
}

static double easeOutBack(const double x)
{
	return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
}

static double easeInOutBack(const double x)
{
	return x < 0.5
		? (pow(2 * x, 2) * ((c2 + 1) * 2 * x - c2)) / 2
		: (pow(2 * x - 2, 2) * ((c2 + 1) * (x * 2 - 2) + c2) + 2) / 2;
}

static double easeInElastic(const double x)
{
	return x == 0
		? 0
		: x == 1
		? 1
		: -pow(2, 10 * x - 10) * sin((x * 10 - 10.75) * c4);
}

static double easeOutElastic(const double x)
{
	return x == 0
		? 0
		: x == 1
		? 1
		: pow(2, -10 * x) * sin((x * 10 - 0.75) * c4) + 1;
}

static double easeInOutElastic(const double x)
{
	return x == 0
		? 0
		: x == 1
		? 1
		: x < 0.5
		? -(pow(2, 20 * x - 10) * sin((20 * x - 11.125) * c5)) / 2
		: (pow(2, -20 * x + 10) * sin((20 * x - 11.125) * c5)) / 2 + 1;
}

static double easeOutBounce(double x)
{
	if (x < 1 / d1)
		return n1 * x * x;
	if (x < 2 / d1)
		return n1 * (x -= 1.5 / d1) * x + 0.75;
	if (x < 2.5 / d1)
		return n1 * (x -= 2.25 / d1) * x + 0.9375;
	return n1 * (x -= 2.625 / d1) * x + 0.984375;
}

static double easeInBounce(const double x)
{
	return 1 - easeOutBounce(1 - x);
}

static double easeInOutBounce(const double x)
{
	return x < 0.5
		? (1 - easeOutBounce(1 - 2 * x)) / 2
		: (1 + easeOutBounce(2 * x - 1)) / 2;
}

easingFunction getEasingFunction(const easing_functions function)
{
	static std::unordered_map<easing_functions, easingFunction> easingFunctions;
	if (easingFunctions.empty())
	{
		easingFunctions.emplace(EaseInSine, easeInSine);
		easingFunctions.emplace(EaseOutSine, easeOutSine);
		easingFunctions.emplace(EaseInOutSine, easeInOutSine);
		easingFunctions.emplace(EaseInQuad, easeInQuad);
		easingFunctions.emplace(EaseOutQuad, easeOutQuad);
		easingFunctions.emplace(EaseInOutQuad, easeInOutQuad);
		easingFunctions.emplace(EaseInCubic, easeInCubic);
		easingFunctions.emplace(EaseOutCubic, easeOutCubic);
		easingFunctions.emplace(EaseInOutCubic, easeInOutCubic);
		easingFunctions.emplace(EaseInQuart, easeInQuart);
		easingFunctions.emplace(EaseOutQuart, easeOutQuart);
		easingFunctions.emplace(EaseInOutQuart, easeInOutQuart);
		easingFunctions.emplace(EaseInQuint, easeInQuint);
		easingFunctions.emplace(EaseOutQuint, easeOutQuint);
		easingFunctions.emplace(EaseInOutQuint, easeInOutQuint);
		easingFunctions.emplace(EaseInExpo, easeInExpo);
		easingFunctions.emplace(EaseOutExpo, easeOutExpo);
		easingFunctions.emplace(EaseInOutExpo, easeInOutExpo);
		easingFunctions.emplace(EaseInCirc, easeInCirc);
		easingFunctions.emplace(EaseOutCirc, easeOutCirc);
		easingFunctions.emplace(EaseInOutCirc, easeInOutCirc);
		easingFunctions.emplace(EaseInBack, easeInBack);
		easingFunctions.emplace(EaseOutBack, easeOutBack);
		easingFunctions.emplace(EaseInOutBack, easeInOutBack);
		easingFunctions.emplace(EaseInElastic, easeInElastic);
		easingFunctions.emplace(EaseOutElastic, easeOutElastic);
		easingFunctions.emplace(EaseInOutElastic, easeInOutElastic);
		easingFunctions.emplace(EaseInBounce, easeInBounce);
		easingFunctions.emplace(EaseOutBounce, easeOutBounce);
		easingFunctions.emplace(EaseInOutBounce, easeInOutBounce);
	}

	const auto it = easingFunctions.find(function);
	return it == easingFunctions.end() ? nullptr : it->second;
}
