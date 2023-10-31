//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_HISTORY_H
#define UNISCHEDULE_HISTORY_H

#include "Activity.h"
#include <stack>
#include <queue>

class History {
private:
    std::stack<Activity> history;
    std::queue<Activity> requests;

public:
    History();
    void addRequest(Activity request);
    void removeHistory();
    void requestAccepted();
    void requestDenied();
    std::string lastHistory() const;
    std::string lastRequest() const;
    Activity lastRequestAct() const;

    Activity *lastRequestPtr() const;
};


#endif //UNISCHEDULE_HISTORY_H
