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
    Student* getStudent(int id);
    void addStudent(Student* student);

};


#endif //UNISCHEDULE_ALLSTUDENTS_H
