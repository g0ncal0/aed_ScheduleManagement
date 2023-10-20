//
// Created by goncalo on 12-10-2023.
//

#include "Unitary.h"
#include <iostream>
//using namespace std;

Class::Class( char weekday, float startHour, float duration, char type) {
    this->weekday = weekday;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
}

char Class::getWeekday() const {
    return weekday;
}
float Class::getStartHour() const{
    return startHour;
}

char Class::getType() const {
    return type;
}

float Class::getDuration() const{
    return duration;
}


void Class::print() const {
    std::cout << weekday << ' ' << startHour << ' ' << duration << ' ' << type << std::endl;
}