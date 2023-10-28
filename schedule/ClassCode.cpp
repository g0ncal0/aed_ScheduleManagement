//
// Created by Filipe Correia on 15/10/2023.
//

#include "Unitary.h"

ClassCode::ClassCode(std::string classCode) {
    this->classCode = classCode;
}

void ClassCode::addStudent(int studentCode, std::string name) {
    std::pair<int, std::string> student(studentCode, name);
    students.push_back(student);
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
    for (std::pair<int, std::string> student : students) {
        std::cout << student.first << " " << student.second << '\n';
    }
}

/*void ClassCode::print_students(const AllStudents& allStudents) const {
    for (int studentCode : students) {
        const Student* student = allStudents.getStudent();
        std::cout << studentCode << " " << student->getStudentCode() << '\n';
    }
}*/

std::list<std::pair<int, std::string>> ClassCode::getStudents() const{
    return students;
}

int ClassCode::classOccupation() const {
    return students.size();
}
