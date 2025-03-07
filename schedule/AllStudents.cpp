//
// Created by Filipe Correia on 15/10/2023.
//

#include "AllStudents.h"

const Student* AllStudents::getStudent(int id) const{
    auto it = std::find_if(students.begin(), students.end(), [id](const Student& student){
        return student.getStudentCode() == id;
    });
    if(it != students.end()) return &(*it);
    return nullptr;
}



void AllStudents::addStudent(int studentCode, std::string name){
    Student student(studentCode, name);
    students.insert(student);
}
/**
 * Add a student to the set of students | O(log(n))
 * @param student the student we want to add
 */
void AllStudents::addStudent(Student student) {
    auto it = students.find(student);

    if (it == students.end())
        students.insert(student);

    else {
        Student student1 = *it;
        student1.addClass(student.getFirstClass());
        students.erase(it);
        students.insert(student1);
        for (auto pair : student1.getAllClasses()) {
            ClassCode& c = pair.second;
        }
    }
}
/**
 * Remove a student from the set | O(log(n))
 * @param student Id of student
 */
void AllStudents::removeStudent(int student) {
    auto it = students.find(Student(student, ""));
    if (it != students.end()){
        students.erase(it);
    }
}

void AllStudents::students_year(char year, std::list<std::pair<int, std::string>>& studentsInYear) const {
    for (const Student& student : students) {
        if (student.checkYear(year)) {
            std::pair<int, std::string> pair(student.getStudentCode(), student.getName());
            studentsInYear.push_back(pair);
        }
    }
}

void AllStudents::print() const {
    for(auto s : students){
        std::cout << s.getStudentCode() << ' ' << s.getName() << std::endl;
        s.printSchedule();
        std::cout << std::endl;
    }
}

int AllStudents::studentsInNUcs(int n) const {
    int res = 0;
    for (const Student& student : students) {
        if (student.numberClasses() >= n) res++;
    }
    return res;
}

int AllStudents::yearOccupation(char year) const {
    int res = 0;
    for (const Student& student : students) {
        if (student.checkYear(year)) {
            res++;
        }
    }
    return res;
}

/**
 * Change class of the student. This change affects solely the student. | O(log(n))
 * @param student id of student to be modified
 * @param oldclass class to leave
 * @param newclass class to enter
 * @param uc uc where change is being made
 */
void AllStudents::changeClassStudent(int student, ClassCode& oldclass, ClassCode& newclass, Uc& uc){
    auto updating = students.find(Student(student,""));
    Student newstudent = *updating;
    newstudent.removeClass(oldclass.getClassCode());
    newstudent.addClass(std::pair<Uc&,ClassCode&>(uc,newclass));
    students.erase(updating);
    students.insert(newstudent);
}
/**
 * Remove class of a student. This change affects solely the student. | O(log(n)
 * @param student id of the student to modify
 * @param oldclass class where student will be removed
 * @param uc uc where student will be removed
 */
void AllStudents::removeClassStudent(int student, ClassCode& oldclass, Uc& uc){
    auto updating = students.find(Student(student,""));
    Student newstudent = *updating;
    students.erase(updating);
    newstudent.removeClass(oldclass.getClassCode());
    students.insert(newstudent);
}

/**
 * Add class to a student. This change affects solely the student. | O(log(n)
 * @param student  id of the student to modify
 * @param newclass class where student will be added
 * @param uc uc where student will be added
 */
void AllStudents::addClassStudent(int student, ClassCode& newclass, Uc& uc){
    auto updating = students.find(Student(student,""));
    Student newstudent = *updating;
    students.erase(updating);
    newstudent.addClass(uc,newclass);
    students.insert(newstudent);
}

void AllStudents::save_changes() const {
    std::ofstream changes("../parser/changes.csv");

    if (!changes.is_open()) {
        std::cout << "not ok";
    }

    changes << "StudentCode,StudentName,UcCode,ClassCode\n";
    for (const Student& student : students) {
        const std::list<std::pair<Uc&, ClassCode&>>& classes = student.getAllClasses();
        for (const std::pair<Uc&, ClassCode&>& pair : classes) {
            changes << student.getStudentCode() << ',' << student.getName() << ',' << pair.first.getUcCode() << ',' << pair.second.getClassCode() << '\n';
        }
    }
    changes.close();
}


void AllStudents::deleteStudent(int id){
    auto s = students.find(Student(id, ""));
    students.erase(s);
}