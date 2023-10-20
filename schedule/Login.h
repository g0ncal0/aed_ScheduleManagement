//
// Created by Rodrigo Miranda on 19/10/2023.
//

#ifndef UNISCHEDULE_LOGIN_H
#define UNISCHEDULE_LOGIN_H


#include "Unitary.h"
#include "AllStudents.h"
#include <iostream>
#include <limits>

class Login {
private:
    bool isAdmin;
    Student* student;

public:
     Login();
     bool is_Administrator() const;
     void Operate();
     void WhatCanIdo();

};


#endif //UNISCHEDULE_LOGIN_H
