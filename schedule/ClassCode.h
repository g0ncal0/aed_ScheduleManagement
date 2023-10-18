//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_CLASSCODE_H
#define UNISCHEDULE_CLASSCODE_H

#include <string>
#include "Class.h"
#include <list>
#include "Student.h"

class ClassCode {
private:
    std::string classCode;
    list<Class> classes;
    list<Student*> students;

public:
    ClassCode(std::string classCode);
    void addClass(Class class_);
    void addStudent(Student* student);
};


#endif //UNISCHEDULE_CLASSCODE_H
