/*
//
// Created by goncalo on 12-10-2023.
//

#include "Uc.h"

//using namespace std;

Uc::Uc(std::string ucCode) {
    this->ucCode = ucCode;
}

std::string Uc::getUcCode() {
    return ucCode;
}
void Uc::addClassCode(ClassCode classCode) {
    //classes.push_back(classcode);

    auto aux = classes.begin();
    while ((aux != classes.end()) && (aux->getClassCode() != classCode.getClassCode())) aux++;

    if (aux == classes.end()) classes.push_back(classCode);

    else {
        aux->addClass(classCode.getFirstClass());
    }
}

bool Uc::operator<(const Uc& other) const {
    return ucCode < other.ucCode;
}

ClassCode Uc::getFirstClassCode() const {
    return classes.front();
}*/
