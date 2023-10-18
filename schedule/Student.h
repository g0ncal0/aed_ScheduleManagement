//
// Created by goncalo on 12-10-2023.
//

#ifndef UNISCHEDULE_STUDENT_H
#define UNISCHEDULE_STUDENT_H

#include <string>
#include "Class.h"
#include <list>
#include "Uc.h"

using namespace std;

class Student {
private:
    int studentCode;
    string name;
    list<pair<Uc,Class*>> Classes;


public:
    Student(int studentCode, string name);
    string getName() const ;
    bool operator<(const Student& other) const;
    int getStudentCode() const ;
    void addClass(Class* class_);
    void removeClass(Class* class_);
};


#endif //UNISCHEDULE_STUDENT_H
