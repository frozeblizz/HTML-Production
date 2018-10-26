#include "pch.h"
#include "Scene.h"

Scene::Scene()
{

}

Scene::Scene(GameObject &background, GameObject ** character)
{
	this->background = &background;
	this->character = character;
}

void Scene::LoadScene()
{
	Scene *scene = new Scene(*background, character);

}

void Scene::NextScene()
{
	//Reduce delta time to 0
}