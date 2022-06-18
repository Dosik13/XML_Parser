#include "Attributes.h"

void Attributes::setKey(const std::string& key)
{
	this->key = key;
}

void Attributes::setValue(const std::string& value)
{
	this->value = value;
}

const std::string Attributes::getKey() const
{
	return key;
}

const std::string Attributes::getValue() const
{
	return value;
}