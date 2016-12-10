/*
 * Developed with love
 * by @whalemare on 2016.
 */

#ifndef OLGA_PERSON_H
#define OLGA_PERSON_H
#include <string>

using namespace std;

class Person {

private:
    string name;

    string lastname;

public:
//    Person(string name, string lastname);
    Person(string name);

    void setName(string name);

//    void setLastName(string lastname);

    string getName();

//    string getLastName();
};

#endif //OLGA_PERSON_H
