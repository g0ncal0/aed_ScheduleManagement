//
// Created by Filipe Correia on 15/10/2023.
//

#include "AllStudents.h"


Student* AllStudents::getStudent(int id) const {
    auto iterator = std::find_if(students.begin(), students.end(), [id](const Student* student){
        return student->getStudentCode() == id;
    });
    if(iterator != students.end()) return *iterator;
    return nullptr;
}


void AllStudents::addStudent(Student *student) {
    students.insert(student);
}



