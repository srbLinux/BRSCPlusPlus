#ifndef PYTHONINLINE_H
#define PYTHONINLINE_H
/*
*   CopyRight (C) 2021.10.24
*   C++  SXBase PythonInLine
*/

/*
*   This is a Program about coding Python in C++ file.
*   if you want use Python to coding in C++ file,you must be use this such as mine:
*   The Program is base on boost::python.
*   this template is:
*   class CPlusPlusPython
*   {
*       public:
*       string* str;
*       ...
*       python:
*       void ap();
*   };
*   void CPlusPlusPython::ap()
*   {
*       import os
*
*   }
*/
#include <iostream>
#include <type_traits>
#include <boost/python.hpp>
using std::istream;
using namespace boost::python;
class PythonInLine
{
public:
    PythonInLine();
    void ReadProject();
private:

};
#endif
