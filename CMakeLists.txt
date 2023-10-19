cmake_minimum_required(VERSION 3.25)
project(UNISchedule)

set(CMAKE_CXX_STANDARD 17)

add_executable(UNISchedule schedule/main.cpp schedule/AllUcs.cpp schedule/AllUcs.h schedule/Activity.cpp schedule/Activity.h schedule/Class.h schedule/Student.h schedule/Uc.h schedule/Uc.cpp schedule/Student.cpp schedule/Class.cpp schedule/History.cpp schedule/History.h schedule/StudentClassChange.cpp schedule/StudentClassChange.h schedule/AllStudents.cpp schedule/AllStudents.h schedule/ClassCode.cpp schedule/ClassCode.h schedule/parse.h schedule/parse.cpp)
add_executable(Parse parser/exampleparser.cpp)
