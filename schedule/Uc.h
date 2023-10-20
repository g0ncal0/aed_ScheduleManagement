//
// Created by goncalo on 12-10-2023.
//

#ifndef UNISCHEDULE_UC_H
#define UNISCHEDULE_UC_H

#include <string>
#include <list>
#include "ClassCode.h"

using namespace std;

class Uc {
private:
    string ucCode;
    list<ClassCode> classes;

public:
    Uc(string ucCode);
    string getUcCode();
    void addClassCode(ClassCode classcode);
    bool operator<(const Uc& other) const;

};

#endif //UNISCHEDULE_UC_H

