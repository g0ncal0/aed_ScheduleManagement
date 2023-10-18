//
// Created by Filipe Correia on 15/10/2023.
//

#include "StudentClassChange.h"

StudentClassChange::StudentClassChange(int code, std::string description, Student* student, Class* old, Class* current) : Activity(code, description) {
    this->student = student;
    this->old = old;
    this->current = current;
}


void StudentClassChange::revertChanges(){
    // Revert the changes

}