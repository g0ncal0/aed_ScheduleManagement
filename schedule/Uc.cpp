//
// Created by Filipe Correia on 20/10/2023.
//


#include "Unitary.h"


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

    if (aux == classes.end()){
        classes.push_back(classCode);
    } else {
        aux->addClass(classCode.getFirstClass());
    }
}

ClassCode* Uc::getClassCode(std::string classcode){
    for(ClassCode &el : classes){
        if(el.getClassCode() == classcode){
            return &el;
        }
    }
}

bool Uc::operator<(const Uc& other) const {
    return ucCode < other.ucCode;
}

ClassCode Uc::getFirstClassCode() const {
    return classes.front();
}

void Uc::print() const {
    std::cout << ucCode << std::endl;
    for (ClassCode classCode : classes) {
        classCode.print();
    }
}