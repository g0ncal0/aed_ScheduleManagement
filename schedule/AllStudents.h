//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_ALLSTUDENTS_H
#define UNISCHEDULE_ALLSTUDENTS_H

#include "Unitary.h"
#include <set>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

class AllStudents {
private:
    std::set<Student> students;

public:
    void addStudent(Student student);
    void addStudent(int studentCode, std::string name);
    const Student* getStudent(int id) const;
    void students_year(char year, std::list<std::pair<int, std::string>>& studentsInYear) const;
    void print() const;
    int studentsInNUcs(int n) const;
    int yearOccupation(char year) const;
    void removeStudent(int student);
    void save_changes() const;
    void changeClassStudent(int student, ClassCode &oldclass, ClassCode &newclass, Uc &uc);
    void removeClassStudent(int student, ClassCode &oldclass, Uc &uc);
    void addClassStudent(int student, ClassCode &newclass, Uc &uc);
    void deleteStudent(int id);
};

#endif //UNISCHEDULE_ALLSTUDENTS_H
