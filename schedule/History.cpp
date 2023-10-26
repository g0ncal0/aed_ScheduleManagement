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

Activity History::lastHistory() const {
    if(!history.empty()) return *(history.top());
}

void History::removeHistory() {
    if(!history.empty()) {
        auto toRemove = history.top();
        delete toRemove;
        history.pop();
    }
}

Activity* History::lastRequest() const {
    return requests.front();
}

void History::requestAccepted() {
    Activity* accepted = requests.front();
    history.push(accepted);
    requests.pop();
}

void History::requestDenied() {
    requests.pop();
}
