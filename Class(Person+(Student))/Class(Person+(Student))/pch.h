#ifndef PCH_H
#define PCH_H
#define _CRT_SECURE_NO_WARNINGS
// ������������� �������������� ��������, ����������� �����
#include <corecrt_math_defines.h>

#include <iostream>
#include <iomanip> // ��� ������������� ������ setw(), setprecision()
#include <Windows.h> // ��� ��������� �������� ����� "���"
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
#include <ciso646> // ��� �++. (��� � iso646.h)
using namespace std;

//���������� ������������� ��������� - ������� ��������
#define rus 1251

//���������� ��������� - ������� ��������� ����� � �������
// ����� ����� �� ������ ����
#define GRAY_ON_BLACK "color 07"

//��� ������������ �������� ����� ������� ������� �������
#define CLEAR "cls"

#endif //PCH_H
#pragma once