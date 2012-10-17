#include "Color.h"

#include <cmath>

#include "exmath.h"

Color::Color(float r, float g, float b, float a = 1.f) {
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

int Color::getRed() {
	return round(r * 255);
}

int Color::getGreen() {
	return round(g * 255);
}

int Color::getBlue() {
	return round(b * 255);
}

int Color::getAlpha() {
	return round(a * 255);
}

Color& Color::operator=(const Color& c) {
	r = c.r;
	g = c.g;
	b = c.b;
	a = c.a;
	return *this;
}
