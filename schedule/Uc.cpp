//
// Created by Filipe Correia on 20/10/2023.
//


#include "Unitary.h"


Uc::Uc(std::string ucCode) {
    this->ucCode = ucCode;
}
std::string Uc::getUcCode() const {
    return ucCode;
}
void Uc::addClassCode(ClassCode classCode) {
    //classes.push_back(classcode);

    auto aux = classes.begin();
    while ((aux != classes.end()) && (aux->getClassCode() != classCode.getClassCode())) aux++;

    if (aux == classes.end()){
        classes.push_back(classCode);
    } else {
        aux->addClass(classCode.getFirstClass());
    }
}

ClassCode& Uc::getClassCode(std::string classCode) {
    for(ClassCode &el : classes){
        if(el.getClassCode() == classCode){
            return el;
        }
    }
}

const ClassCode& Uc::getClassCode(std::string classCode) const {
    for(const ClassCode &el : classes){
        if(el.getClassCode() == classCode){
            return el;
        }
    }
}

bool Uc::operator<(const Uc& other) const {
    return ucCode < other.ucCode;
}

ClassCode Uc::getFirstClassCode() const {
    return classes.front();
}

const std::list<ClassCode>& Uc::getClasses() const {
    return classes;
}

void Uc::print() const {
    std::cout << ucCode << std::endl;
    for (const ClassCode& classCode : classes) {
        classCode.print();
    }
}

void Uc::print_classes() const {
    for (const ClassCode& classCode : classes) {
        std::cout << classCode.getClassCode() << '\n';
    }
}

int Uc::ucOccupation() const {
    int res = 0;
    for (const ClassCode& classCode : classes) {
        res += classCode.classOccupation();
    }
    return res;
}