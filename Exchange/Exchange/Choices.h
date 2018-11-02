#pragma once

#include "TextObject.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Choices :public TextObject
{
	unsigned int BGtexture = 0;
	int choiceID;
public:
	Choices();
	~Choices();
	void render(glm::mat4 globalModelTransform);
	void update(float deltaTime);
	void loadTexture(string fileName);
	int GetID();
	void SetID(int id);
};

