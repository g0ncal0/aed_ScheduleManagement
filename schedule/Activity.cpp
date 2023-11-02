//
// Created by Filipe Correia on 15/10/2023.
//

#include "Activity.h"


Activity::Activity(bool in, int student) {
    this->student = student;
    if(in){
        code = 0;
    } else{
        code = 1;
    }
}

Activity::Activity(int student, std::string old, std::string current, Uc* uc) {
    this->student = student;
    this->old = old;
    this->current = current;
    this->uc = uc;
    code = 2;
}

Activity::Activity(bool in, int student, std::string classcode, Uc* uc) {
    this->student = student;
    this->current = classcode;
    this->uc = uc;
    if(in){
        code = 3;
    }else{
        code = 4;
    }
}

/**
 * Get a summary of the Activity
 * @return String with a brief description
 */
const std::string Activity::getMessage() const{
    switch(code){
        case 0:
            return "Creation of student " + std::to_string(student);
        case 1:
            return "Deletion of student " + std::to_string(student);
        case 2:
            return "Student " + std::to_string(student) + " changed from " + old + " to " + current + " at " + uc->getUcCode();
        case 3:
            return "Student " + std::to_string(student)  + " joined the class " + current + " at " + uc->getUcCode();
        case 4:
            return "Student " +std::to_string(student)+ " left the class " + current + " at " + uc->getUcCode();
    }
    return "Activity not recognized";
}
