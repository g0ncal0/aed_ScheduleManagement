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

const int DIFFERENCE_ACCEPTABLE_EQULIBRIUM = 4;
const int MAX_STUDENTS_CLASS = 30;

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
    void printSchedule() const;
    std::list<std::pair<Uc&, ClassCode&>> getAllClasses();
    const std::list<std::pair<Uc&, ClassCode&>>& getAllClasses() const;
    bool checkYear(char year) const;
    int numberClasses() const;
    void getClasses(std::list<std::pair<const Class&, std::string>>& allClasses) const;
    void removeClass(std::string class_);

    const ClassCode &getClassCode(std::string uc) const;

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
    bool operator<(const Class& class2) const;
    void print() const;
};

class ClassCode {
private:
    std::string classCode;
    std::list<Class> classes;
    std::list<int> students;

public:
    ClassCode(std::string classCode);
    void addStudent(int studentCode);
    void removeStudent(int studentCode);
    void addClass(Class class_);
    std::string getClassCode() const ;
    Class& getFirstClass();
    void print() const;
    void print_schedule() const;
    void print_students() const;
    std::list<int> getStudents() const;
    int classOccupation() const;
    void getClasses(std::list<std::pair<const Class&, std::string>>& allClasses, std::string ucCode) const;

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
    const std::list<ClassCode>& getClasses() const;
    bool classCodeExists(std::string classCode) const;
    void print() const;
    void print_classes() const;
    int ucOccupation() const;

    bool changeClass(int student, std::string leave, std::string current);
    int minOcupation();

};

#endif //UNISCHEDULE_UNITARY_H
