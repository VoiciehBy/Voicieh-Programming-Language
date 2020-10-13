#ifndef KEYWORD_H
#define KEYWORD_H

#include <iostream>

class Keyword {
public:
    Keyword(std::string n =" ",std::string d= " ") : name(n),description(d) {}

    std::string getName();

    void setName(std::string nameToBeSet);

    std::string getDescription();

    void setDescription(std::string descriptionToBeSet);

    void show();

    virtual ~Keyword() {}

private:
    std::string name;
    std::string description;
};

#endif // KEYWORD_H
