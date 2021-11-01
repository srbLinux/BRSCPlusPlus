QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Abstract.cpp \
    Settings/Plugins/FontAdmin.cpp \
    Settings/SettingsAdmin.cpp \
    main.cpp \
    Mainwindow.cpp \
    Login.cpp   \
    Register.cpp \
    MainWindow/LeftToolWindow/ProjectFileTree.cpp \
    MainWindow/TopMenuWindow/Aboutbrs.cpp \
    MainWindow/TopMenuWindow/Alldialog.cpp \
    MainWindow/TopMenuWindow/Newfile.cpp \
    MainWindow/TopMenuWindow/Newfolder.cpp \
    mos/src/JavaInLine.cpp \
    mos/src/PythonInLine.cpp

HEADERS += \
    Abstract.h \
    Mainwindow.h \
    Register.h \
    Login.h \
    MainWindow/LeftToolWindow/ProjectFileTree.h \
    MainWindow/TopMenuWindow/Aboutbrs.h \
    MainWindow/TopMenuWindow/Alldialog.h \
    MainWindow/TopMenuWindow/Newfile.h \
    MainWindow/TopMenuWindow/Newfolder.h \
    Settings/Plugins/FontAdmin.h \
    Settings/SettingsAdmin.h \
    mos/include/JavaInLine.h \
    mos/include/PythonInLine.h \

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    MainWindow/LeftToolWindow/image_source.qrc \
    Settings/Plugins/CoreFont/Font.qrc
