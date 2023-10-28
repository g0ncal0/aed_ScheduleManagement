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
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
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
    for (int studentCode : classCode.getStudents()) {
        const Student* student = students.getStudent(studentCode);
        std::cout << studentCode << " " << student->getName() << '\n';
    }
}