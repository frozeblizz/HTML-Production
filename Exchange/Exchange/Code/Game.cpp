#include "pch.h"
#include "Game.h"
#include "GLRendererColor.h"
#include "SquareMeshVbo.h"
#include "GameObject.h"
#include "TextMeshVbo.h"
#include "DiaTextMeshVbo.h"
#include "Scene.h"
#include "Choices.h"
#include "tinyxml2.h"
#include <vector>

Game* Game::instance = nullptr;

using namespace tinyxml2;

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
	int leftmost[2], rightmost[2], upmost[2], lowmost[2];
	float realX, realY;
	realX = (1280 / -2.0f) + x * (1280 / winWidth);
	realY = (720 / -2.0f) + (winHeight - y) * (720 / winHeight);
	cout << "X: " << realX << endl;
	cout << "Y: " << realY << endl;

	for (int i = 0; i < choicesNum; i++)
	{
	/*	leftmost[i] = (choices[i]->getPostion().x - (choices[i]->getSize().x / 2));
		rightmost[i] = (choices[i]->getPostion().x + (choices[i]->getSize().x / 2));
		upmost[i] = (choices[i]->getPostion().y + (choices[i]->getSize().y / 2));
		lowmost[i] = (choices[i]->getPostion().y - (choices[i]->getSize().y / 2));

		cout << "Choice " << i << "posX: " << choices[i]->getPostion().x << endl;
		cout << "Choice " << i << "posY: " << choices[i]->getPostion().y << endl;*/
	}

	/*for (int i = 0; i < choicesNum; i++)
	{
		if (realX > leftmost[i] && realX < rightmost[i] && realY < upmost[i] && realY > lowmost[i])
		{
			if (choices[i]->GetID() == 0)
			{
				dialogue->setFullText("1");
			}
			else if (choices[i]->GetID() == 1)
			{
				dialogue->setFullText("222222222222222222222222222222222");
			}
			cout << "hit" << endl;
		}
	}*/
	
	if (this->dialogue->GetComplete() == false)
	{
		int index = this->dialogue->GetFullText().length();
		this->dialogue->SetIndex(index - 1);
		
	}
	else
	{

		//dialogue->setFullText("ouiytiyruteytrtuyuiphgcb");
		dialogue->SetIndex(0);
		dialogue->SetComplete(false);
	}
}
	

void Game::handleKey(char ch)
{
	if (this->objects.size() > 0) 
	{
		DrawableObject *obj = this->objects.at(0);
		switch (ch)
		{
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

	DiaTextMeshVbo * diaText = new DiaTextMeshVbo();
	diaText->loadData();
	renderer->addMesh(DiaTextMeshVbo::MESH_NAME, diaText);


	Scene first("Scripts/OP.xml");
	LoadScene(first);
	/*GameObject * BG = new GameObject();
	BG->loadTexture("Background/pikachu.jpg");
	BG->setSize(1280, -720);
	BG->translate(glm::vec3(0, 0, 0));
	objects.push_back(BG);*/

	GameObject * MC = new GameObject(); //MC
	MC->loadTexture("character/MC.png");
	MC->setSize(300, -400);
	MC->translate(glm::vec3(-500, -200, 0));
	objects.push_back(MC);

	GameObject * char1 = new GameObject(); //Char1
	char1->loadTexture("Character/Vivian.png");
	char1->setSize(400, -600);
	char1->translate(glm::vec3(-100, 50, 0));
	objects.push_back(char1);

	GameObject * char2 = new GameObject(); //Char2
	char2->loadTexture("Character/Zac.png");
	char2->setSize(400, -600);
	char2->translate(glm::vec3(370, 50, 0));
	objects.push_back(char2);

	GameObject * dialogueBox = new GameObject(); //Dialogue
	dialogueBox->setColor(1.0, 0.0, 0.0,0.5);
	dialogueBox->setSize(990, 250);
	dialogueBox->translate(glm::vec3(120, -220, 0));
	objects.push_back(dialogueBox);

	GameObject * nameBox = new GameObject(); //NameBox
	nameBox->setColor(0.0, 0.0, 1.0,0.5);
	nameBox->setSize(200, 50);
	nameBox->translate(glm::vec3(-275, -70, 0));
	objects.push_back(nameBox);

	TextObject * name = new TextObject(true); //Name
	SDL_Color textColor = { 0,0,255 };
	name->loadText("Name", textColor, "Font/LibreBaskerville-Regular.otf", 40);
	name->translate(glm::vec3(-275, -70, 0));
	objects.push_back(name);


	XMLDocument doc;
	int errorID = doc.LoadFile("Scripts/OP.xml");
	
	XMLElement * ele = doc.FirstChildElement("Scene")->FirstChildElement("Dialogue")->FirstChildElement("s1");

	const char* textxml = ele->GetText();
	cout << "From " << ele->Value() << " : " << text << endl;
	ele = ele->NextSiblingElement();
	TextObject * dialogue = new TextObject(false);

	string dialogueText(textxml);
	SDL_Color dialogueColor = { 0,0,0 };
	dialogue->setFullText(dialogueText);
	dialogue->setFontName("Font/LibreBaskerville-Regular.otf");
	dialogue->setTextColor(dialogueColor);
	dialogue->setFontSize(30);
	dialogue->setPosition(glm::vec3(-363, -100, 0));
	objects.push_back(dialogue);
	this->dialogue = dialogue;
	
	const int num = 2;
	choicesNum = num;
	Choices * choice[num]; 


	
	for (int i = 0; i < num; i++)
	{
		choice[i] = new Choices();
		int upper = 320;
		int lower = -20;

		float diff = upper - lower;
		choice[i]->SetID(i);
		cout << "Choice " << i << " id: " << choice[i]->GetID() << endl;
	
		/*choice[i]->setColor(0.0, 0.3 * i, 1.0, 1.0);
		choice[i]->setSize(800, 60);
		choice[i]->setPosition(glm::vec3(135, upper - ((diff/(num*1.0f))*(i+1)), 0));
		objects.push_back(choice[i]);
		this->choices[i] = choice[i];
		TextObject * text = new TextObject(true);
		SDL_Color textColor = { 0,0,255 };
		if (i == 0)
		{
			ele = doc.FirstChildElement("Scene")->FirstChildElement("Choice")->FirstChildElement("c1");
			const char* choicexml = ele->GetText();
			string c1(choicexml);
			text->loadText(c1, textColor, "Font/LibreBaskerville-Regular.otf", 40);
	
		}
		else
		{
			ele = doc.FirstChildElement("Scene")->FirstChildElement("Choice")->FirstChildElement("c2");
			const char* choicexml = ele->GetText();
			string c2(choicexml);
			text->loadText(c2, textColor, "Font/LibreBaskerville-Regular.otf", 40);
		}
		text->translate(glm::vec3(135, upper - ((diff / (num*1.0f))*(i + 1)), 0));
		objects.push_back(text);*/
	}


}

void Game::render()
{
	this->getRenderer()->render(this->objects);
}

void Game::update(float deltaTime)
{
	for (DrawableObject* obj : objects) {
		obj->update(deltaTime);
	}
}

void Game::LoadScene(Scene scene)
{
	objects.push_back(scene.background);
	
	for (Choices *ch : scene.choice)
	{
		objects.push_back(ch);
	}
	

}

Game::Game()
{
	for (DrawableObject* obj : objects) {
		delete obj;
	}
	renderer = nullptr;
}



