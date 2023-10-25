//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_ALLSTUDENTS_H
#define UNISCHEDULE_ALLSTUDENTS_H

#include "Unitary.h"
#include <set>
#include <algorithm>

class AllStudents {
private:
    std::set<Student> students;

public:
    void addStudent(Student student);
    void addStudent(int studentCode, std::string name);
    Student* getStudent(int id) const;
    void print();
};

#endif //UNISCHEDULE_ALLSTUDENTS_H
