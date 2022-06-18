#ifndef __SERIALIZE_VISITOR_H
#define __SERIALIZE_VISITOR_H

#include "Visitor.h"
#include <fstream>

class SerializeVisitor : public Visitor {
private:
	std::ostream& out;
	size_t depth;
public:
	SerializeVisitor(std::ostream& outStream);

	void visitChildren(XmlNode* children) override;
};

#endif