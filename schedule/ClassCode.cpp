//
// Created by Filipe Correia on 15/10/2023.
//

#include "ClassCode.h"

ClassCode::ClassCode(std::string classCode) {
    this->classCode = classCode;
}

void ClassCode::addClass(Class class_) {
    classes.push_back(class_);
}

void ClassCode::addStudent(Student *student) {
    students.push_back(student);
}
