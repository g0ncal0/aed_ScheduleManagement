//
// Created by Rodrigo Miranda on 19/10/2023.
//


#include "Operation.h"

const std::string ADMIN_PERMISSIONS = "An admin can create new students (1), create new UCs (2), assign Classes to UCs (3) and check students' requests (4) . \nFor more information, you can also list all the information.\n To see all students, insert 20. To see all classes in a UC, insert 21. To see all Ucs, insert 22.";
const std::string USER_PERMISSIONS = "A student can make a request to add a class (1), remove a class (2) and switch classes(3).";


Operation::Operation(AllStudents& students) {
    char answer = 0;
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
            if(std::cin >> studentCode && !std::cin.fail() && studentCode > 0) isValidCode = true;
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
                std::cout << "Invalid input. Please enter a valid positive integer." << std::endl;
            }
        }while(!isValidCode);

        Student* findStudent = students.getStudentPtr(studentCode);

        if(findStudent != nullptr){
            student = findStudent;
        }

        std::string message = (student == nullptr) ? "Sucesso!" : "Não te encontramos na base de dados.";
        std::cout << message << std::endl;
    }else {
        isAdmin = true;
        student = nullptr;
    }
}

bool Operation::is_Administrator() const {return isAdmin;}


void Operation::whatCanIDo() const {
    if(isAdmin){
        std::cout << ADMIN_PERMISSIONS << std::endl;
    }else{
        std::cout << USER_PERMISSIONS << std::endl;
    }
}

bool Operation::acceptRequest() {
    Activity* request = history.lastRequest();
    std::cout << request->getDescription() << std::endl;
    // a partir daqui, chama-se uma das funções que o filipe está a criar para o admin decidir se aceitar
}

void Operation::operate(){
    if(student == nullptr && !isAdmin){
        std::cout << "YOU ARE NOT ALLOWED IN!";
        return;
    }
    std::cout << "Operation to apply: ";
    whatCanIDo();
    int answer;
    bool isValidAnswer = false;
    do {
        if(std::cin >> answer && answer >= 1 && ((isAdmin && answer <= 4) || (!isAdmin && answer <= 3))) {
            if(isAdmin && answer <= 4) isValidAnswer = true;
            else if(!isAdmin && answer <= 3) isValidAnswer = true;
        }
        else{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
            std::cout << "Invalid input. Please enter an integer between 1 and " << (isAdmin ? "4." : "3.") << std::endl;
        }
    }while(!isValidAnswer);
    if(isAdmin){
        switch(answer){
            case 1:
                //createStudent();
                break;
            case 2:
                //createUc();
                break;
            case 3:
                //assignClassToUc();
                break;
            case 4:
                acceptRequest() ? history.requestAccepted() : history.requestDenied();
                break;
        }
    }
    else {
        switch(answer) {
            case 1:
                //addClass();
                break;
            case 2:
                //removeClass();
                break;
            case 3:
                //switchClass();
                break;
        }
    }
}

/*
Student* Operation::getCurrentStudent() {
    return student;
}*/
