//
// Created by Filipe Correia on 20/10/2023.
//

#ifndef UNISCHEDULE_UNITARY_H
#define UNISCHEDULE_UNITARY_H


#include <string>
#include <list>
#include <iostream>
#include <set>
#include <utility>

class Uc;
class Student;
class ClassCode;
class Class;


class Student {
private:
    int studentCode;
    std::string name;
    std::list<std::pair<Uc&,ClassCode&>> classes;

public:
    Student(int studentCode, std::string name);
    std::string getName() const;
    bool operator<(const Student& other) const;
    int getStudentCode() const;
    void addClass(Uc& uc, ClassCode& class_);
    void addClass(std::pair<Uc&, ClassCode&> class_);
    std::pair<Uc&, ClassCode&> getFirstClass() const;
    void removeClass(Class& class_);
    void printSchedule() const;
    std::list<std::pair<Uc&, ClassCode&>> getAllClasses();
    bool checkYear(char year) const;
    int numberClasses() const;
};

class Class {
private:
    char weekday;
    char type;
    float startHour;
    float duration;

public:
    Class(char weekday, float startHour, float duration, char type);
    char getWeekday() const;
    float getStartHour() const;
    char getType() const;
    float getDuration() const;
    void print() const;
};

class ClassCode {
private:
    std::string classCode;
    std::list<Class> classes;
    std::list<std::pair<int, std::string>> students;

public:
    ClassCode(std::string classCode);
    void addStudent(int studentCode, std::string name);
    void addClass(Class class_);
    std::string getClassCode() const ;
    Class& getFirstClass();
    void print() const;
    void print_schedule() const;
    void print_students() const;
    //void print_students(const AllStudents& allStudents) const;
    std::list<std::pair<int, std::string>> getStudents() const;
    int classOccupation() const;
};



class Uc {
private:
    std::string ucCode;
    std::list<ClassCode> classes;

public:
    Uc(std::string ucCode);

    std::string getUcCode() const;
    void addClassCode(ClassCode classCode);

    bool operator<(const Uc& other) const;
    ClassCode& getClassCode(std::string classCode);
    const ClassCode& getClassCode(std::string classCode) const;
    ClassCode getFirstClassCode() const;
    void print() const;
    void print_classes() const;
    void print_students() const;
    int ucOccupation() const;
};

#endif //UNISCHEDULE_UNITARY_H
