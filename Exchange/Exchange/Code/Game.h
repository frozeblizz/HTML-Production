#pragma once

#include <vector>
#include "DrawableObject.h"
#include "GLRenderer.h"
#include "TextObject.h"
#include "Choices.h"
using namespace std;
class Game
{
	static Game* instance;
	int winWidth, winHeight;
	int choicesNum;
	bool triggerChoice = false;
	vector<DrawableObject*> objects;
	GLRenderer *renderer;
	TextObject * dialogue;
	Choices * choices[];
	Game();
public:
	static Game* getInstance();
	GLRenderer * getRenderer();
	void handleMouse(int x, int y);
	void handleKey(char ch);
	void init(int width, int height);
	void render();
	void update(float deltaTime);

	


};