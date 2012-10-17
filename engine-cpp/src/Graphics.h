#pragma once

#include "Color.h"

class AABB;
class Texture;

class Graphics {
public:
	Graphics();

	void setColor(const Color& c);
	void drawRect(float x, float y, float w, float h);
	void drawRect(const AABB& r);
	void fillRect(float x, float y, float w, float h);
	void fillRect(const AABB& r);
	void drawTexture(float x, float y, Texture& texture);
	void drawTexture(float x, float y, float w, float h, unsigned int glName);

private:
	void _setGlColor();
	Color color;
};