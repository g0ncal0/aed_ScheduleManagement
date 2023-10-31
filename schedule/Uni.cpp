//
// Created by goncalo on 24-10-2023.
//

#include "Uni.h"


const std::string ADMIN_PERMISSIONS = "An admin can create new students (1), create new UCs (2), assign Classes to UCs (3) and check students' requests (4) . \nFor more information, you can also list all the information.\n To see all students, insert 20. To see all classes in a UC, insert 21. To see all Ucs, insert 22.";
const std::string USER_PERMISSIONS = "A student can make a request to add a class (1), remove a class (2) and switch classes(3).";



Uni::Uni(AllUcs ucs, AllStudents students) {
    this->ucs = ucs;
    this->students = students;
    history = History();
}

void Uni::print_all_ucs() const {
    ucs.print();
}

void Uni::print_all_students() const {
    students.print();
}

const Uc & Uni::consult_uc() const {
    std::cout << "List of UCs:\n\n";
    ucs.print_ucs();
    std::cout << "\nPlease enter the UC you want to consult: ";
    std::string ucCode;
    std::cin >> ucCode;
    return ucs.getUc(ucCode);
}
Uc & Uni::consult_uc() {
    std::cout << "List of UCs:\n\n";
    ucs.print_ucs();
    std::cout << "\nPlease enter the UC you want to consult: ";
    std::string ucCode;
    std::cin >> ucCode;
    return ucs.getUc(ucCode);
}

const ClassCode& Uni::consult_class(const Uc& uc) const {
    std::cout << "\nList of classes:\n\n";
    uc.print_classes();
    std::cout << "\nPlease enter the class you want to consult: ";
    std::string classCode;
    std::cin >> classCode;
    return uc.getClassCode(classCode);
}

void Uni::students_class(const ClassCode& classCode, std::list<std::pair<int, std::string>>& studentsInClass) const {
    for (int studentCode : classCode.getStudents()) {
        const Student* student = students.getStudent(studentCode);
        std::pair<int, std::string> pair(studentCode, student->getName());
        studentsInClass.push_back(pair);
    }
}

void Uni::students_course(const Uc& uc, std::list<std::pair<int, std::string>>& studentsInCourse) const {
    const std::list<ClassCode>& classes = uc.getClasses();
    for (ClassCode classCode : classes) {
        students_class(classCode, studentsInCourse);
    }
}

void Uni::sort_print_students(std::list<std::pair<int, std::string>>& l_students, int aux) const {
    if (aux == 1) {
        l_students.sort();
        for (std::pair<int, std::string> pair : l_students) {
            std::cout << pair.first << " " << pair.second << '\n';
        }
    }
    else {
        l_students.sort(compare_students_name);
        for (std::pair<int, std::string> pair : l_students) {
            std::cout << pair.second << " " << pair.first << '\n';
        }
    }
}

bool Uni::compare_Occupation_UcCode(const std::pair<int, std::string>& p1, const std::pair<int, std::string>& p2) {
    if (p1.first != p2.first) return p1.first > p2.first;
    else return p1.second < p2.second;
}

bool Uni::compare_students_name(const std::pair<int, std::string>& p1, const std::pair<int, std::string>& p2) {
    if (p1.second != p2.second) return p1.second < p2.second;
    else return p1.first < p2.first;
}

void Uni::print_day(char weekday) const {
    if (weekday == '0') {
        std::cout << "   Monday:\n";
    }
    else if (weekday == '1') {
        std::cout << "   Tuesday:\n";
    }
    else if (weekday == '2') {
        std::cout << "   Wednesday:\n";
    }
    else if (weekday == '3') {
        std::cout << "   Thursday:\n";
    }
    else if (weekday == '4') {
        std::cout << "   Friday:\n";
    }
    else if (weekday == '5') {
        std::cout << "   Saturday:\n";
    }
    else {
        std::cout << "   Sunday:\n";
    }
}

