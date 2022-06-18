#include "XmlNode.h"
#include "FileParser.h"
#include <fstream>
int main()
{
	std::ifstream file("test.xml");
	if (!file.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		return -1;
	}
	std::string result;
	result = FileParser::fileParser(file);
	XmlNode xml;
	size_t i = 0;
	xml.XmlReader(result, i);
	std::cout << xml.getChildrenSize();

	return 0;
}