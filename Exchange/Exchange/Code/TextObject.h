#pragma once

#include "DrawableObject.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <SDL_ttf.h>

class TextObject :public DrawableObject
{
private:
	unsigned int texture;

public:
	TextObject();
	~TextObject();
	void render(glm::mat4 globalModelTransform);
	void update(float deltaTime);
	void loadText(string text, SDL_Color textColor, string fontname, int fontSize);
	
};