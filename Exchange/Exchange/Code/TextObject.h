#pragma once

#include "DrawableObject.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <SDL_ttf.h>

class TextObject :public DrawableObject
{
private:
	
	
	bool complete = false;
	string fullText;
	int index = 0;
	int fontSize;
	SDL_Color textColor;
	string fontName;
	int countUpdateFrame = 0;
public:
	unsigned int texture;
	bool middleText;
	TextObject();
	TextObject(bool mode);
	~TextObject();
	void setFullText(string text);
	void setTextColor(SDL_Color color);
	void setFontName(string font);
	void setFontSize(int size);
	virtual void render(glm::mat4 globalModelTransform);
	void update(float deltaTime);
	virtual void loadText(string text, SDL_Color textColor, string fontname, int fontSize);
	string GetFullText();
	void SetIndex(int ind);
	bool GetComplete();
	void SetComplete(bool comp);
	
};