//
// Created by goncalo on 18-10-2023.
//

#include "AllUcs.h"

//
// Created by goncalo on 18-10-2023.
//

#include "AllUcs.h"

void AllUcs::addUc(Uc uc) {
    auto aux = ucs.find(uc);

    if (aux == ucs.end()) ucs.insert(uc);

    else {

    }

}