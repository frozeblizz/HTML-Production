#pragma once

#include <vector>
#include "DrawableObject.h"
#include "GLRenderer.h"
#include "TextObject.h"
#include "Choices.h"
#include "Scene.h"
using namespace std;
class Game
{
	static Game* instance;
	int winWidth, winHeight;
	int choicesNum;
	vector<DrawableObject*> objects;
	GLRenderer *renderer;
	TextObject * dialogue;
	Game();
public:
	
	static Game* getInstance();
	GLRenderer * getRenderer();
	void handleMouse(int x, int y);
	void handleKey(char ch);
	void init(int width, int height);
	void render();
	void update(float deltaTime);
	void LoadScene(Scene scene);

	


};