cmake_minimum_required(VERSION 3.5)

project(BRSCPlusPlus VERSION 0.1 LANGUAGES CXX)

file(GLOB_RECURSE QRC_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/SourceFile/*.qrc)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QRC_SOURCE_FILES FilePicture.qrc)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets Sql REQUIRED Core)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Sql REQUIRED Core)
find_package(usr/local/lib)
find_package(usr/local/boost/lib)

qt6_add_resources(QRC_FILES ${QRC_SOURCE_FILES})

source_group("Resource Files" FILES ${QRC_SOURCE_FILES})

include_directories(/usr/include/boost/include)
include_directories(/usr/include/python2.7)

set(PROJECT_SOURCES
        main.cpp
        Mainwindow.cpp
        Mainwindow.h
        Login.h
        Login.cpp
        Register.h
        Register.cpp
        Basefunction.h
        Basefunction.cpp
        MainWindow/TopMenuWindow/Newfolder.h
        MainWindow/TopMenuWindow/Newfolder.cpp
        mos/include/JavaInLine.h
        mos/include/PythonInLine.h
        mos/src/JavaInLine.cpp
        mos/src/PythonInLine.cpp
        MainWindow/TopMenuWindow/Openfloder.h
        MainWindow/TopMenuWindow/Openfloder.cpp
        MainWindow/TopMenuWindow/Newfile.h
        MainWindow/TopMenuWindow/Newfile.cpp
        MainWindow/TopMenuWindow/Alldialog.h
        MainWindow/TopMenuWindow/Alldialog.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(BRSCPlusPlus
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${QRC_FIFES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET BRSCPlusPlus APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(BRSCPlusPlus SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(BRSCPlusPlus
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(BRSCPlusPlus PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::Gui)

set_target_properties(BRSCPlusPlus PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BRSCPlusPlus)
endif()
