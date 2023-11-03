//
// Created by Filipe Correia on 20/10/2023.
//


#include "Unitary.h"


Uc::Uc(std::string ucCode) {
    this->ucCode = ucCode;
}
std::string Uc::getUcCode() const {
    return ucCode;
}



void Uc::addClassCode(ClassCode classCode) {

    auto aux = classes.begin();
    while ((aux != classes.end()) && (aux->getClassCode() != classCode.getClassCode())) aux++;

    if (aux == classes.end()){
        classes.push_back(classCode);
    } else {
        aux->addClass(classCode.getFirstClass());
    }
}



ClassCode& Uc::getClassCode(std::string classCode) {
    for(ClassCode &el : classes){
        if(el.getClassCode() == classCode){
            return el;
        }
    }
}

const ClassCode& Uc::getClassCode(std::string classCode) const {
    for(const ClassCode &el : classes){
        if(el.getClassCode() == classCode){
            return el;
        }
    }
}

bool Uc::operator<(const Uc& other) const {
    return ucCode < other.ucCode;
}

ClassCode Uc::getFirstClassCode() const {
    return classes.front();
}

const std::list<ClassCode>& Uc::getClasses() const {
    return classes;
}


/**
 *  Checks if the classCode already exists | O(n)
 *  @param classCode string that identifies the classCode
 * */
bool Uc::classCodeExists(std::string classCode) const {
    for(const ClassCode &el : classes){
        if(el.getClassCode() == classCode){
            return true;
        }
    }
    return false;
}

void Uc::print() const {
    std::cout << ucCode << std::endl;
    for (const ClassCode& classCode : classes) {
        classCode.print();
    }
}

void Uc::print_classes() const {
    for (const ClassCode& classCode : classes) {
        std::cout << classCode.getClassCode() << '\n';
    }
}

int Uc::ucOccupation() const {
    int res = 0;
    for (const ClassCode& classCode : classes) {
        res += classCode.classOccupation();
    }
    return res;
}

/**
 * Function to get the minimum occupation of all the classes of the UC | O(n)
 * @return the number of students in the least populated class
 */
int Uc::minOcupation(){
    int min = 1000;
    for(ClassCode c : classes){
        int numberstudentsinclass = c.classOccupation();
        if(numberstudentsinclass < min){
            min = numberstudentsinclass;
        }
    }
    return min;
}


/**
 * Function to get the maximum occupation of all the classes of the UC | O(n)
 * @return the number of students in the most populated class
 */
int Uc::maxOcupation(){
    int max = 0;
    for(ClassCode c : classes){
        int numberstudentsinclass = c.classOccupation();
        if(numberstudentsinclass > max){
            max = numberstudentsinclass;
        }
    }
    return max;
}


/**
 * Function to do the operation of a class change
 * @param student studentCode of the student to change
 * @param leave ClassCode to exit
 * @param current ClassCode to enter
 * @return true if change is done and possible. false if change is not possible
 */
bool Uc::changeClass(int student, ClassCode* leave, ClassCode* enter){
    // ver se horário interseta com uma não teórica
    // classcode é apenas de uma uc
    // função chamada a partir de Uni

    if(enter->classOccupation() >= MAX_STUDENTS_CLASS || ((abs(enter->classOccupation() - minOcupation()) > DIFFERENCE_ACCEPTABLE_EQULIBRIUM && enter->classOccupation() >= maxOcupation()))){
        return false;
    }
    leave->removeStudent(student);
    enter->addStudent(student);
    return true;
}
