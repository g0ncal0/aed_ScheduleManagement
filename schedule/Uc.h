//
// Created by goncalo on 12-10-2023.
//

#ifndef UNISCHEDULE_UC_H
#define UNISCHEDULE_UC_H

#include "ClassCode.h"
#include <string>
#include <list>

//using namespace std;

class Uc {
private:
    std::string ucCode;
    std::list<ClassCode> classes;

public:
    Uc(std::string ucCode);
    std::string getUcCode();
    void addClassCode(ClassCode classCode);
    ClassCode getFirstClassCode() const;
    bool operator<(const Uc& other) const;
};

#endif //UNISCHEDULE_UC_H

