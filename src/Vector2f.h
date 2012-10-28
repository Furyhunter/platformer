#pragma once

class Vector2f {
public:
	Vector2f();
	Vector2f(float x, float y);
	Vector2f(const Vector2f& d);

	float x;
	float y;

	float length();
	Vector2f normalize();
	Vector2f& normalizeLocal();

	Vector2f& operator=(const Vector2f& r);
	Vector2f operator+(const Vector2f& r);
	Vector2f operator-(const Vector2f& r);
	Vector2f operator*(float r);
	Vector2f operator/(float r);

	Vector2f& operator+=(const Vector2f& r);
	Vector2f& operator-=(const Vector2f& r);
	Vector2f& operator*=(float r);
	Vector2f& operator/=(float r);

	bool operator==(const Vector2f& r);
};