//
// Created by goncalo on 18-10-2023.
//

#include "parse.h"
#include <iostream>

char weekdayToChar(const std::string& weekday) {
    if (weekday == "Monday") {
        return '0';
    }
    else if (weekday == "Tuesday") {
        return '1';
    }
    else if (weekday == "Wednesday") {
        return '2';
    }
    else if (weekday == "Thursday") {
        return '3';
    }
    else if (weekday == "Friday") {
        return '4';
    }
    else if (weekday == "Saturday") {
        return '5';
    }
    return '6';
}

char typeToChar(const std::string& type) {
    if (type == "T") {
        return 'T';
    }
    else if (type == "TP") {
        return 'P';
    }
    else {
        return 'L';
    }
}
/**
 * Parses the classes used in the classes.csv file | In the best case cenario: O(n)
 * @return
 */
AllUcs parse_classes() {
    std::ifstream classes("classes.csv");
    std::string line;

    AllUcs ucs;
    std::string trash;
    getline(classes, trash);

    if (!classes.is_open()) {
        std::cout << "not ok";
        return ucs;
    }

    while (getline(classes,line))
    {
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream iss(line);

        std::string classCode, ucCode, weekday, type;
        float startHour, duration;

        iss >> classCode >> ucCode >> weekday >> startHour >> duration >> type;

        Class class_(weekdayToChar(weekday), startHour, duration, typeToChar(type));
        ClassCode classC(classCode);
        classC.addClass(class_);
        Uc uc(ucCode);
        uc.addClassCode(classC);
        ucs.addUc(uc);

    }

    classes.close();

    return ucs;
}

/**
 * Parse data about students either from the original file or from the last saved changes file into the data structures. | Best case scenario: O(n)
 * @param ucs List of the UCs parsed previously. This data structure may be modified.
 * @return
 */
AllStudents parse_students(AllUcs& ucs){
    std::string filename;
    char aux;
    std::cout << "Do you want to use the saved changes? s/n ";
    std::cin >> aux;
    if (aux == 's') filename = "../parser/changes.csv";
    else filename = "students_classes.csv";
    std::ifstream classes(filename);
    std::string line;

    AllStudents students;
    std::string trash;
    getline(classes, trash);

    while (getline(classes,line))
    {
        std::istringstream iss(line);

        std::string stCode, studentName, ucCode, classCode;

        getline(iss, stCode, ',');
        getline(iss, studentName, ',');
        getline(iss, ucCode, ',');
        getline(iss, classCode, '\r');
        int studentCode = std::stoi(stCode);

        Student student(studentCode, studentName);
        Uc& uc = ucs.getUc(ucCode);
        ClassCode& classC = uc.getClassCode(classCode);
        student.addClass(uc, classC);
        students.addStudent(student);
    }

    classes.close();
    return students;
}