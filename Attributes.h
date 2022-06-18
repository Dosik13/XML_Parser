#pragma once
#include<iostream>

class Attributes
{
	std::string key;
	std::string value;

public:
	void setKey(const std::string&);
	void setValue(const std::string&);
	const std::string getKey() const;
	const std::string getValue() const;
};

