//
// Created by Filipe Correia on 15/10/2023.
//

#include "Activity.h"

Activity::Activity(int code, std::string description) {
    this->code = code;
    this->description = description;
    this->changeMade = false;
}

int Activity::getCode() const {
    return code;
}

std::string Activity::getDescription() const{
    return description;
}



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



