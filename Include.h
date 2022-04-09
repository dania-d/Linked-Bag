#pragma once
// specifies that the compiler includes the header file only once 
// when compiling a source code file. . It also helps to prevent violations of the 
// one definition rule: the requirement that all templates, types, functions, and 
// objects have no more than one definition in your code.

// have all of the include statements that LinkedBagClient.cpp file needs. 
//#include "LinkedBag.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "LinkedBag.cpp"
#include "LinkedBag340.cpp"
using namespace std;