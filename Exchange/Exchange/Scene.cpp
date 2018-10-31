#include "pch.h"
#include "Scene.h"
#include <iostream>
Scene::Scene()
{

}

Scene::Scene(const char * xml)
{
	XMLDocument doc;
	int errorID = doc.LoadFile(xml);

	XMLElement * ele = doc.FirstChildElement("Scene")->FirstChildElement("Background");
	background = new GameObject();
	background->loadTexture(ele->GetText());
	background->setSize(1280, -720);
	background->setPosition(glm::vec3(0, 0, 0));

	ele = doc.FirstChildElement("Scene")->FirstChildElement("Dialogue")->FirstChildElement();
	int textSize = stoi(ele->GetText());

	text = new string[textSize];

	ele = ele->NextSiblingElement();

	for(int i = 0; i < textSize; i++)
	{
		text[i] = string(ele->GetText());
		ele = ele->NextSiblingElement();
	}

	ele = doc.FirstChildElement("Scene")->FirstChildElement("Choice")->FirstChildElement();
	int choiceSize = stoi(ele->GetText());
	 
	choice = new Choices[choiceSize];

	ele = ele->NextSiblingElement();

	SDL_Color textcolor = { 1, 1, 1 };
	int upper = 320;
	int lower = -20;
	int diff = upper - lower;
	for (int i = 0; i < choiceSize; i++)
	{
		choice[i] = Choices();
		choice[i].loadTexture("Background/pikachu.jpg");
		choice[i].setSize(800, 60);
		choice[i].setPosition(glm::vec3(135, upper - ((diff / (choiceSize*1.0f))*(i + 1)), 0));
		cout << ele->GetText();
		choice[i].loadText(ele->GetText(), textcolor, "neuropol.ttf", 40);
		ele = ele->NextSiblingElement();
	}
	

}


void Scene::Next()
{
	//Reduce delta time to 0
}