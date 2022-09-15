#include <windows.h>
#include "resource.h"
#include <iostream>
#include <vector>
using namespace std;
#define ID_EDIT 10001
#define ID_BUTTON0 1000
#define ID_BUTTON1 1001
#define ID_BUTTON2 1002
#define ID_BUTTON3 1003
#define ID_BUTTON4 1004
#define ID_BUTTON5 1005
#define ID_BUTTON6 1006
#define ID_BUTTON7 1007
#define ID_BUTTON8 1008
#define ID_BUTTON9 1009
#define ID_BUTTONPLUS 2001
#define ID_BUTTONMINUS 2002
#define ID_BUTTONMP 2003
#define ID_BUTTONDIV 2004
#define ID_BUTTONRES 2005
#define ID_BUTTONCLEAR 2006
#define ID_BUTTONCLEAR2 2007
#define ID_BUTTONPOINT 2008
#define ID_BUTTONNEG 2009
#define ID_BUTTONPERCENT 2010
#define ID_BUTTONMPLUS 2011
#define ID_BUTTONMMINUS 2012
#define ID_BUTTONMCLEAR 2013
#define ID_BUTTONMWATCH 2014
// название класса окна
char className[] = "WindowClass1";

// структура, хран€ща€ информацию о сообщении
MSG msg;

HWND button[24];

HWND buttonPlus, buttonResult;

HWND hEdit;

vector <string> v; // дл€ memory

HFONT hFont = NULL;

//HFONT hFont = CreateFont(13, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,
//    OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
//    DEFAULT_PITCH | FF_DONTCARE, TEXT("Tahoma"));

char temp[100], buffer[100], memory[400], memTemp[100];
char firstValue[100], secondValue[100];
double first, second, result;
size_t flag = 0, cnt=0, codeNum = 0;


