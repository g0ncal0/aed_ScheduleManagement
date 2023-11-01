//
// Created by goncalo on 12-10-2023.
//

#include "Unitary.h"
#include "utilities.h"

using namespace std;

Student::Student(int studentCode, std::string name) {
    this->studentCode = studentCode;
    this->name = name;
}

/**
 * getter of student name
 * @return student name
 */
string Student::getName() const {
    return name;
}

bool Student::operator<(const Student &other) const {
    return studentCode < other.studentCode;
}

int Student::getStudentCode() const {
    return studentCode;
}

void Student::addClass(Uc& uc, ClassCode& class_) {
    class_.addStudent(studentCode);
    classes.push_back(pair<Uc&, ClassCode&>(uc, class_));
}

void Student::removeClass(std::string class_) {
    // HAS TO BE BETTER IMPLEMENTED: Find the pair whose class uses that class and remove that pair

    for(auto it = classes.begin(); it != classes.end(); it++){
        if(class_ == it->second.getClassCode()){
            classes.erase(it);
            break;
        }
    }
}



void Student::printSchedule() const {
    for(pair<Uc&, ClassCode&> c : classes){
        std::cout << "   " << c.first.getUcCode() << "\n" << "  ";
        c.second.print();
    }
}

std::list<std::pair<Uc&, ClassCode&>> Student::getAllClasses(){
    return classes;
}

const std::list<std::pair<Uc&, ClassCode&>>& Student::getAllClasses() const {
    return classes;
}

std::pair<Uc&, ClassCode&> Student::getFirstClass() const {
    return classes.front();
}

void Student::addClass(std::pair<Uc&, ClassCode&> class_){
    classes.push_back(class_);
}

bool Student::checkYear(char year) const {
    for (std::pair<Uc&,ClassCode&> pair : classes) {
        if (year == pair.second.getClassCode()[0]) return true;
    }
    return false;
}

int Student::numberClasses() const {
    return classes.size();
}

void Student::getClasses(std::list<std::pair<const Class&, std::string>>& allClasses) const {
    for (const std::pair<Uc&,ClassCode&>& pair : classes) {
        pair.second.getClasses(allClasses, pair.first.getUcCode());
    }
}

const ClassCode& Student::getClassCode(std::string uc) const{
    for(auto el: classes){ // MD turma 3, apenas tem aulas de MD
        if(el.first.getUcCode() == uc){
            return el.second;
        }
    }
}
