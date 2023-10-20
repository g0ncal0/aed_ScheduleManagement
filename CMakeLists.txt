cmake_minimum_required(VERSION 3.25)
project(UNISchedule)

set(CMAKE_CXX_STANDARD 17)


add_executable(UNISchedule schedule/main.cpp schedule/Activity.cpp schedule/Activity.h schedule/Class.h schedule/Student.h schedule/Uc.h schedule/Uc.cpp schedule/Student.cpp schedule/Class.cpp schedule/History.cpp schedule/History.h schedule/StudentClassChange.cpp schedule/StudentClassChange.h schedule/AllStudents.cpp schedule/AllStudents.h schedule/ClassCode.cpp schedule/ClassCode.h schedule/utilities.cpp schedule/utilities.cpp schedule/utilities.cpp schedule/utilities.cpp schedule/parse.h schedule/parse.cpp)

add_executable(Parse parser/exampleparser.cpp)


file(COPY parser/classes.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY parser/classes_per_uc.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY parser/students_classes.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
