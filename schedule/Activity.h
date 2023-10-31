//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_ACTIVITY_H
#define UNISCHEDULE_ACTIVITY_H
#include <string>
#include <utility>
#include "Unitary.h"



class Activity {
    int code;
    int student;
    std::string old;
    std::string current;
    Uc* uc = nullptr;
public:
    Activity(bool in, int student); // Student inserted
    Activity(int student, std::string old, std::string current, Uc* uc); // Class change
    Activity(bool in, int student,std::string classcode, Uc* uc); // Class insertion (true) or deletion (false)
    int getcode() const { return code;}
    int getStudent(){return student;}
    std::string getOldClassCode(){return old;}
    std::string getClassCode(){return current;}
    Uc* getUc(){ return uc;}
    const std::string getMessage() const;
};




#endif //UNISCHEDULE_ACTIVITY_H
