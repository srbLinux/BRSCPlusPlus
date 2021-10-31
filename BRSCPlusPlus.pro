QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    Mainwindow.cpp \
    Login.cpp   \
    Register.cpp \
    MainWindow/LeftToolWindow/ProjectFileTree.cpp \
    MainWindow/TopMenuWindow/Aboutbrs.cpp \
    MainWindow/TopMenuWindow/Alldialog.cpp \
    MainWindow/TopMenuWindow/BuildAction.cpp \
    MainWindow/TopMenuWindow/Newfile.cpp \
    MainWindow/TopMenuWindow/Newfolder.cpp \
    mos/src/JavaInLine.cpp \
    mos/src/PythonInLine.cpp

HEADERS += \
    Mainwindow.h \
    Register.h \
    Login.h \
    MainWindow/LeftToolWindow/ProjectFileTree.h \
    MainWindow/TopMenuWindow/Aboutbrs.h \
    MainWindow/TopMenuWindow/Alldialog.h \
    MainWindow/TopMenuWindow/BuildAction.h \
    MainWindow/TopMenuWindow/Newfile.h \
    MainWindow/TopMenuWindow/Newfolder.h \
    mos/include/JavaInLine.h \
    mos/include/PythonInLine.h
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MainWindow/LeftToolWindow/image_source.qrc
