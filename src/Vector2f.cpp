#include "Vector2f.h"

#include <cmath>

Vector2f::Vector2f() {
    x = 0;
    y = 0;
}

Vector2f::Vector2f(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2f::Vector2f(const Vector2f& d) {
    this->x = d.x;
    this->y = d.y;
}

float Vector2f::length() {
    return sqrt(pow(x, 2) + pow(y, 2));
}

Vector2f& Vector2f::operator=(const Vector2f& r) {
    x = r.x;
    y = r.y;
    return *this;
}

Vector2f Vector2f::operator+(const Vector2f& r) {
    Vector2f ret(x, y);
    ret.x += r.x;
    ret.y += r.y;
    return ret;
}

Vector2f Vector2f::operator-(const Vector2f& r) {
    Vector2f ret(x, y);
    ret.x -= r.x;
    ret.y -= r.y;
    return ret;
}

Vector2f Vector2f::operator*(float r) {
    Vector2f ret(x, y);
    ret.x *= r;
    ret.y *= r;
    return ret;
}

Vector2f Vector2f::operator/(float r) {
    Vector2f ret(x, y);
    ret.x /= r;
    ret.y /= r;
    return ret;
}

Vector2f& Vector2f::operator+=(const Vector2f& r) {
    x += r.x;
    y += r.y;
    return *this;
}

Vector2f& Vector2f::operator-=(const Vector2f& r) {
    x -= r.x;
    y -= r.y;
    return *this;
}

Vector2f& Vector2f::operator*=(float r) {
    x *= r;
    y *= r;
    return *this;
}

Vector2f& Vector2f::operator/=(float r) {
    x /= r;
    y /= r;
    return *this;
}

bool Vector2f::operator==(const Vector2f& r) {
    if (x == r.x && y == r.y) {
        return true;
    }
    return false;
}
