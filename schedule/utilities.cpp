//
// Created by Filipe Correia on 19/10/2023.
//
#include "Class.h"
#include <list>
#include <iostream>

bool compare_class (const Class& first, const Class& second)
{
    if(first.getWeekday() < second.getWeekday()){
        return true;
    }
    if(first.getWeekday() == second.getWeekday()){
        if(first.getStartHour() < second.getStartHour()){
            return true;
        }
    }
    return false;
}

list<Class> order_classes(list<Class> classes){
    classes.sort(compare_class);
    return classes;
}


void printSchedule(list<Class> classes){
    classes = order_classes(classes);
    char weekday = -1;
    for(auto el : classes){
        if(el.getWeekday() != weekday){
            weekday = el.getWeekday();
            std::cout << "DAY " << weekday;
        }
        cout << el.getStartHour() << el.getDuration();
    }
}
