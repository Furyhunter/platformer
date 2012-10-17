#pragma once

#include "Color.h"

class Graphics {
public:
	Graphics();
	void setColor(const Color& c);
	void drawRect(float x, float y, float w, float h);
	void fillRect(float x, float y, float w, float h);

private:
	void _setGlColor();
	Color color;
};