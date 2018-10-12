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
	Scene(GameObject &background, GameObject **character);
	void LoadScene();
	
};