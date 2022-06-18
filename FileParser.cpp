#include "FileParser.h"

std::string FileParser::removeSpaces(const std::string& line)
{
    std::string newLine = "";
  
    size_t l = 0, r = line.size() - 1;
    while ((line[l] == ' ' || line[r] == ' ') && l <= r)
    {
        if (line[l] == ' ' && line[r] == ' ')
        {
            l++;
            r--;
        }
        else if (line[l] == ' ') l++;
        else if (line[r] == ' ') r--;
    }
    for (size_t i = l; i <= r; i++)
    {
        newLine += line[i];
    }
    return newLine;
}

std::string FileParser::fileParser(std::ifstream& file)
{
    std::string result = "";
    std::string line;
    while (getline(file, line))
    {
        result += FileParser::removeSpaces(line);
    }
    return result;

}



