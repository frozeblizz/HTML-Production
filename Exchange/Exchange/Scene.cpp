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
	 
	choice.clear();

	ele = ele->NextSiblingElement();

	SDL_Color textcolor = { 1, 1, 1 };
	int upper = 320;
	int lower = -20;
	int diff = upper - lower;
	for (int i = 0; i < choiceSize; i++)
	{
		Choices * ch = new Choices();
		ch->loadTexture("Background/pikachu.jpg");
		//ch->setSize(800, 60);
		ch->setPosition(glm::vec3(135, upper - ((diff / (choiceSize*1.0f))*(i + 1)), 0));
		cout << ele->GetText();
		string temp(ele->GetText());
		ch->loadText(temp, textcolor, "Font/LibreBaskerville-Regular.otf", 40);
		choice.push_back(ch);
		ele = ele->NextSiblingElement();
	}
	

}


void Scene::Next()
{
	//Reduce delta time to 0
}