//
// Created by Filipe Correia on 15/10/2023.
//

#include "History.h"

void History::addRequest(Activity *request) {
    requests.push(request);
}

History::History() {
    history.push(new Activity(0, "Start of History"));
}

Activity History::lastActivity() {
    if(!history.empty()) return *(history.top());
}

void History::removeActivity() {
    if(!history.empty()) {
        auto toRemove = history.top();
        delete toRemove;
        history.pop();
    }
}
