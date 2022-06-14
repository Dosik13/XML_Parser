#pragma once
#include <iostream>
#include <vector>

class XmlNode
{
	size_t id;
	std::string tag;
	std::string text;
	std::vector<XmlNode> children;

};

