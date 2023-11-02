#include <iostream>


#include "History.h"
#include "parse.h"
#include "Uni.h"

int main() {

    AllUcs ucs = parse_classes();
    AllStudents students = parse_students(ucs);
    Uni uni = Uni(ucs, students);
    //uni.print_all_ucs();
    //uni.print_all_students();
    char check;
    do {
        uni.login();
        std::cout << "\nDo you want to exit? s/n ";
        std::cin >> check;
    } while (check != 's');

    //Operation op = Operation(students);
    //op.operate();
    // We can get the current student with op.getCurrentStudent();
    return 0;
}
