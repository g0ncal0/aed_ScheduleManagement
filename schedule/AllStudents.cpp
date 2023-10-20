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

Student* AllStudents::addStudent(int studentCode, std::string name){
    Student* r = new Student(studentCode, name);
    students.insert(r);
    return r;
}

void AllStudents::addStudent(Student *student) {
    students.insert(student);
}


void AllStudents::print() {
    for(auto s : students){
        s->printSchedule();
    }
}


