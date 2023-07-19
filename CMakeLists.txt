cmake_minimum_required(VERSION 3.24)
project(AED_FEUP_PROJ_22_23)

set(CMAKE_CXX_STANDARD 14)

add_executable(AED_FEUP_PROJ_22_23 main.cpp
        Classes/Class.h Classes/Class.cpp Classes/UC.h Classes/UC.cpp Classes/Lesson.h Classes/Lesson.cpp
        Classes/Student.h Classes/Student.cpp Classes/RequestApplication.cpp Classes/RequestApplication.h Classes/Menu.cpp Classes/Menu.h Classes/DataBase.cpp Classes/DataBase.h Classes/ListingApplication.cpp Classes/ListingApplication.h Classes/Schedule.cpp Classes/Schedule.h Classes/Request.cpp Classes/Request.h Classes/Application.cpp Classes/Application.h Classes/Pointers.cpp Classes/Pointers.h Classes/Searcher.cpp Classes/Searcher.h Classes/Sorter.cpp Classes/Sorter.h Classes/QuickSort.h)
