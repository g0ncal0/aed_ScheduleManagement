cmake_minimum_required(VERSION 3.25)
project(UNISchedule)

set(CMAKE_CXX_STANDARD 11)

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)

add_executable(UNISchedule schedule/main.cpp schedule/AllUcs.h schedule/Activity.cpp schedule/Activity.h  schedule/Student.cpp schedule/Class.cpp schedule/History.cpp schedule/History.h schedule/AllStudents.cpp schedule/AllStudents.h schedule/ClassCode.cpp schedule/utilities.cpp schedule/utilities.cpp schedule/utilities.cpp schedule/utilities.cpp schedule/parse.h schedule/parse.cpp schedule/utilities.h schedule/Uc.cpp  schedule/AllUcs.cpp schedule/Unitary.h
        schedule/Uni.h
        schedule/Uni.cpp)

file(COPY parser/classes.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY parser/classes_per_uc.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY parser/students_classes.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY parser/changes.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR})