//
// Created by goncalo on 12-10-2023.
//

#ifndef UNISCHEDULE_UC_H
#define UNISCHEDULE_UC_H

#include "ClassCode.h"
#include <iostream>
#include <string>
#include <list>

//using namespace std;

class Uc {
private:
    std::string ucCode;
    std::list<ClassCode> classes;

public:
   /* Uc(std::string ucCode);
    std::string getUcCode();
    void addClassCode(ClassCode classCode);
    ClassCode getFirstClassCode() const;
    bool operator<(const Uc& other) const;*/

   Uc(std::string ucCode) {
       this->ucCode = ucCode;
   }

    std::string getUcCode() {
        return ucCode;
    }
    void addClassCode(ClassCode classCode) {
        //classes.push_back(classcode);

        auto aux = classes.begin();
        while ((aux != classes.end()) && (aux->getClassCode() != classCode.getClassCode())) aux++;

        if (aux == classes.end()) classes.push_back(classCode);

        else {
            aux->addClass(classCode.getFirstClass());
        }
    }

    bool operator<(const Uc& other) const {
        return ucCode < other.ucCode;
    }

    ClassCode getFirstClassCode() const {
        return classes.front();
    }

    void print() const {
       std::cout << ucCode << std::endl;
       for (ClassCode classCode : classes) {
           classCode.print();
       }
   }
};

#endif //UNISCHEDULE_UC_H

