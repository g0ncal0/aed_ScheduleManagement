//
// Created by goncalo on 12-10-2023.
//

#include "Student.h"

using namespace std;

Student::Student(int studentCode, std::string name) {
    this->studentCode = studentCode;
    this->name = name;
}

string Student::getName() const {
    return name;
}

bool Student::operator<(const Student &other) const {
    return studentCode < other.studentCode;
}

int Student::getStudentCode() const {
    return studentCode;
}

void Student::addClass(Class* class_) {
    classes.push_back(class_);
}

void Student::removeClass(Class* class_) {
    classes.remove(class_);
}


void Student::printSchedule(){
    for(pair<Uc*,Class*> c : Classes){

    }
}


