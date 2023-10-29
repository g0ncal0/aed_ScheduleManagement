//
// Created by Filipe Correia on 19/10/2023.
//

#include <list>
#include <iostream>
#include "utilities.h"


/*
bool compare_class(const std::pair<const Uc&,const Class&>& first, const std::pair<const Uc&,const Class&>& second)
{
    if(first.second.getWeekday() < second.second.getWeekday()){
        return true;
    }
    if(first.second.getWeekday() == second.second.getWeekday()){
        if(first.second.getStartHour() < second.second.getStartHour()){
            return true;
        }
    }
    return false;
}

std::list<std::pair<Uc*,Class*>> order_classes(std::list<std::pair<Uc*,Class*>> classes){
    //classes.sort(compare_class);
    return classes;
}


void printSchedule(std::list<std::pair<Uc*,Class*>> classes){
    classes = order_classes(classes);
    char weekday = -1;
    for(auto el : classes){
        if(el.second->getWeekday() != weekday){
            weekday = el.second->getWeekday();
            std::cout << "DAY " << weekday;
        }
        std::cout << "Starting: " << el.second->getStartHour() << " | Duration: " << el.second->getDuration() << "\n";
    }
}
*/

