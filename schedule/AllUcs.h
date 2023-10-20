//
// Created by goncalo on 18-10-2023.
//

#ifndef UNISCHEDULE_ALLUCS_H
#define UNISCHEDULE_ALLUCS_H

#include "Unitary.h"
#include <set>
#include <iostream>

//using namespace std;

class AllUcs {
private:
    std::list<Uc> ucs;

public:
    void addUc(Uc uc);
    Uc* getUc(std::string ucCode);
    void print() const;
};


#endif //UNISCHEDULE_ALLUCS_H