//
// Created by goncalo on 24-10-2023.
//

#ifndef UNISCHEDULE_UNI_H
#define UNISCHEDULE_UNI_H

#include "Unitary.h"
#include "parse.h"
#include "History.h"
#include <algorithm>
#include <iomanip>




class Uni {
private:
    AllUcs ucs;
    AllStudents students;
    bool isAdmin, loggedIn = false;
    int student_id_loggedin = 0;
    History history;


    const Uc & consult_uc() const;
    Uc & consult_uc();
    const ClassCode& consult_class(const Uc& uc) const;
    void students_class(const ClassCode& classCode, std::list<std::pair<int, std::string>>& studentsInClass) const;
    void students_course(const Uc& uc, std::list<std::pair<int, std::string>>& studentsInYear) const;
    void sort_print_students(std::list<std::pair<int, std::string>>& l_students, int aux) const;
    static bool compare_Occupation_UcCode(const std::pair<int, std::string>& p1, const std::pair<int, std::string>& p2);
    static bool compare_students_name(const std::pair<int, std::string>& p1, const std::pair<int, std::string>& p2);
    void print_day(char weekday) const;
    void print_schedule(std::list<std::pair<const Class&, std::string>>& classes) const;
    bool act(Activity activity);
    void actionsforadmin();
    void actionsforuser();
    void enterClass();
    void changeClass();


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
    void print_uc_occupation() const;
    void print_year_occupation() const;
    void print_ucs_more_students() const;

    void login();

    void leaveUC();

    bool actleaveUC(Activity activity);
};


#endif //UNISCHEDULE_UNI_H
