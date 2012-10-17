#pragma once

#include "Color.h"

class Graphics {
public:
	virtual void setColor(const Color& c);
	virtual void drawRect(float x, float y, float w, float h);
	virtual void fillRect(float x, float y, float w, float h);

private:
	void _setGlColor();
	Color color;
};