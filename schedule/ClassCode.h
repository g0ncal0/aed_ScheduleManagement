//
// Created by Filipe Correia on 15/10/2023.
//

#ifndef UNISCHEDULE_CLASSCODE_H
#define UNISCHEDULE_CLASSCODE_H

#include <string>
#include "Class.h"
#include <list>
#include "Student.h"
//#include "ClassCode.h"

class ClassCode {
private:
    std::string classCode;
    std::list<Class> classes;
    //list<Student*> students; // We don't want to store the students in this list. Solely the pointer to the student.

public:
   /* ClassCode(std::string classCode);
    void addClass(Class class_);
    //void addStudent(Student* student);
    std::string getClassCode() const;
    Class getFirstClass() const;*/

   ClassCode(std::string classCode) {
       this->classCode = classCode;
   }
   void addClass(Class class_) {
       classes.push_back(class_);
   }
   std::string getClassCode() const {
       return classCode;
   }

   Class getFirstClass() const {
       return classes.front();
   }
};


#endif //UNISCHEDULE_CLASSCODE_H
