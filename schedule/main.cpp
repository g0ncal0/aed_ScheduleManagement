#include <iostream>


#include "History.h"
#include "parse.h"

int main() {
    /*History test = History();

    test.addHistory(Activity(1, "added some student"));
    std::cout << test.lastActivity().getCode();*/

    AllUcs ucs = parse_classes();
    ucs.print();

    AllStudents students = parse_students(ucs);
    students.print();

    return 0;
}
