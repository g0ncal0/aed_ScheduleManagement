//
// Created by Rodrigo Miranda on 19/10/2023.
//

#ifndef UNISCHEDULE_OPERATION_H
#define UNISCHEDULE_OPERATION_H


#include "Unitary.h"
#include "AllStudents.h"
#include <limits>

class Operation {
private:
    bool isAdmin;
    bool loggedin = false;
    Student* student;

public:
     Operation(AllStudents& students);
     bool is_Administrator() const;
     void Operate();
     void WhatCanIdo();
     Student* getCurrentStudent();

};


#endif //UNISCHEDULE_OPERATION_H