void Uni::print_schedule(std::list<std::pair<const Class&, std::string>>& classes) const {
    classes.sort();
    char weekday = '0';
    for (std::pair<const Class&, std::string> class_ : classes) {
        if (class_.first.getWeekday() >= weekday) {
            weekday = class_.first.getWeekday() + 1;
            print_day(class_.first.getWeekday());
        }
        float startHour = class_.first.getStartHour();
        float endHour = startHour + class_.first.getDuration();
        int s_h = (int)startHour;
        int s_m = (int)(((float)startHour-s_h) * 60);
        int e_h = (int)endHour;
        int e_m = (int)(((float)endHour-e_h) * 60);
        std::string type;
        switch (class_.first.getType()) {
            case 'T':
                type = "T";
                break;
            case 'P':
                type = "TP";
                break;
            case 'L':
                type = "PL";
                break;
        }
        std::cout << "      " << std::setw(2) << std::setfill('0') << s_h << ':' << std::setw(2) << std::setfill('0') << s_m << '-' << std::setw(2) << std::setfill('0') << e_h << ':' << std::setw(2) << std::setfill('0') << e_m << "   " << type << "   " << class_.second << '\n';
    }
}

void Uni::info() {
    std::cout << "What do you want to consult?\n\n";
    std::cout << "1. Schedule of a student\n";
    std::cout << "2. Schedule of a class\n";
    std::cout << "3. Students of a class\n";
    std::cout << "4. Students of a course\n";
    std::cout << "5. Students of a year\n";
    std::cout << "6. Number of students registered in at least n UCs\n";
    std::cout << "7. Class occupation\n";
    std::cout << "8. Course occupation\n";
    std::cout << "9. Year occupation\n";
    std::cout << "10. Consult the UCs with the greatest number of students\n";
    std::cout << "11. Process Requests and Make Changes\n";
    std::cout << "12. See All Students \n\n";


    std::cout << "Enter a number: ";
    int op;
    std::cin >> op;

    switch (op) {
        case 1:
            print_schedule_student();
            break;
        case 2:
            print_schedule_class();
            break;
        case 3:
            print_students_class();
            break;
        case 4:
            print_students_course();
            break;
        case 5:
            print_students_year();
            break;
        case 6:
            print_number_students_in_n_ucs();
            break;
        case 7:
            print_class_occupation();
            break;
        case 8:
            print_uc_occupation();
            break;
        case 9:
            print_year_occupation();
            break;
        case 10:
            print_ucs_more_students();
            break;
        case 11:
            actionsforadmin();
            break;
        case 12:
            print_all_students();
            break;
    }
}

void Uni::print_schedule_student() const {
    std::cout << "Please enter the student code: ";
    int studentCode;
    std::cin >> studentCode;
    const Student* student = students.getStudent(studentCode);
    std::list<std::pair<const Class&, std::string>> classes;
    student->getClasses(classes);
    std::cout << "Schedule of " << studentCode << "-" << student->getName() << ":\n";
    print_schedule(classes);
}

void Uni::print_schedule_class() const {
    const Uc& uc = consult_uc();
    const ClassCode& classCode = consult_class(uc);
    std::list<std::pair<const Class&, std::string>> classes;
    classCode.getClasses(classes, uc.getUcCode());
    std::cout << "\nSchedule of " << uc.getUcCode() << "-" << classCode.getClassCode() << ":\n";
    print_schedule(classes);
}

void Uni::print_students_class() const {
    const Uc& uc = consult_uc();
    const ClassCode& classCode = consult_class(uc);
    std::list<std::pair<int, std::string>> studentsInClass;
    students_class(classCode, studentsInClass);
    std::cout << "\nIn what order do you want to sort the information?\n1.By student code\n2.By student name\n";
    int aux;
    std::cin >> aux;
    std::cout << "\nStudents of " << uc.getUcCode() << "-" << classCode.getClassCode() << ":\n\n";
    sort_print_students(studentsInClass, aux);
}

