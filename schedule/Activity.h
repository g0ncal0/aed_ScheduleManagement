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
    bool changeMade;

public:
    Activity(int code, std::string description);
    int getCode() const;
    std::string getDescription() const;

    //virtual void revertChanges();
};


class CreateStudent : protected Activity {
public:
    CreateStudent(int code, std::string description);
};

class CreateUc : protected Activity {
public:
    CreateUc(int code, std::string description, Uc* uc);
};

class AssignClassToUc : protected Activity {
private:
    Class* course;
    Uc* uc;
public:
    AssignClassToUc(int code, std::string description, Class* course, Uc* uc);
};

class AddClass : protected Activity {
private:
    Class* course;
public:
    AddClass(int code, std::string description, Class* course);
};

class RemoveClass : protected Activity {
private:
    Class* course;
public:
    RemoveClass(int code, std::string description, Class* course);
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
