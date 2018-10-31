#pragma once

#include "DrawableObject.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

class Choices :public DrawableObject
{
	glm::vec4 color;
	unsigned int texture = 0;
	int choiceID;
public:
	Choices();
	~Choices();
	void setColor(float r, float g, float b, float a);
	void render(glm::mat4 globalModelTransform);
	void update(float deltaTime);
	void loadTexture(string fileName);
	int GetID();
	void SetID(int id);
};

