//
// Created by Filipe Correia on 15/10/2023.
//

#include "History.h"

void History::addHistory(Activity* activity) {
    history.push(activity);
}


History::History() {
    history.push(new Activity(0, "Start of History"));
}

Activity History::lastActivity() {
    return history.top();
}
