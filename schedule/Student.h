//
// Created by goncalo on 12-10-2023.
//

#ifndef UNISCHEDULE_STUDENT_H
#define UNISCHEDULE_STUDENT_H

#include <string>

using namespace std;

class Student {
private:
    string studentCode;
    string name;
    //definir como fazer a lista das turmas inscritas
public:
    Student(string studentCode, string name);
    string getName();
};


#endif //UNISCHEDULE_STUDENT_H
