//
// Created by Filipe Correia on 15/10/2023.
//

#include "Unitary.h"

ClassCode::ClassCode(std::string classCode) {
    this->classCode = classCode;
}

void ClassCode::addStudent(int studentCode) {
    //std::pair<int, std::string> student(studentCode, name);
    students.push_back(studentCode);
}
void ClassCode::removeStudent(int studentCode) {
    students.remove(studentCode);
}

void ClassCode::addClass(Class class_) {
    classes.push_back(class_);
}
std::string ClassCode::getClassCode() const {
    return classCode;
}

Class& ClassCode::getFirstClass() {
    return classes.front();
}

void ClassCode::print() const {
    std::cout << "   " << classCode << std::endl;
    for (Class class_: classes) {
        class_.print();
    }
}

void ClassCode::print_schedule() const {
    for (Class class_: classes) {
        class_.print();
    }
}

void ClassCode::print_students() const {
    /*for (std::pair<int, std::string> student : students) {
        std::cout << student.first << " " << student.second << '\n';
    }*/
}

std::list<int> ClassCode::getStudents() const{
    return students;
}

int ClassCode::classOccupation() const {
    return students.size();
}


/**
 *
 *
 * */
void ClassCode::getClasses(std::list<std::pair<const Class&, std::string>>& allClasses, std::string ucCode) const {
    for (const Class& class_ : classes) {
        std::pair<const Class&, std::string> pair(class_, ucCode);
        allClasses.push_back(pair);
    }
}

/**
 * returns the practical class of a certain ClassCode
 * */
Class* ClassCode::getPractialClass() const {
    for(auto lecture : classes) {
        if(lecture.getType() != 'T') return &lecture;
    }
    return nullptr;
}