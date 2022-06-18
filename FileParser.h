#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
class FileParser
{
public:
	static std::string removeSpaces(const std::string&);
	static std::string fileParser(std::ifstream&);
};

