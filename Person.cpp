/*
 * Developed with love
 * by @whalemare on 2016.
 */

#include "Person.h"

using namespace std;

Person::Person(string name, string lastname) {
    setName(name);
    setLastName(lastname);
}

string Person::getName() {
    return name;
}

string Person::getLastName() {
    return lastname;
}

void Person::setLastName(string lastname) {
    this->lastname = lastname;
}

void Person::setName(string name) {
    this->name = name;
}
