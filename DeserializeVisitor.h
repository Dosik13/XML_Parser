#ifndef __XML_DESERIALIZER_H
#define __XML_DESERIALIZER_H

#include "Visitor.h"
#include <iostream>

class XmlDeserializer : public Visitor
{
private:
    std::istream& In;

public:
    XmlDeserializer(std::istream& in);
    virtual void visitChildren(XmlNode* children) override;
};

#endif