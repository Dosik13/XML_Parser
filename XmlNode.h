#pragma once
#include <iostream>
#include <vector>
#include "Attributes.h"
class XmlNode
{
	Attributes attributes;
	std::string tag;
	std::string text;
	std::vector<XmlNode*> childrens;

	void free();
public:
	XmlNode() = default;

	~XmlNode();
	XmlNode* XmlReader(const std::string&, size_t&, size_t);
	//std::string TagParser(const std::string&, size_t&);

	void print() const
	{
		std::cout << " tag:" << tag << " text" << text << " AttributeID" << attributes.getKey() << " AttributeValue" << attributes.getValue() << "\n";
	}
	XmlNode* searchID(const std::string&) const;
	XmlNode* searchKey(const std::string&) const;
	//void print() const;													//��������
	//id - value   // key - ID 
	XmlNode* select(const std::string&, const std::string&);		//������� �������� �� �������
	void set(const std::string&, const std::string&, const std::string&);	//����������� �� �������� �� �������
	void children(const std::string&) const;										//������ � ��������
	//void child(const std::string, size_t);								//������ �� �-��� ���������
	//void text(size_t);													//������ �� ������ �� �������	
	//void delete(const std::string, const std::string);					//��������� �� ������� �� ������� �� ����
	//void newchild(const std::string);										//�������� �� ��� ���������

};

