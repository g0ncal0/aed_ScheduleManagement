#include <iostream>


#include "History.h"

int main() {
    History test = History();

    test.addHistory(Activity(1, "added some student"));
    std::cout << test.lastActivity().getCode();

    return 0;
}
