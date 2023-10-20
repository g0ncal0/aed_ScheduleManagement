//
// Created by goncalo on 18-10-2023.
//

#include "AllUcs.h"

//using namespace std;

void AllUcs::addUc(Uc uc) {
    auto aux = ucs.begin();
    while ((aux!=ucs.end()) && (aux->getUcCode()!=uc.getUcCode())) aux++;

    if (aux==ucs.end()) ucs.push_back(uc);

    else {
        aux->addClassCode(uc.getFirstClassCode());
    }

}

void AllUcs::print() const {
    for (Uc uc: ucs) {
        uc.print();
        std::cout << '\n';
    }
}