//
// Created by Rodrigo Miranda on 19/10/2023.
//

#include "Login.h"

const std::string ADMIN_PERMISSIONS = "An admin can create new students (1), create new UCs (2), assign Classes to UCs (3), . \nFor more information, you can also list all the information.\n To see all students, insert 20. To see all classes in a UC, insert 21. To see all Ucs, insert 22.";
const std::string USER_PERMISSIONS = "An admin can ";


Login::Login() {
    char answer;
    while(answer != 's' && answer != 'n') {
        std::cout << "Are you a student? s/n" << std::endl;
        std::cin >> answer;
        answer = tolower(answer);
    }
    if(answer == 's') {
        isAdmin = false;
        int studentCode;
        std::cout << "What is your student code?" << std::endl;
        bool isValidCode = false;
        do {
            std::cin >> studentCode;
            if(!std::cin.fail() && studentCode > 0) isValidCode = true;
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
                std::cout << "Invalid input. Please enter a valid positive integer." << std::endl;
            }
        }while(!isValidCode);
        Student* findStudent = new Student(20, "Test");//AllStudents::getStudent(studentCode);
        if(findStudent != nullptr) student = findStudent;
        std::string message = student == nullptr ? "Sucesso!" : "Não te encontramos na base de dados.";
        std::cout << message << std::endl;
    }else {
        isAdmin = true;
        student = nullptr;
    }
}

bool Login::is_Administrator() const {return isAdmin;}


void Login::WhatCanIdo() {
    if(isAdmin){
        std::cout << ADMIN_PERMISSIONS;
    }else{
        std::cout << USER_PERMISSIONS;
    }
}

void Login::Operate(){
    std::cout << "Opperation to apply: ";
    int answer;
    std::cin >> answer;

    if(isAdmin){
        switch(answer){
            case 0:
                WhatCanIdo();
                break;
        }
    }
}
