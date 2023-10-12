//
// Created by goncalo on 12-10-2023.
//

#ifndef UNISCHEDULE_UC_H
#define UNISCHEDULE_UC_H

#include <string>
#include <vector>
#include "Class.h"

using namespace std;

class Uc {
private:
    string UcCode;
    vector<Class> classes;

public:
    Uc(string UcCode) {
        this->UcCode = UcCode;
    }
    string getUcCode() {
        return UcCode;
    }
    void addClass(Class class_) {
        classes.push_back(class_);
    }
};

#endif //UNISCHEDULE_UC_H

