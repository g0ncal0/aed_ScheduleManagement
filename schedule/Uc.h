//
// Created by goncalo on 12-10-2023.
//

#ifndef UNISCHEDULE_UC_H
#define UNISCHEDULE_UC_H

#include <string>
#include <list>
#include "Class.h"

using namespace std;

class Uc {
private:
    string ucCode;
    list<Class> classes;

public:
    Uc(string ucCode);
    string getUcCode();
    void addClass(Class class_);
};

#endif //UNISCHEDULE_UC_H

