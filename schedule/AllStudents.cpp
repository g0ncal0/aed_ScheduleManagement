//
// Created by Filipe Correia on 15/10/2023.
//

#include "AllStudents.h"
#include <algorithm>


const Student* AllStudents::getStudent(int id) const{
    auto it = std::find_if(students.begin(), students.end(), [id](const Student& student){
        return student.getStudentCode() == id;
    });
    if(it != students.end()) return &(*it);
    return nullptr;
}

void AllStudents::addStudent(int studentCode, std::string name){
    Student student(studentCode, name);
    students.insert(student);
}

void AllStudents::addStudent(Student student) {
    auto it = students.find(student);

    if (it == students.end())
        students.insert(student);

    else {
        Student student1 = *it;
        student1.addClass(student.getFirstClass());
        students.erase(it);
        students.insert(student1);
        for (auto pair : student1.getAllClasses()) {
            ClassCode& c = pair.second;
        }
    }

}

void AllStudents::print() {
    for(auto s : students){
        std::cout << s.getStudentCode() << ' ' << s.getName() << std::endl;
        s.printSchedule();
        std::cout << std::endl;
    }
}

