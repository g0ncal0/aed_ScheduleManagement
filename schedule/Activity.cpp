//
// Created by Filipe Correia on 15/10/2023.
//

#include "Activity.h"

Activity::Activity(int code, std::string description) {
    this->code = code;
    this->description = description;
}

int Activity::getCode() {
    return code;
}

std::string Activity::getDescription() {
    return description;
}


