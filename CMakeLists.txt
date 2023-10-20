cmake_minimum_required(VERSION 3.25)
project(UNISchedule)

set(CMAKE_CXX_STANDARD 11)


add_executable(UNISchedule schedule/main.cpp schedule/Login.cpp schedule/Login.h schedule/AllUcs.h schedule/Activity.cpp schedule/Activity.h schedule/Class.h schedule/Student.h schedule/Student.cpp schedule/Class.cpp schedule/History.cpp schedule/History.h schedule/AllStudents.cpp schedule/AllStudents.h schedule/ClassCode.cpp schedule/ClassCode.h schedule/utilities.cpp schedule/utilities.cpp schedule/utilities.cpp schedule/utilities.cpp schedule/parse.h schedule/parse.cpp schedule/utilities.h schedule/Uc.cpp schedule/Uc.h schedule/AllUcs.cpp schedule/Unitary.h)

add_executable(Parse parser/exampleparser.cpp)


file(COPY parser/classes.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY parser/classes_per_uc.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY parser/students_classes.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
