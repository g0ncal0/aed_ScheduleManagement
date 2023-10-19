//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_ACTIVITY_H
#define UNISCHEDULE_ACTIVITY_H
#include <string>
#include <utility>

class Activity {
private:
    int code;
    std::string description;

public:
    Activity(int code, std::string description);
    int getCode();
    std::string getDescription();

    //virtual void revertChanges();
};


#endif //UNISCHEDULE_ACTIVITY_H
