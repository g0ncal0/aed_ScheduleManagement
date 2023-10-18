//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_STUDENTCLASSCHANGE_H
#define UNISCHEDULE_STUDENTCLASSCHANGE_H

#include "Student.h"
#include "Activity.h"
#include "Class.h"
#include <string>

class StudentClassChange : protected Activity {
private:

    Student* student;
    Class* old;
    Class* current;

public:
    StudentClassChange(int code, std::string description, Student *student, Class *old, Class *current);
    void revertChanges() override;
};


#endif //UNISCHEDULE_STUDENTCLASSCHANGE_H
