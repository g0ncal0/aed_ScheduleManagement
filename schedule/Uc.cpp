//
// Created by goncalo on 12-10-2023.
//

#include "Uc.h"

using namespace std;

Uc::Uc(string ucCode) {
    this->ucCode = ucCode;
}

string Uc::getUcCode() {
    return ucCode;
}
void Uc::addClass(Class class_) {
    classes.push_back(class_);
}