// оконна€ функци€
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam) 
{
    switch (msg) 
    {
        case WM_CREATE:
        {
            hEdit = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT | ES_NUMBER, 10, 20, 310, 65, wnd, (HMENU)ID_EDIT, 0, 0);

            button[codeNum++] = CreateWindow("button", "0", WS_CHILD | WS_VISIBLE, 87, 339, 80, 50, wnd, (HMENU)ID_BUTTON0, 0, 0);
            button[codeNum++] = CreateWindow("button", "1", WS_CHILD | WS_VISIBLE, 4, 286, 80, 50, wnd, (HMENU)ID_BUTTON1, 0, 0);
            button[codeNum++] = CreateWindow("button", "2", WS_CHILD | WS_VISIBLE, 87, 286, 80, 50, wnd, (HMENU)ID_BUTTON2, 0, 0);
            button[codeNum++] = CreateWindow("button", "3", WS_CHILD | WS_VISIBLE, 168, 286, 80, 50, wnd, (HMENU)ID_BUTTON3, 0, 0);
            button[codeNum++] = CreateWindow("button", "4", WS_CHILD | WS_VISIBLE, 4, 233, 80, 50, wnd, (HMENU)ID_BUTTON4, 0, 0);
            button[codeNum++] = CreateWindow("button", "5", WS_CHILD | WS_VISIBLE, 87, 233, 80, 50, wnd, (HMENU)ID_BUTTON5, 0, 0);
            button[codeNum++] = CreateWindow("button", "6", WS_CHILD | WS_VISIBLE, 168, 233, 80, 50, wnd, (HMENU)ID_BUTTON6, 0, 0);
            button[codeNum++] = CreateWindow("button", "7", WS_CHILD | WS_VISIBLE, 4, 180, 80, 50, wnd, (HMENU)ID_BUTTON7, 0, 0);
            button[codeNum++] = CreateWindow("button", "8", WS_CHILD | WS_VISIBLE, 87, 180, 80, 50, wnd, (HMENU)ID_BUTTON8, 0, 0);
            button[codeNum++] = CreateWindow("button", "9", WS_CHILD | WS_VISIBLE, 168, 180, 80, 50, wnd, (HMENU)ID_BUTTON9, 0, 0);
            button[codeNum++] = CreateWindow("button", "+", WS_CHILD | WS_VISIBLE, 250, 286, 80, 50, wnd, (HMENU)ID_BUTTONPLUS, 0, 0);
            button[codeNum++] = CreateWindow("button", "-", WS_CHILD | WS_VISIBLE, 250, 233, 80, 50, wnd, (HMENU)ID_BUTTONMINUS, 0, 0);
            button[codeNum++] = CreateWindow("button", "*", WS_CHILD | WS_VISIBLE, 250, 180, 80, 50, wnd, (HMENU)ID_BUTTONMP, 0, 0); // MP - Multiply
            button[codeNum++] = CreateWindow("button", "/", WS_CHILD | WS_VISIBLE, 250, 127, 80, 50, wnd, (HMENU)ID_BUTTONDIV, 0, 0);
            button[codeNum++] = CreateWindow("button", "=", WS_CHILD | WS_VISIBLE, 250, 339, 80, 50, wnd, (HMENU)ID_BUTTONRES, 0, 0);
            button[codeNum++] = CreateWindow("button", "C", WS_CHILD | WS_VISIBLE, 168, 127, 80, 50, wnd, (HMENU)ID_BUTTONCLEAR, 0, 0);
            button[codeNum++] = CreateWindow("button", "CE", WS_CHILD | WS_VISIBLE, 87, 127, 80, 50, wnd, (HMENU)ID_BUTTONCLEAR2, 0, 0);
            button[codeNum++] = CreateWindow("button", ".", WS_CHILD | WS_VISIBLE, 168, 339, 80, 50, wnd, (HMENU)ID_BUTTONPOINT, 0, 0);
            button[codeNum++] = CreateWindow("button", " ( - ) ", WS_CHILD | WS_VISIBLE, 4, 339, 80, 50, wnd, (HMENU)ID_BUTTONNEG, 0, 0);
            button[codeNum++] = CreateWindow("button", " % ", WS_CHILD | WS_VISIBLE, 4, 127, 80, 50, wnd, (HMENU)ID_BUTTONPERCENT, 0, 0);

            button[codeNum++] = CreateWindow("button", " MC ", WS_CHILD | WS_VISIBLE, 4, 90, 80, 30, wnd, (HMENU)ID_BUTTONMCLEAR, 0, 0);
            button[codeNum++] = CreateWindow("button", " M+ ", WS_CHILD | WS_VISIBLE, 87, 90, 80, 30, wnd, (HMENU)ID_BUTTONMPLUS, 0, 0);
            button[codeNum++] = CreateWindow("button", " M- ", WS_CHILD | WS_VISIBLE, 168, 90, 80, 30, wnd, (HMENU)ID_BUTTONMMINUS, 0, 0);
            button[codeNum++] = CreateWindow("button", "  M  ", WS_CHILD | WS_VISIBLE, 250, 90, 80, 30, wnd, (HMENU)ID_BUTTONMWATCH, 0, 0);

            hFont = CreateFont(25, 12, 0, 0, 400, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, "Times New Roman");
            SendMessage(hEdit, WM_SETFONT, (WPARAM)hFont, NULL);
            return 0; 
        }

        case WM_COMMAND:
        {
            int code = LOWORD(wParam);
            int mes = HIWORD(wParam);
            GetWindowText(hEdit, temp, 100);
            size_t i = 0, k = 0;

            if ((LOWORD(wParam) == ID_BUTTONMCLEAR) && (mes == BN_CLICKED))
            {
                memset(memory, 0, strlen(memory));
                v.clear();
            }

            if ((LOWORD(wParam) == ID_BUTTONMPLUS) && (mes == BN_CLICKED))
            {
                GetWindowText(hEdit, memTemp, 100);
                if (memory != "")
                {
                    strcat_s(memory, "\n");
                    strcat_s(memory, memTemp);
                    v.push_back(memTemp);
                }
            }

            if ((LOWORD(wParam) == ID_BUTTONMMINUS) && (mes == BN_CLICKED))
            {
                memset(memory, 0, strlen(memory));
                v.pop_back();
                for (size_t j = 0; j < v.size(); j++)
                {
                    strcat_s(memory, v[j].c_str());
                    strcat_s(memory, "\n");
                }
            }

            if ((LOWORD(wParam) == ID_BUTTONMWATCH) && (mes == BN_CLICKED))
            {
                if(strlen(memory) < 1)
                MessageBox(wnd, "Memory clear!", "Memory", MB_OK);
                else
                MessageBox(wnd, memory, "Memory", MB_OK);
                
            }


            if ((LOWORD(wParam) == ID_BUTTONCLEAR) && (mes == BN_CLICKED))
            {
                SetWindowText(hEdit, "");
                memset(firstValue, 0, strlen(firstValue));
                memset(secondValue, 0, strlen(secondValue));
                memset(temp, 0, strlen(temp));
                memset(buffer, 0, strlen(buffer));
                flag = 0;
            }

            if ((LOWORD(wParam) == ID_BUTTONCLEAR2) && (mes == BN_CLICKED))
            {
                SetWindowText(hEdit, "");
                if (flag == 0)
                {
                    memset(firstValue, 0, strlen(firstValue));
                    memset(temp, 0, strlen(temp));
                    memset(buffer, 0, strlen(buffer));

                }
                else
                {
                    memset(secondValue, 0, strlen(secondValue));
                    memset(temp, 0, strlen(temp));
                    memset(buffer, 0, strlen(buffer));
                    strcpy_s(temp, firstValue);
                    if (flag == 1) strcat_s(temp, "+");
                    if (flag == 2) strcat_s(temp, "-");
                    if (flag == 3) strcat_s(temp, "*");
                    if (flag == 4) strcat_s(temp, "/");
                    if (flag == 5) strcat_s(temp, "%");
                    SetWindowText(hEdit, temp);
                }

            }

            if ((LOWORD(wParam) == ID_BUTTONNEG) && (mes == BN_CLICKED))
            {
                if (temp[strlen(temp) - 1] == '+' || temp[strlen(temp) - 1] == '-' || temp[strlen(temp) - 1] == '*' || temp[strlen(temp) - 1] == '/' || temp[strlen(temp) - 1] == '%')
                strcat_s(secondValue, "-");
                SetWindowText(hEdit, "-");
            }

            if (code >= ID_BUTTON0 && code <= ID_BUTTON9 && (mes == BN_CLICKED))
            {
                int qq = code - 1000;
                char ww[10];
                _itoa_s(qq, ww, 10);
                strcat_s(temp, ww);
                if (strlen(temp) - 1 == '0' && strlen(temp) == 1)
                {
                    temp[0] = temp[1];
                }
                if (flag == 0)
                strcpy_s(firstValue, temp);
                else
                {
                    for (i = cnt; i < strlen(temp); i++)
                    {
                        buffer[k++] = temp[i];
                    }
                    strcpy_s(secondValue, buffer);
                }
                SetWindowText(hEdit, temp);
            }

            if ((LOWORD(wParam) == ID_BUTTONPLUS) && (mes == BN_CLICKED))
            {
                if (strlen(secondValue) > 0)
                {
                    first = atof(firstValue);
                    second = atof(secondValue);
                    result = first + second;
                    sprintf_s(firstValue, "%g", result);
                }
                if (temp[strlen(temp) - 1] == '+' || temp[strlen(temp) - 1] == '-' || temp[strlen(temp) - 1] == '*' || temp[strlen(temp) - 1] == '/' || temp[strlen(temp) - 1] == '%')
                {
                    temp[strlen(temp) - 1] = '+';
                }
                else
                strcat_s(temp, "+");
                cnt = strlen(temp);
                flag = 1;
                SetWindowText(hEdit, temp);

            }

            if ((LOWORD(wParam) == ID_BUTTONMINUS) && (mes == BN_CLICKED))
            {
                if (strlen(secondValue) > 0)
                {
                    first = atof(firstValue);
                    second = atof(secondValue);
                    result = first - second;
                    sprintf_s(firstValue, "%g", result);
                }
                if (temp[strlen(temp) - 1] == '+' || temp[strlen(temp) - 1] == '-' || temp[strlen(temp) - 1] == '*' || temp[strlen(temp) - 1] == '/' || temp[strlen(temp) - 1] == '%')
                {
                    temp[strlen(temp) - 1] = '-';
                }
                else
                strcat_s(temp, "-");
                cnt = strlen(temp);
                flag = 2;
                SetWindowText(hEdit, temp);
            }

            if ((LOWORD(wParam) == ID_BUTTONMP) && (mes == BN_CLICKED))
            {
                if (strlen(secondValue) > 0)
                {
                    first = atof(firstValue);
                    second = atof(secondValue);
                    result = first * second;
                    sprintf_s(firstValue, "%g", result);
                }
                if (temp[strlen(temp) - 1] == '+' || temp[strlen(temp) - 1] == '-' || temp[strlen(temp) - 1] == '*' || temp[strlen(temp) - 1] == '/' || temp[strlen(temp) - 1] == '%')
                {
                    temp[strlen(temp) - 1] = '*';
                }
                else
                strcat_s(temp, "*");
                cnt = strlen(temp);
                flag = 3;
                SetWindowText(hEdit, temp);
            }

            if ((LOWORD(wParam) == ID_BUTTONDIV) && (mes == BN_CLICKED))
            {
                if (strlen(secondValue) > 0)
                {
                    first = atof(firstValue);
                    second = atof(secondValue);
                    result = first / second;
                    sprintf_s(firstValue, "%g", result);
                }
                if (temp[strlen(temp) - 1] == '+' || temp[strlen(temp) - 1] == '-' || temp[strlen(temp) - 1] == '*' || temp[strlen(temp) - 1] == '/' || temp[strlen(temp) - 1] == '%')
                {
                    temp[strlen(temp) - 1] = '/';
                }
                else
                strcat_s(temp, "/");
                cnt = strlen(temp);
                flag = 4;
                SetWindowText(hEdit, temp);
            }

            if ((LOWORD(wParam) == ID_BUTTONPERCENT) && (mes == BN_CLICKED))
            {
                strcat_s(temp, "%");
                cnt = strlen(temp);
                if(flag == 1)
                flag = 5;
                if (flag == 2)
                flag = 6;
                SetWindowText(hEdit, temp);
            }

            if ((LOWORD(wParam) == ID_BUTTONPOINT) && (mes == BN_CLICKED))
            {
                strcat_s(temp, ".");
                SetWindowText(hEdit, temp);
            }

            if ((LOWORD(wParam) == ID_BUTTONRES) && (mes == BN_CLICKED))
            {
                first = atof(firstValue);
                second = atof(secondValue);
                switch (flag)
                {
                    case 1:
                        result = first + second;
                        sprintf_s(temp, "%g", result);
                        break;
                    case 2:
                        result = first - second;
                        sprintf_s(temp, "%g", result);
                        break;
                    case 3:
                        result = first * second;
                        sprintf_s(temp, "%g", result);
                        break;
                    case 4:
                        if (first == 0 || second == 0)
                        {
                            SetWindowText(hEdit, "Cannot divide by zero");
                            break;
                        }
                        result = first / second;
                        sprintf_s(temp, "%g", result);
                        break;
                    case 5:
                        result = first / 100 * second + first;
                        sprintf_s(temp, "%g", result);
                        break;
                    case 6:
                        result = first / 100 * second;
                        result = first - result;
                        sprintf_s(temp, "%g", result);
                        break;
                    default:
                        break;
                }
                memset(firstValue, 0, strlen(firstValue));
                memset(secondValue, 0, strlen(secondValue));
                memset(buffer, 0, strlen(buffer));
                flag = 0;
                _itoa_s(result, firstValue, 10);
                SetWindowText(hEdit, temp);
            }
            return 0;
        }

        // зарытие окна
        case WM_DESTROY:
        {
            if (hFont) DeleteObject(hFont);
            // закрыть приложение (процесс)
            PostQuitMessage(0);
            return 0;
        }

        case WM_KEYDOWN: // дл€ нажатой клавиши
        {
            if (hFont) DeleteObject(hFont);
            if (wParam == VK_ESCAPE) // если нажал на esc - закрыть окно
                PostQuitMessage(0);
            return 0;
        }

    }

    // утилизаци€ необработанных сообщений
    return DefWindowProc(wnd, msg, wParam, lParam);
}

