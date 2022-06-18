#include "XmlNode.h"

void XmlNode::free()
{
	children.clear();
}

XmlNode::~XmlNode()
{
	free();
}

XmlNode* XmlNode::XmlReader(const std::string& content, size_t& i)
{
    bool flag = false;
    std::string info = "";
    if (content[i++] == '<')
    {
        while (content[i] != '>')
        {
            if (content[i] == ' ') break;
            info += content[i++];
           // std::cout << "PROBLEM: PERSON!" << info << std::endl;
        }
        if (content[i] == '>')
        {
            i++;
            tag = info;
            std::cout << "TAG: " << info << "\n";
            info = "";
        }
        else if (content[i++] == ' ')
        {
            tag = info;
            std::cout << "TAG+: " << info << "\n";
            info = "";
            while (content[i] != '=')
            {
                info += content[i++];
            }
            i++;
            std::cout << "AttributeName: " << info << "\n";
            attributes.setKey(info);
            info = "";
            while (content[i] != '>')
            {
                info += content[i++];
            }
            std::cout << "AttributeValue: " << info << "\n";
            attributes.setValue(info);
            info = "";
            i++;
        }

        if (content[i] != '<')
        {
            while (content[i] != '<')
            {
                info += content[i++];
            }
            flag = true;
            std::cout << "TEXT: " << info << "\n";
            text = info;
            info = "";
        }
        if (content[i] == '<')
        {
            if (flag == true)
            {
                while (content[i] != '>') i++;
                return this;
            }
            while (content[i + 1] != '/') children.push_back(XmlReader(content, i));
            while (content[i] != '>') i++;
            return this;
        }
        
    }
}


size_t XmlNode::getChildrenSize() const
{
	return children.size();
}

XmlNode* XmlNode::searchID(const std::string& id) const
{
    for (size_t i = 0; i < children.size(); i++)
    {
        if (id == children[i]->attributes.getValue()) return children[i];
    }

    return nullptr;
}

XmlNode* XmlNode::searchKey(const std::string& key) const
{
    for (size_t i = 0; i < children.size(); i++)
    {
        if (children[i]->attributes.getKey() == key) return children[i];
    }
    
    return nullptr;
}

XmlNode* XmlNode::select(const std::string& id , const std::string& key)
{
    XmlNode* ptr = searchID(id);
    if (ptr == nullptr)
    {
        //std::cout << "This element does not exist!\n";
        return nullptr;
    }
    if (key == "id") return ptr;

    ptr = ptr->searchKey(key);
    if (ptr == nullptr)
    {
        //std::cout << "This element does not exist!\n";
        return nullptr;
    }
    return ptr;
}

void XmlNode::set(const std::string& id, const std::string& key, const std::string& value)
{
    XmlNode* ptr = select(id, key);
    ptr->attributes.setValue(value);
}





