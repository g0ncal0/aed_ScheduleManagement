//
// Created by goncalo on 24-10-2023.
//

#include "Uni.h"

Uni::Uni(AllUcs ucs, AllStudents students) {
    this->ucs = ucs;
    this->students = students;
}

void Uni::print_all_ucs() const {
    ucs.print();
}

void Uni::print_all_students() const {
    students.print();
}

const Uc& Uni::consult_uc() const {
    std::cout << "List of UCs:\n\n";
    ucs.print_ucs();
    std::cout << "\nPlease enter the UC you want to consult: ";
    std::string ucCode;
    std::cin >> ucCode;
    return ucs.getUc(ucCode);
}

const ClassCode& Uni::consult_class(const Uc& uc) const {
    std::cout << "\nList of classes:\n\n";
    uc.print_classes();
    std::cout << "\nPlease enter the class you want to consult: ";
    std::string classCode;
    std::cin >> classCode;
    return uc.getClassCode(classCode);
}

bool Uni::compare_Occupation_UcCode(const std::pair<int, std::string>& p1, const std::pair<int, std::string>& p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    else return p1.second < p2.second;
}

void Uni::info() {
    std::cout << "What do you want to consult?\n\n";
    std::cout << "1. Schedule of a student\n";
    std::cout << "2. Schedule of a class\n";
    std::cout << "3. Students of a class\n";
    std::cout << "4. Students of a course\n";
    std::cout << "5. Students of a year\n";
    std::cout << "6. Number of students registered in at least n UCs\n";
    std::cout << "7. Class occupation\n";
    std::cout << "8. Course occupation\n";
    std::cout << "9. Year occupation\n";
    std::cout << "10. Consult the UCs with the greatest number of students\n\n";

    std::cout << "Enter a number: ";
    int op;
    std::cin >> op;

    switch (op) {
        case 1:
            print_schedule_student();
            break;
        case 2:
            print_schedule_class();
            break;
        case 3:
            print_students_class();
            break;
        case 4:
            print_students_course();
            break;
        case 5:
            print_students_year();
            break;
        case 6:
            print_number_students_in_n_ucs();
            break;
        case 7:
            print_class_occupation();
            break;
        case 8:
            print_uc_occupation();
            break;
        case 9:
            print_year_occupation();
            break;
        case 10:
            print_ucs_more_students();
            break;
    }
}

void Uni::print_schedule_student() const {
    std::cout << "Please enter the student code: ";
    int studentCode;
    std::cin >> studentCode;
    const Student* student = students.getStudent(studentCode);
    student->printSchedule();
}

void Uni::print_schedule_class() const {
    const Uc& uc = consult_uc();
    const ClassCode& classCode = consult_class(uc);
    std::cout << "\nSchedule of " << uc.getUcCode() << "-" << classCode.getClassCode() << ":\n";
    classCode.print_schedule();
}

void Uni::print_students_class() const {
    const Uc& uc = consult_uc();
    const ClassCode& classCode = consult_class(uc);
    std::cout << "\nStudents of " << uc.getUcCode() << "-" << classCode.getClassCode() << ":\n\n";
    classCode.print_students();
}

void Uni::print_students_course() const {
    const Uc& uc = consult_uc();
    std::cout << "\nStudents of " << uc.getUcCode() << ":\n\n";
    uc.print_students();
}

void Uni::print_students_year() const {
    std::cout << "What year do you want do consult?\n\n1.\n2.\n3.\n";
    char year;
    std::cin >> year;
    std::cout << "\nStudents of year " << year << ":\n\n";
    students.print_students_year(year);
}

void Uni::print_number_students_in_n_ucs() const {
    std::cout << "Number minimum of ucs? ";
    int n;
    std::cin >> n;
    std::cout << "Number of students in at least " << n << " UCs: " << students.studentsInNUcs(n);
}

void Uni::print_class_occupation() const {
    const Uc& uc = consult_uc();
    const ClassCode& classCode = consult_class(uc);
    std::cout << "Occupation of " << uc.getUcCode() << "-" << classCode.getClassCode() << ": " << classCode.classOccupation();
}

void Uni::print_uc_occupation() const {
    const Uc& uc = consult_uc();
    std::cout << "Occupation of " << uc.getUcCode() << ": " << uc.ucOccupation();
}

void Uni::print_year_occupation() const {
    std::cout << "What year do you want do consult?\n\n1.\n2.\n3.\n";
    char year;
    std::cin >> year;
    std::cout << "\nOccupation of year " << year << ": " << students.yearOccupation(year);
}

void Uni::print_ucs_more_students() const {
    std::list<std::pair<int, std::string>> occupation_UcCode;
    ucs.list_Occupation_UcCode(occupation_UcCode);
    occupation_UcCode.sort(compare_Occupation_UcCode);
    std::cout << "\nList of UCs with the greatest number of students:\n";
    for (const std::pair<int, std::string>& pair : occupation_UcCode) {
        std::cout << pair.second << " - " << pair.first << " students\n";
    }
}