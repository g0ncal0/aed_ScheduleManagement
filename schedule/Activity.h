//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_ACTIVITY_H
#define UNISCHEDULE_ACTIVITY_H
#include <string>
#include <utility>
#include "Unitary.h"
#include "Activity.h"



class Activity {
private:
    int code;
    std::string description;

public:
    Activity(int code, std::string description);
    int getCode();
    std::string getDescription();

    //virtual void revertChanges();
};




class StudentClassChange : protected Activity {
private:

    Student* student;
    Class* old;
    Class* current;

public:
    StudentClassChange(int code, std::string description, Student *student, Class *old, Class *current);
    //void revertChanges() override;
};





#endif //UNISCHEDULE_ACTIVITY_H
