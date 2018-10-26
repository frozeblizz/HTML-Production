#pragma once

#include "DrawableObject.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <SDL_ttf.h>

class TextObject :public DrawableObject
{
private:
	unsigned int texture;
	bool middleText;
	string fullText;
	int index = 0;
	int fontSize;
	SDL_Color textColor;
	string fontName;
	int countUpdateFrame = 0;
public:
	TextObject(bool mode);
	~TextObject();
	void setFullText(string text);
	void setTextColor(SDL_Color color);
	void setFontName(string font);
	void setFontSize(int size);
	void render(glm::mat4 globalModelTransform);
	void update(float deltaTime);
	void loadText(string text, SDL_Color textColor, string fontname, int fontSize);
	
};