// точка входа в программу
int APIENTRY WinMain(HINSTANCE hInstance,   // адрес экземпл€ра приложени€
    HINSTANCE hPrevInstance,                // адрес экземпл€ра приложени€, запустившего текущее
    LPSTR     lpCmdLine,                    // комендна€ строка
    int       nCmdShow)                     // флаги запуска окна
{
    // структура дл€ класса окна
    WNDCLASS wc;

    // адрес одного окна (указатель на окно)
    HWND hwnd;

    // занесение свойств окна
    wc.hInstance = hInstance;

    // значок окна
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

    // курсор окна
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    // оконна€ функци€
    wc.lpfnWndProc = WndProc;

    // адрес строки меню
    wc.lpszMenuName = NULL;

    // кисть окна
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 7);

    // назвние класса окна
    wc.lpszClassName = className;

    // стили окна
    wc.cbClsExtra = wc.cbWndExtra = wc.style = 0;

    // регистраци€ класса окна
    int k = RegisterClass(&wc);

    // создание главного окна приложени€
    hwnd = CreateWindow(className, "Calculator", WS_VISIBLE | WS_SYSMENU,
        800, 300, 350, 435, NULL, NULL, hInstance, 0);

    // выйти с ошибкой
    if (!hwnd) return false;

    // цикл обработки сообщений
    while (GetMessage(&msg, 0, 0, 0)) 
    {

        TranslateMessage(&msg); // трансл€ци€ сообщений в текст пол€
        // обработка сообщений окну
        DispatchMessage(&msg);
    }

    return 1;
}
