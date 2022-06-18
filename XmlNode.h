#pragma once
#include <iostream>
#include <vector>
#include "Attributes.h"
class XmlNode
{
	Attributes attributes;
	std::string tag;
	std::string text;
	std::vector<XmlNode*> children;

	void free();
public:
	XmlNode() = default;

	~XmlNode();
	XmlNode* XmlReader(const std::string&, size_t&);

	size_t getChildrenSize() const;

	XmlNode* searchID(const std::string&) const;
	XmlNode* searchKey(const std::string&) const;
	//void print() const;													//принтира
	//id - value   // key - ID 
	XmlNode* select(const std::string&, const std::string&);		//извежда стойност на елемент
	void set(const std::string&, const std::string&, const std::string&);	//присвояване на стойност на атрибут
	//void children(const std::string);										//списък с атрибути
	//void child(const std::string, size_t);								//достъп до п-тия наследник
	//void text(size_t);													//достъп до текста на елемент	
	//void delete(const std::string, const std::string);					//изтриване на атрибут на елемент по ключ
	//void newchild(const std::string);										//добавяне на нов наследник

};

