#include <iostream>
#include "Person.h"

using namespace std;

int main() {
    Person *p = new Person("Olga", "Turkina");

    cout << p->getLastName() << endl;
    return 0;
}