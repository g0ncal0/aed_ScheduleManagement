//
// Created by goncalo on 12-10-2023.
//

#ifndef UNISCHEDULE_STUDENT_H
#define UNISCHEDULE_STUDENT_H

#include "Uc.h"
#include <string>
#include "Class.h"
#include <list>
#include "ClassCode.h"
#include <utility>

//using namespace std;

class Student {
private:
    int studentCode;
    std::string name;
    //std::list<std::pair<Uc*,Class*>> classes;


public:
    Student(int studentCode, std::string name);
    std::string getName() const ;
    bool operator<(const Student& other) const;
    int getStudentCode() const ;
    void addClass(Class* class_);
    void removeClass(Class* class_);
    void printSchedule();
};


#endif //UNISCHEDULE_STUDENT_H
