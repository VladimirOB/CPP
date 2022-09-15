#ifndef PCH_H
#define PCH_H
#define _CRT_SECURE_NO_WARNINGS
// использование математических констант, современный стиль
#include <corecrt_math_defines.h>

#include <iostream>
#include <iomanip> // для манипуляторов вывода setw(), setprecision()
#include <Windows.h> // для поддержки русского языка "тут"
#include <conio.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <string.h>
#include <time.h>
#include <vector>
#include <io.h>
#include <direct.h>
#include <fstream>
#include <stdarg.h>
#include <ciso646> // для С++. (для С iso646.h)
using namespace std;

//объявление символической константы - кодовой страницы
#define rus 1251

//объявление константы - команды включения цвета в консоли
// серые буквы на черном фоне
#define GRAY_ON_BLACK "color 07"

//для единообразия кодируем также команду очистки консоли
#define CLEAR "cls"

#endif //PCH_H
#pragma once