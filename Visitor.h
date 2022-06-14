#ifndef __VISITOR_H
#define __VISITOR_H
#include"XmlNode.h"

class Visitor {
public:
	virtual void visitChildren(XmlNode* children) = 0;
};

#endif