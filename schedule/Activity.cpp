//
// Created by Filipe Correia on 15/10/2023.
//

#include "Activity.h"


Activity::Activity(bool in, Student *student) {
    this->student = student;
    if(in){
        code = 0;
    } else{
        code = 1;
    }
}

Activity::Activity(Student *student, ClassCode *old, ClassCode *current, Uc* uc) {
    this->student = student;
    this->old = old;
    this->current = current;
    this->uc = uc;
    code = 2;
}

Activity::Activity(bool in, Student *student, ClassCode *c, Uc* uc) {
    this->student = student;
    this->current = c;
    this->uc = uc;
    if(in){
        code = 3;
    }else{
        code = 4;
    }
}


std::string Activity::getMessage() {
    if(!message.empty()){
        return message;
    }
    return student->getName();
}
