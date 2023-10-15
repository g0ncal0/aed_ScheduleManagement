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