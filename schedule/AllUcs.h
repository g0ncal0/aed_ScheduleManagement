//
// Created by goncalo on 18-10-2023.
//

#ifndef UNISCHEDULE_ALLUCS_H
#define UNISCHEDULE_ALLUCS_H

#include "Uc.h"
#include <set>

using namespace std;

class AllUcs {
private:
    std::set<Uc> ucs;

public:
    void addUc(Uc uc);
    Uc* getUc(string ucCode);

};


#endif //UNISCHEDULE_ALLUCS_H