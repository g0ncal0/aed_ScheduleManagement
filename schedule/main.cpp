#include <iostream>


#include "History.h"
#include "parse.h"
#include "Uni.h"

int main() {

    AllUcs ucs = parse_classes();
    AllStudents students = parse_students(ucs);
    Uni uni = Uni(ucs, students);

    char check;
    do {
        uni.login();
        std::cout << "\nDo you want to exit? s/n ";
        std::cin >> check;
    } while (check != 's');


     return 0;
}
