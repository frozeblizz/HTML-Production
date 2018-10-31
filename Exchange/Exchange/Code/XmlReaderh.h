#pragma once
#include "tinyxml2.h"
#include <string>

using namespace std;
using namespace tinyxml2;

class XmlReader
{
private:
	XMLDocument* doc;
	XMLElement* ele;
public:
	XmlReader(const char * filename);

};