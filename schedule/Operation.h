//
// Created by Rodrigo Miranda on 19/10/2023.
//

#ifndef UNISCHEDULE_OPERATION_H
#define UNISCHEDULE_OPERATION_H


#include "Unitary.h"
#include "AllStudents.h"
#include "History.h"
#include <limits>


class Operation {
private:
    bool isAdmin, loggedIn = false;
    const Student* student;
    History history;

public:
     Operation(AllStudents& students);
     bool is_Administrator() const;
     void operate();
     void whatCanIDo() const;
     bool acceptRequest();
    Student* getCurrentStudent();

};


#endif //UNISCHEDULE_OPERATION_H
