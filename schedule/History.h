//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_HISTORY_H
#define UNISCHEDULE_HISTORY_H

#include "Activity.h"
#include <stack>

class History {
private:
    std::stack<Activity> history;

public:
    History();
    void addHistory(Activity activity);
    Activity lastActivity();
};


#endif //UNISCHEDULE_HISTORY_H
