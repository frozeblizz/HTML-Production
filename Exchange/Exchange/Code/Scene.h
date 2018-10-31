#pragma once
#include "GameObject.h"
#include <string>
class Scene
{
	GameObject* background;
	GameObject** character;
	GameObject* choice;
	string text;
public:
	Scene();
	Scene(GameObject &background, GameObject **character);
	void LoadScene();
	void Next();
	
};