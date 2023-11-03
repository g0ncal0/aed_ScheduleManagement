//
// Created by goncalo on 18-10-2023.
//

#include "AllUcs.h"


void AllUcs::addUc(Uc uc) {
    auto aux = ucs.begin();
    while ((aux!=ucs.end()) && (aux->getUcCode()!=uc.getUcCode())) aux++;

    if (aux==ucs.end()) ucs.push_back(uc);

    else {
        aux->addClassCode(uc.getFirstClassCode());
    }

}

Uc& AllUcs::getUc(std::string ucCode){
    for(Uc &u : ucs){
        if(u.getUcCode() == ucCode){
            return u;
        }
    }
}

std::list<std::string> AllUcs::getUcCodes() const {
    std::list<std::string> allUcs;
    for(const Uc& u : ucs){
        allUcs.push_back(u.getUcCode());
    }
    return allUcs;
}

/**
 * Function to get the object UC using its code. | O(n)
 * @param ucCode uc code of the uc we want
 * @return
 */
const Uc& AllUcs::getUc(std::string ucCode) const {
    for(const Uc &u : ucs){
        if(u.getUcCode() == ucCode){
            return u;
        }
    }
}
/**
 * Function to check if a uc exists | O(n)
 * @param ucCode uc code of the uc we want to check
 * @return Returns a boolean indicating if a uc exists in the list of UCs
 */
bool AllUcs::ucExists(std::string ucCode) const {
    for(const Uc &u : ucs){
        if(u.getUcCode() == ucCode){
            return true;
        }
    }
    return false;
}

void AllUcs::print() const {
    for (Uc uc: ucs) {
        uc.print();
        std::cout << '\n';
    }
}

void AllUcs::print_ucs() const {
    for (Uc uc: ucs) {
        std::cout << uc.getUcCode() << '\n';
    }
}

void AllUcs::list_Occupation_UcCode(std::list<std::pair<int, std::string>>& occupation_UcCode) const {
    for (const Uc& uc : ucs) {
        std::pair<int, std::string> pair(uc.ucOccupation(), uc.getUcCode());
        occupation_UcCode.push_back(pair);
    }
}