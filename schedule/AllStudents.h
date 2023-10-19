//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_ALLSTUDENTS_H
#define UNISCHEDULE_ALLSTUDENTS_H

#include "Student.h"
#include <set>

class AllStudents {
private:
    set<Student*> students;

public:
    static Student* getStudent(int id) const ;
    void addStudent(Student* student);
};

#endif //UNISCHEDULE_ALLSTUDENTS_H
