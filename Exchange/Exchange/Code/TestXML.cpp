// TestXML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
/*
#include <iostream>
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

int main()
{
    std::cout << "Hello World!\n"; 

	XMLDocument doc;
	int errorID = doc.LoadFile("Scripts/OP.xml");
	
	if (errorID != 0)
	{
		std::cout << "XMLDocument error : " << doc.ErrorName() << std::endl;
		return -1;
	}

	XMLElement * ele = doc.FirstChildElement("Root")->FirstChildElement("Element_1")->FirstChildElement();

	while (ele != NULL)
	{
		const char* text = ele->GetText();
		cout << "From " << ele->Value() << " : " << text << endl;
		ele = ele->NextSiblingElement();
	}

	ele = doc.FirstChildElement("Root")->FirstChildElement("Element_2");
	const char* text = ele->GetText();
	cout << "From " << ele->Value() << " : " << text << endl;

	ele = doc.FirstChildElement("Root")->FirstChildElement("Element_3");
	text = ele->GetText();
	cout << "From " << ele->Value() << " : " << text << endl;
	
	std::cout << "Finish\n";
}
*/