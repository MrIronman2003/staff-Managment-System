#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <sstream>

using namespace std;
#define el "\n"

// ANSI escape codes for color
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#ifdef _WIN32
#define CLEAR "cls"
#elif _unix_
#define CLEAR "clear"
#elif __APPLE__
#define CLEAR "clear"
#endif

#endif