void Uni::print_students_course() const {
    const Uc& uc = consult_uc();
    std::list<std::pair<int, std::string>> studentsInCourse;
    students_course(uc, studentsInCourse);
    std::cout << "\nIn what order do you want to sort the information?\n1.By student code\n2.By student name\n";
    int aux;
    std::cin >> aux;
    std::cout << "\nStudents of " << uc.getUcCode() << ":\n\n";
    sort_print_students(studentsInCourse, aux);
}

void Uni::print_students_year() const {
    std::cout << "What year do you want do consult?\n\n1.\n2.\n3.\n";
    char year;
    std::cin >> year;
    std::list<std::pair<int, std::string>> studentsInYear;
    students.students_year(year, studentsInYear);
    std::cout << "\nIn what order do you want to sort the information?\n1.By student code\n2.By student name\n";
    int aux;
    std::cin >> aux;
    std::cout << "\nStudents of year " << year << ":\n\n";
    sort_print_students(studentsInYear, aux);
}

void Uni::print_number_students_in_n_ucs() const {
    std::cout << "Number minimum of ucs? ";
    int n;
    std::cin >> n;
    std::cout << "Number of students in at least " << n << " UCs: " << students.studentsInNUcs(n);
}

void Uni::print_class_occupation() const {
    const Uc& uc = consult_uc();
    const ClassCode& classCode = consult_class(uc);
    std::cout << "Occupation of " << uc.getUcCode() << "-" << classCode.getClassCode() << ": " << classCode.classOccupation();
}

void Uni::print_uc_occupation() const {
    const Uc& uc = consult_uc();
    std::cout << "Occupation of " << uc.getUcCode() << ": " << uc.ucOccupation();
}

void Uni::print_year_occupation() const {
    std::cout << "What year do you want do consult?\n\n1.\n2.\n3.\n";
    char year;
    std::cin >> year;
    std::cout << "\nOccupation of year " << year << ": " << students.yearOccupation(year);
}

void Uni::print_ucs_more_students() const {
    std::list<std::pair<int, std::string>> occupation_UcCode;
    ucs.list_Occupation_UcCode(occupation_UcCode);
    occupation_UcCode.sort(compare_Occupation_UcCode);
    std::cout << "\nList of UCs with the greatest number of students:\n";
    for (const std::pair<int, std::string>& pair : occupation_UcCode) {
        std::cout << pair.second << " - " << pair.first << " students\n";
    }
}




void Uni::changeClass(){
    Uc& uc = consult_uc();  // uc we will work with
    std::string old, current;
    std::cout << "Class to leave:";
    std::cin >> old;
    std::cout << "Class to enter:";
    std::cin >> current;

    history.addRequest(Activity(student_id_loggedin, old, current, &uc));
}

void Uni::enterClass(){
    Uc& uc = consult_uc();  // uc we will work with
    std::string current;
    std::cout << "Class to enter:";
    std::cin >> current;
    history.addRequest( Activity(true, student_id_loggedin, current, &uc));
}

void Uni::leaveUC(){
    Uc& uc = consult_uc();  // uc we will work with
    const ClassCode& classcode = students.getStudent(student_id_loggedin)->getClassCode(uc.getUcCode());
    history.addRequest(Activity(false,student_id_loggedin,classcode.getClassCode(),&uc));
}
/**
 * Helper function to guide student to actions he can perform
 */
void Uni::actionsforuser(){

    std::cout << "0. Change Class in UC\n1. Enter new UC\n2. Leave a UC\n\n";
    std::cout << "Enter a number: ";
    int op;
    std::cin >> op;
    switch(op){
        case 0:
            changeClass();
            break;
        case 1:
            enterClass();
            break;
        case 2:
            leaveUC();
            break;

    }


}




/**
 * Helper function that understands what admin wants to do and acts.
 */
