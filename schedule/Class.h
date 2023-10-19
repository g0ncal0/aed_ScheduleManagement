//
// Created by goncalo on 12-10-2023.
//

#ifndef UNISCHEDULE_CLASS_H
#define UNISCHEDULE_CLASS_H

#include <string>

//using namespace std;

class Class {
private:
    char weekday;
    char type;
    float startHour;
    float duration;

public:
    Class(char weekday, float startHour, float duration, char type);
    void print() const;

};

#endif //UNISCHEDULE_CLASS_H
