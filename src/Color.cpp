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
    return roundToInt(r * 255);
}

int Color::getGreen() {
    return roundToInt(g * 255);
}

int Color::getBlue() {
    return roundToInt(b * 255);
}

int Color::getAlpha() {
    return roundToInt(a * 255);
}

Color& Color::operator=(const Color& c) {
    r = c.r;
    g = c.g;
    b = c.b;
    a = c.a;
    return *this;
}

bool Color::operator==(const Color& c) {
    if (r == c.r && b == c.b && g == c.g && a == c.a) {
        return true;
    }

    return false;
}