void Uni::actionsforadmin(){
    if(!isAdmin){
        return;
    }
    std::cout << "0. Do nothing\n1. Check last Request\n2. Accept last Request\n3. Reject last Request\n4. Check last History Activity\n5. Add new student\n";
    std::cout << "Enter a number: ";
    int op;
    std::cin >> op;

    bool done = false;
    switch(op){
    case 0:
        break;
    case 1:
        std::cout << history.lastRequest() << "\n";
        break;
    case 2:
        try{
            done = act(history.lastRequestAct());
            std::cout << "Successfully done.\n";
            history.requestAccepted();
        }catch (...) {
            std::cout << "Exception occurred.";
        }
        if(!done){
            std::cout << "Request doesn't fit rules. Removed.\n";
            history.requestDenied();

        }

        break;
    case 3:
        history.requestDenied();
        break;
    case 4:
        std::cout << history.lastHistory() << std::endl;
        break;
    case 5:
        int id;
        std::cout << "first name:";
        std::string first;
        std::cin >> first;
        std::cout << "last name:";
        std::string last;
        std::cin >> last;
        std::cout << "id:";
        std::cin >> id;
        history.addRequest(Activity(true, id));
        students.addStudent(id, first + last);
        history.requestAccepted();
        break;
}
}

bool Uni::actleaveUC(Activity activity){
    activity.getUc()->getClassCode(activity.getClassCode()).removeStudent(activity.getStudent());
    ClassCode& old = activity.getUc()->getClassCode(activity.getClassCode());
    students.removeClassStudent(activity.getStudent(),old, *activity.getUc());
    return true;
}

bool Uni::act(Activity activity){
    bool done = true;
    switch(activity.getcode()){
        case 2:
            if(students.getStudent(activity.getStudent())->numberClasses() < 7 ){
                done = activity.getUc()->changeClass(activity.getStudent(), activity.getOldClassCode(), activity.getClassCode());
                // check if we can continue changing the class in the user level.
                if(done){
                    ClassCode& old = activity.getUc()->getClassCode(activity.getOldClassCode());
                    ClassCode& future = activity.getUc()->getClassCode(activity.getOldClassCode());
                    students.changeClassStudent(activity.getStudent(),old, future, *activity.getUc());
                }
            }else{
                done = false;
            }
            break;
        case 4:
            // leave class
            done = actleaveUC(activity);
            break;
        case 3:
            // join a class
            ClassCode& classC = activity.getUc()->getClassCode(activity.getClassCode());
            if(abs(activity.getUc()->minOcupation() - classC.classOccupation()) < 4){
                classC.addStudent(activity.getStudent());
                students.addClassStudent(activity.getStudent(), classC, *activity.getUc());
            }else{done = false;}
            break;

    }
    return done;
}









void Uni::login() {
    char answer;
    bool isValidInput = false;
    while (!isValidInput) {
        std::cout << "Are you a student? s/n" << std::endl;
        std::cin >> answer;
        answer = tolower(answer);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (answer == 's' || answer == 'n') {
            isValidInput = true; // A entrada é válida, sai do loop
        } else {
            std::cout << "Invalid input. Please enter 's' or 'n'." << std::endl;
        }
    }
    if (answer == 's') {
        isAdmin = false;
        int studentCode;
        std::cout << "What is your student code?" << std::endl;
        bool isValidCode = false;
        do {
            if (std::cin >> studentCode && !std::cin.fail() && studentCode > 0) isValidCode = true;
            else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descartar a entrada inválida
                std::cout << "Invalid input. Please enter a valid positive integer." << std::endl;
            }
        } while (!isValidCode);
        const Student *findStudent = students.getStudent(studentCode);


        if (findStudent != nullptr) {
            student_id_loggedin = studentCode;
            std::cout << "Welcome, " << findStudent->getName() << std::endl;
        }
        if (findStudent == nullptr) {
            std::cout << "It seems that we don't have that student code in our Database." << std::endl;
        }

    } else {
            isAdmin = true;
            student_id_loggedin = 0;
    }

    if(isAdmin){
        info();
    }else{
        actionsforuser();
    }
    std::cout << "YOU WERE LOGGED OUT OF YOUR ACCOUNT \n";
}
