#include <iostream>


#include "History.h"
#include "parse.h"
#include "Operation.h"

int main() {

    AllUcs ucs = parse_classes();
    ucs.print();

    AllStudents students = parse_students(ucs);
    students.print();

    Operation op = Operation(students);
    op.Operate();
    // We can get the current student with op.getCurrentStudent();
    return 0;
}
