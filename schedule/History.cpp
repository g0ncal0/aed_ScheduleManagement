//
// Created by Filipe Correia on 15/10/2023.
//

#include "History.h"

void History::addRequest(Activity request) {

    requests.push(request);
}

History::History() {

}

std::string History::lastHistory() const {
    if(!history.empty()) return history.top().getMessage();
    return "No history available";
}

Activity History::lastHistoryObj() {
    return history.top();
}

void History::removeHistory() {
    if(!history.empty()) {
        history.pop();
    }
}



std::string History::lastRequest() const {
    if(requests.empty()){
        return "No requests Available";
    }
    return requests.front().getMessage();
}
Activity History::lastRequestAct() const{
    return requests.front();
}


void History::requestAccepted() {
    Activity accepted = requests.front();
    history.push(accepted);
    requests.pop();
}

void History::requestDenied() {
    requests.pop();
}
