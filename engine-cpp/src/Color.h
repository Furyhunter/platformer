#pragma once

class Color {
public:
	Color(float r, float g, float b, float a);
	
	float r;
	float g;
	float b;
	float a;

	int getRed();
	int getGreen();
	int getBlue();
	int getAlpha();

	// Operator overloading
	Color& operator=(const Color& c);
	bool operator==(const Color& c);
};