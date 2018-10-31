#include "pch.h"
#include "XmlReaderh.h"

XmlReader::XmlReader(const char* filename)
{
	int errorID = doc->LoadFile(filename);
	int index = 0;
	if (index == 0)
	{
		ele = doc->FirstChildElement("Scene")->FirstChildElement("Dialogue")->FirstChildElement();
		index++;
	}
	else
	{
		ele = doc->FirstChildElement("Scene")->FirstChildElement("Dialogue")->NextSiblingElement();
	}
	


}