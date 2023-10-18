//
// Created by goncalo on 12-10-2023.
//

#include "Student.h"

using namespace std;

Student::Student(int studentCode, std::string name) {
    this->studentCode = studentCode;
    this->name = name;
}

string Student::getName() {
    return name;
}

int Student::getStudentCode() {
    return studentCode;
}

void Student::addClass(Class* class_) {
    classes.push_back(class_);
}

void Student::removeClass(Class* class_) {
    classes.remove(class_);
}

