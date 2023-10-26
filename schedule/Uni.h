//
// Created by goncalo on 24-10-2023.
//

#ifndef UNISCHEDULE_UNI_H
#define UNISCHEDULE_UNI_H

#include "Unitary.h"
#include "parse.h"
#include <set>

class Uni {
private:
    AllUcs ucs;
    AllStudents students;

public:
    Uni(AllUcs ucs, AllStudents students);
    void print_all_ucs() const;
    void print_all_students() const;
    void info();
    void print_schedule_student() const;
};


#endif //UNISCHEDULE_UNI_H
