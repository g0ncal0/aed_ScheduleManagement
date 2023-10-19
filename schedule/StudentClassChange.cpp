//
// Created by Filipe Correia on 15/10/2023.
//

#include "StudentClassChange.h"

StudentClassChange::StudentClassChange(int code, std::string description, Student* student, Class* old, Class* current) : Activity(code, description) {
    this->student = student;
    this->old = old;
    this->current = current;
}


// We have to implement here something for actually doing the changes, after being approved by admins. We should also have
// a private member that checks whether we have already executed this change.

/*
void StudentClassChange::revertChanges(){
    // Revert the changes

}*/
