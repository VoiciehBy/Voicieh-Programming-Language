#ifndef BUCKET_H
#define BUCKET_H

#include <iostream>

class Bucket {
public:
    Bucket(std::string n="",int v=0) : name(n),value(v) {}
    std::string getName();
    int getValue();

    void setName(std::string nameToBeSet);
    void setValue(int valueToBeSet);

    virtual ~Bucket() {}
private:
    std::string name;
    int value;
};

#endif // BUCKET_H
