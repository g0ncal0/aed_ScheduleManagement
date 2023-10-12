//
// Created by goncalo on 12-10-2023.
//

#include "Class.h"
using namespace std;

Class::Class(string classCode, char weekday, float startHour, float duration, char type) {
    this->classCode = classCode;
    this->weekday = weekday;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
}