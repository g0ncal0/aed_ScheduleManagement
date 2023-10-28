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

    const Uc& consult_uc() const;
    const ClassCode& consult_class(const Uc& uc) const;

public:
    Uni(AllUcs ucs, AllStudents students);
    void print_all_ucs() const;
    void print_all_students() const;
    void info();
    void print_schedule_student() const;
    void print_schedule_class() const;
    void print_students_class() const;
    void print_students_course() const;
    void print_students_year() const;
    void print_number_students_in_n_ucs() const;
    void print_class_occupation() const;
};


#endif //UNISCHEDULE_UNI_H
