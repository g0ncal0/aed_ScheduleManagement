//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_ACTIVITY_H
#define UNISCHEDULE_ACTIVITY_H
#include <string>
#include <utility>
#include "Unitary.h"



class Activity {
    int code;
    Student* student;
    ClassCode* old = nullptr;
    ClassCode* current = nullptr;
    Uc* uc = nullptr;
    std::string message;
public:
    Activity(bool in, Student* student); // Student inserted
    Activity(Student* student, ClassCode* old, ClassCode* current, Uc* uc); // Class change
    Activity(bool in, Student* student,ClassCode* c, Uc* uc); // Class insertion (true) or deletion (false)
    int getcode() const { return code;}
    Student* getStudent(){return student;}
    ClassCode* getOldClassCode(){return old;}
    ClassCode* getClassCode(){return current;}
    Uc* getUc(){ return uc;}
    std::string getMessage();
};




#endif //UNISCHEDULE_ACTIVITY_H
