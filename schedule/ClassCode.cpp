//
// Created by Filipe Correia on 15/10/2023.
//



#include "Unitary.h"

ClassCode::ClassCode(std::string classCode) {
    this->classCode = classCode;
}

void ClassCode::addStudent(Student* student) {
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

/*std::list<Student&> ClassCode::getStudents() {
    return students;
}*/

