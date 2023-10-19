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
void Uc::addClassCode(ClassCode classcode) {
    classes.push_back(classcode);
}

bool Uc::operator<(const Uc& other) const {
    return ucCode < other.ucCode;
}