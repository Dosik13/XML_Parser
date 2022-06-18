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
	//void print() const;													//��������
	//id - value   // key - ID 
	XmlNode* select(const std::string&, const std::string&);		//������� �������� �� �������
	void set(const std::string&, const std::string&, const std::string&);	//����������� �� �������� �� �������
	//void children(const std::string);										//������ � ��������
	//void child(const std::string, size_t);								//������ �� �-��� ���������
	//void text(size_t);													//������ �� ������ �� �������	
	//void delete(const std::string, const std::string);					//��������� �� ������� �� ������� �� ����
	//void newchild(const std::string);										//�������� �� ��� ���������

};

