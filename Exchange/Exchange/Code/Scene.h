#pragma once
#include "GameObject.h"
#include "Choices.h"
#include <string>
#include "tinyxml2.h"

using namespace tinyxml2;

class Scene
{
	
public:
	GameObject* background;
	GameObject** character;
	Choices* choice;
	string* text;
	Scene();
	Scene(const char * xml);

	void Next();
	
};