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
    const Student* getStudent(int id) const;
    void print() const;
    void print_students_year(char year) const;
    int studentsInNUcs(int n) const;
};

#endif //UNISCHEDULE_ALLSTUDENTS_H
