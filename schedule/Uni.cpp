//
// Created by goncalo on 24-10-2023.
//

#include "Uni.h"

void Uni::addUc(Uc uc) {
    auto aux = ucs.begin();
    while ((aux!=ucs.end()) && (aux->getUcCode()!=uc.getUcCode())) aux++;

    if (aux==ucs.end()) ucs.push_back(uc);

    else {
        aux->addClassCode(uc.getFirstClassCode());
    }

}

Uc* Uni::getUc(std::string ucCode){
    for(Uc &u : ucs){
        if(u.getUcCode() == ucCode){
            return &u;
        }
    }
    return nullptr;
}


void Uni::printUcs() const {
    for (Uc uc: ucs) {
        uc.print();
        std::cout << '\n';
    }
}

void Uni::parseUcs() {
    ucs = parse_classes();
}