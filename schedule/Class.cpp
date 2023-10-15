//
// Created by goncalo on 12-10-2023.
//

#include "Class.h"
using namespace std;

Class::Class( char weekday, float startHour, float duration, char type) {
    this->weekday = weekday;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
}