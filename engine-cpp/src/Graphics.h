#pragma once

#include "Color.h"
#include "Vector2f.h"

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

	void setTranslation(const Vector2f& vec) { translation = vec; }
	Vector2f getTranslation() { return translation; }

private:
	void _setGlColor();
	Color color;
	Vector2f translation;
};