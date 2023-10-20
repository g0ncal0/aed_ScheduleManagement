//
// Created by goncalo on 18-10-2023.
//

#include <set>
#include "parse.h"

//using namespace std;

void parse() {
    parse_classes();
}

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
    else {
        return '6';
    }
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


AllStudents parse_students(AllUcs ucs){
    std::ifstream classes("students_classes.csv");
    std::string line;

    AllStudents students;
    std::string trash;
    getline(classes, trash);

    int i = 0;
    while (getline(classes,line))
    {
        std::istringstream iss(line);

        std::string stcode, studentname, uccode, classcode;


        getline(iss, stcode, ',');
        getline(iss, studentname, ',');
        getline(iss, uccode, ',');
        getline(iss, classcode, '\r');
        int studentcode = std::stoi(stcode);
        Student* s = students.addStudent(studentcode, studentname);
        Uc* u = ucs.getUc(uccode);
        ClassCode* c = ucs.getUc(uccode)->getClassCode(classcode);

        if(u == nullptr || c == nullptr){
            std::cout << "FOUND IT";
            continue;
        }

        c->addStudent(s);
        s->addClass(u, c);
    }
}
