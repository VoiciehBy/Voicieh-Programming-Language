#include "Keyword.h"

std::string Keyword::getName() {
    return name;
}
void Keyword::setName(std::string nameToBeSet) {
    name = nameToBeSet;
}
std::string Keyword::getDescription() {
    return description;
}
void Keyword::setDescription(std::string descriptionToBeSet) {
    description = descriptionToBeSet;
}
void Keyword::show()
{
    std::cout << "<" << name << ">" << "::=" << description << std::endl;
}
