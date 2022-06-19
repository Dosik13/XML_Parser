#include "XmlNode.h"

void XmlNode::free()
{
	childrens.clear();
}

XmlNode::~XmlNode()
{
	free();
}

XmlNode* XmlNode::XmlReader(const std::string& content, size_t& i, size_t level)
{
    std::cout << level << "REKURSIQ!!!\n";
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
            this->tag = info;
            std::cout << "Tag: " << tag << '\n';
            info = "";
        }
        if (content[i] == ' ')
        {
            i++;
            this->tag = info;
            std::cout << "Tag: " << tag << '\n';
            info = "";
            while (content[i] != '=')
            {
                info += content[i++];
            }
            i++;
          
            this->attributes.setKey(info);
            std::cout << "Key: " << attributes.getKey() << '\n';
            info = "";
            while (content[i] != '>')
            {
                //if (content[i] == ' ') break;
                info += content[i++];
            }
            this->attributes.setValue(info);
            std::cout << "Value: " << attributes.getValue() << '\n';
            info = "";     
            i++;
        }
        std::cout << "Key: " << attributes.getKey() << '\n';
        std::cout << "Value: " << attributes.getValue() << '\n';

        if (content[i] != '<')
        {
            while (content[i] != '<')
            {
                info += content[i++];
            }
            flag = true;
            this->text = info;
            std::cout << "Text: " << text << '\n';
            info = "";
        }
        if (content[i] == '<')
        {
            while (content[i + 1] != '/')
            {
                XmlNode* child = new XmlNode;
                childrens.push_back(child->XmlReader(content, i, level + 1));
            }
            if (content[i + 1] == '/' && flag == true)
            {
                while (content[i] != '>') i++;
                i++;
                return this;
            }
            if (content[i + 1] == '/')
            {
                while (content[i] != '>') i++;
                i++;
                return this;
            }
        }
    }
}


//size_t XmlNode::getChildrensSize() const
//{
//	return childrens.size();
//}

XmlNode* XmlNode::searchID(const std::string& id) const
{
    /*for (size_t i = 0; i < childrens.size(); i++)
    {
        if (id == childrens[i]->attributes.getValue()) return childrens[i];
    }*/
    std::cout << childrens.size();
    return nullptr;
}

XmlNode* XmlNode::searchKey(const std::string& key) const
{
    for (size_t i = 0; i < childrens.size(); i++)
    {
        if (childrens[i]->attributes.getKey() == key) return childrens[i];
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

void XmlNode::children(const std::string& id) const
{
    XmlNode* element = searchID(id);
    for (size_t i = 0; i < element->childrens.size(); i++) // Cycles through all childrens
    {
        std::cout << element->childrens[i]->attributes.getKey() << " " << element[i].attributes.getValue() << "\n";
        std::cout << '\n';
    }
}





