#include "Bucket.h"
std::string Bucket::getName() {
    return name;
}

int Bucket::getValue() {
    return value;
}

void Bucket::setName(std::string nameToBeSet) {
    name = nameToBeSet;
}

void Bucket::setValue(int valueToBeSet) {
    value = valueToBeSet;

}
