# CMake Build File
cmake_minimum_required(VERSION 3.1.0)

file(STRINGS "${CMAKE_SOURCE_DIR}/makespec/VERSION" VERSION)
file(STRINGS "${CMAKE_SOURCE_DIR}/makespec/BUILD_VERSION" BUILD_VERSION)
file(STRINGS "${CMAKE_SOURCE_DIR}/makespec/VERSION_SUFFIX" VERSION_SUFFIX)

project(lsnotes)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VERSION_STRING "${VERSION}${VERSION_SUFFIX}")
set(VERSION_LIST ${VERSION})
string(REPLACE "." ";" VERSION_LIST ${VERSION_LIST})
separate_arguments(VERSION_LIST)

list(GET VERSION_LIST 0 CMAKE_PROJECT_VERSION_MAJOR)
list(GET VERSION_LIST 1 CMAKE_PROJECT_VERSION_MINOR)
list(GET VERSION_LIST 2 CPACK_PACKAGE_VERSION_PATCH)

add_definitions(-DVERSION_STRING="${VERSION_STRING}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

# =========== BUILD MSG ============

message(" ")
message("> Hello! This is lsnotes!")
message("= Version: ${VERSION_STRING}")
message("= Build Version: ${BUILD_VERSION}")
message("= Build Type: ${CMAKE_BUILD_TYPE}")
message("= Build Platform: ${CMAKE_SYSTEM_NAME}")
message("---------------------------")
message("* Open Source on https://github.com/aeilot/lsnotes")
message("* Licenced under MIT")
message("---------------------------")
message("* Check our README.md for more!")
message(" ")

# =========== BUILD SOURCE FILES ============

set(SOURCES
    src/core/dbutils.cpp
        src/core/preferancemanager.cpp
    src/main.cpp
    src/ui/aboutdialog.cpp
    src/ui/mainwindow.cpp
    src/ui/preferancedialog.cpp
    src/core/curlutils.cpp
        src/core/photoutils.cpp src/core/photoutils.h)

add_executable(lsnotes
    ${SOURCES}
)