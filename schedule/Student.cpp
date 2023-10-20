//
// Created by goncalo on 12-10-2023.
//

#include "Unitary.h"
#include "utilities.h"

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



void Student::addClass(Uc* uc, ClassCode* class_) {
    classes.push_back(pair<Uc*, ClassCode*>(uc, class_));
}

void Student::removeClass(Class* class_) {
    // HAS TO BE BETTER IMPLEMENTED: Find the pair whose class uses that class and remove that pair
    // classes.remove(class_);
}


void Student::printSchedule(){
    for(pair<Uc*,ClassCode*> c : classes){
        //printSchedule(c);
    }
}

std::list<std::pair<Uc*,ClassCode*>> Student::getAllClasses(){
    return classes;
}

