//
// Created by Rodrigo Miranda on 19/10/2023.
//

#include "Login.h"
#include "AllStudents.h"
#include <iostream>

Login::Login() {
    char answer;
    while(answer != 's' && answer != 'n') {
        std::cout << "Are you a student? s/n" << endl;
        std::cin >> answer;
        answer = tolower(answer);
    }
    if(answer == 's') {
        isAdmin = false;
        int studentCode;
        std::cout << "What is your student code?" << endl;
        bool isValidCode = false;
        do {
            std::cin >> studentCode;
            if(!std::cin.fail() && studentCode > 0) isValidCode = true;
            else {
                cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
                std::cout << "Invalid input. Please enter a valid positive integer." << std::endl;
            }
        }while(!isValidCode);
        Student* findStudent = AllStudents::getStudent(studentCode);
        if(findStudent != nullptr) student = findStudent;
        std::string message = student == nullptr ? "Sucesso!" : "Não te encontramos na base de dados.";
        std::cout << message << std::endl;
    }else {
        isAdmin = true;
        student = nullptr;
    }
}

bool Login::is_Administrator() const {return isAdmin;}