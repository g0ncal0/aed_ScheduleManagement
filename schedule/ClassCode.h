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
    list<Student*> students; // We don't want to store the students in this list. Solely the pointer to the student.

public:
    ClassCode(std::string classCode);
    void addClass(Class class_);
    void addStudent(Student* student);
};


#endif //UNISCHEDULE_CLASSCODE_H
