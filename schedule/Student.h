//
// Created by goncalo on 12-10-2023.
//

#ifndef UNISCHEDULE_STUDENT_H
#define UNISCHEDULE_STUDENT_H

#include <string>
#include "Class.h"
#include <list>

using namespace std;

class Student {
private:
    int studentCode;
    string name;
    list<Class*> Classes;


public:
    Student(int studentCode, string name);
    string getName();
};


#endif //UNISCHEDULE_STUDENT_H
