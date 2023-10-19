//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_ALLSTUDENTS_H
#define UNISCHEDULE_ALLSTUDENTS_H

#include "Student.h"
#include <set>

class AllStudents {
private:
    set<Student*> students; // We don't want to store the students in this list. Solely the pointer to the student.

public:
    static Student* getStudent(int id) const ;
    void addStudent(Student* student);
};

#endif //UNISCHEDULE_ALLSTUDENTS_H
