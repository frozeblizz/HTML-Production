#include "pch.h"
#include "Game.h"
#include "GLRendererColor.h"
#include "SquareMeshVbo.h"
#include "GameObject.h"
#include "TextMeshVbo.h"
#include "TextObject.h"
#include "DiaTextMeshVbo.h"

Game* Game::instance = nullptr;


Game * Game::getInstance()
{
	if (instance == nullptr) {
		instance = new Game();
	}
	return instance;
}

GLRenderer * Game::getRenderer()
{
	return this->renderer;
}



void Game::handleMouse(int x, int y)
{
	float realX, realY;
	realX = -3 + x * (6.0 / winWidth);
	realY = -3 + (winHeight - y) * (6.0 / winHeight);
	
}

void Game::handleKey(char ch)
{
	if (this->objects.size() > 0) {
		DrawableObject *obj = this->objects.at(0);
		switch (ch) {
		case 'u': obj->translate(glm::vec3(0, 0.3, 0)); break;
		case 'd': obj->translate(glm::vec3(0, -0.3, 0)); break;
		case 'l': obj->translate(glm::vec3(-0.3, 0, 0)); break;
		case 'r': obj->translate(glm::vec3(0.3, 0, 0)); break;
		}
	}
}

void Game::init(int width, int height)
{
	winWidth = width;
	winHeight = height;
	renderer = new GLRendererColor(width, height);
	renderer->initGL("shaders/color/vertext.shd", "shaders/color/fragment.shd");
	renderer->setOrthoProjection(-640, 640, -360, 360);
	renderer->setClearColor(1.0f, 1.0f, 200.0f / 255);

	SquareMeshVbo * square = new SquareMeshVbo();
	square->loadData();
	renderer->addMesh(SquareMeshVbo::MESH_NAME, square);

	TextMeshVbo * text = new TextMeshVbo();
	text->loadData();
	renderer->addMesh(TextMeshVbo::MESH_NAME, text);

	/*DiaTextMeshVbo * diaText = new DiaTextMeshVbo();
	diaText->loadData();
	renderer->addMesh(DiaTextMeshVbo::MESH_NAME, diaText);*/

	
	GameObject * MC = new GameObject(); //MC
	MC->loadTexture("character/MC.png");
	
	MC->setSize(250, -350);
	MC->translate(glm::vec3(-500, -200, 0));

	objects.push_back(MC);

	GameObject * char1 = new GameObject(); //Char1
	char1->setColor(0.0, 1.0, 1.0);
	char1->setSize(300, 400);
	char1->translate(glm::vec3(-100, 90, 0));
	objects.push_back(char1);

	GameObject * char2 = new GameObject(); //Char2
	char2->setColor(0.0, 1.0, 1.0);
	char2->setSize(300, 400);
	char2->translate(glm::vec3(370, 90, 0));
	objects.push_back(char2);

	GameObject * dialogueBox = new GameObject(); //Dialogue
	dialogueBox->setColor(1.0, 0.0, 0.0);
	dialogueBox->setSize(990, 250);
	dialogueBox->translate(glm::vec3(120, -220, 0));
	objects.push_back(dialogueBox);

	GameObject * nameBox = new GameObject(); //NameBox
	nameBox->setColor(0.0, 0.0, 1.0);
	nameBox->setSize(200, 50);
	nameBox->translate(glm::vec3(-275, -70, 0));
	objects.push_back(nameBox);

	TextObject * name = new TextObject(); //Name
	SDL_Color textColor = { 0,0,255 };
	name->loadText("MC", textColor, "neuropol.ttf", 40);
	name->translate(glm::vec3(-275, -70, 0));
	objects.push_back(name);

	TextObject * dialogue = new TextObject(); 
	string test = "asasddddasdddddddd";
	string t1;
	SDL_Color dialogueColor = { 0,0,0 };
	for (int i = 0; i < test.length(); i++)
	{
		cout << i << endl;
		t1 += test[i];
		dialogue->loadText(t1, dialogueColor, "neuropol.ttf", 40);
		dialogue->setPosition(glm::vec3(0, -50, 0));
		objects.push_back(dialogue);
	}
	/*dialogue->loadText(test, dialogueColor, "neuropol.ttf", 40);
	dialogue->setPosition(glm::vec3(0, -50, 0));
	objects.push_back(dialogue);*/
	
	
	

	int num = 2;
	for (int i = 0; i < num; i++)
	{
		int upper = 180;
		int lower = 40;

		float diff = upper - lower;

		GameObject * obj6 = new GameObject(); //Choice1
		obj6->setColor(0.0, 0.3 * i, 1.0);
		obj6->setSize(800, 80);
		obj6->translate(glm::vec3(135, upper - diff/((num * i+1) * 1.0f), 0));
		objects.push_back(obj6);

		TextObject * text = new TextObject();
		SDL_Color textColor = { 0,0,255 };
		if (i == 0)
		{
			text->loadText("Choice 2", textColor, "neuropol.ttf", 40);
		}
		else
		{
			text->loadText("Choice 1", textColor, "neuropol.ttf", 40);
		}
		text->translate(glm::vec3(135, upper - diff / ((num * i + 1) * 1.0f), 0));
		objects.push_back(text);
	}

	
}

void Game::render()
{
	this->getRenderer()->render(this->objects);
}

Game::Game()
{
	for (DrawableObject* obj : objects) {
		delete obj;
	}
	renderer = nullptr;
}


