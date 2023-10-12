//
// Created by goncalo on 12-10-2023.
//

#ifndef UNISCHEDULE_CLASS_H
#define UNISCHEDULE_CLASS_H

#include <string>

using namespace std;

class Class {
private:
    string classCode;
    char weekday;
    char type;
    float startHour;
    float duration;

public:
    Class(string classCode, char weekday, float startHour, float duration, char type) {
        this->classCode = classCode;
        this->weekday = weekday;
        this->startHour = startHour;
        this->duration = duration;
        this->type = type;
    }


};

#endif //UNISCHEDULE_CLASS_H
