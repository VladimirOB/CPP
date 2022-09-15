//Проект > Свойства > Свойства конфигурации > Дополнительно > Набор символов > Использовать многобайтовую кодировку.
//Проект > Свойства > С/C++ > Создание кода > Библиотека времени выполнения > Многопоточная(/ MT) ( для Release)
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;
#define ID_BUTTON1 1000
#define ID_BUTTON2 1001
#define ID_EDIT 1002
#define ID_EDIT2 1003
#define IDT_TIMER1 1004
#define IDT_TIMER2 1005
#define IDT_TIME 1006
#define ID_MENU 1007
#define ID_MENU2 1008
#define ID_MENU3 1009
#define ID_MENU_EXIT 1010
#define ID_HEDIT 1011
#define ID_OPEN 1012
#define ID_OPENNAME 1013
#define ID_SAVE 1014
#define ID_OPENTEXT 1015
#define ID_HEDITTEXT 1016
#define ID_OPENOK 1017
#define ID_OPENCANCEL 1018
// название класса окна
char className[] = "WindowClass1";

/*WinApi
3. По центру окна расположена кнопка. Когда пользователь нажимает мышью в окне, кнопка плавно перемещается по прямой в место нажатия мышью.
MoveWindow, SetTimer*/

// структура, хранящая информацию о сообщении
MSG msg;

HWND hButton;
HWND time2;
HWND hEdit;
HWND hEditText;
HWND hEditFile;
HWND hEditFileText;
HWND hButtOk;
HWND hButtCancel;
//HWND hwndTimer;
//UINT uResult;
//OPENFILENAME ofn = { 0 };

char clock2[40] = "\nTime";
char text[1000];
char file_name[100] = "DB.txt";
RECT rct;
int oldX = 350;
int oldY = 350;
int x = 0;
int y = 0;
int i, k;


VOID __stdcall MyTimerProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];
    if (WM_TIMER == uMsg) 
    {


        if (idEvent == IDT_TIMER2)
        {
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strftime(buffer, 80, "%H:%M:%S",  timeinfo);

            strcat(buffer, clock2);
            SetWindowText(time2, buffer);
        }

        if (idEvent == IDT_TIMER1)  // Тут проводить операцию, когда кнопка подъедет делать кил
        {
           
            //GetWindowRect(hButton, &rct);
            //ScreenToClient(hButton, &rct);
            //SetWindowPos(hButton, HWND_TOP, x - 20, y - 15, 50, 50, SWP_SHOWWINDOW);
            
            if (x <= i)
            {
                SetWindowPos(hButton, HWND_TOP, i, k, 50, 50, SWP_SHOWWINDOW);
                i--;
            }
            if (x > i)
            {
                SetWindowPos(hButton, HWND_TOP, i, k, 50, 50, SWP_SHOWWINDOW);
                i++;
                
            }

            if (y <= k)
            {
                SetWindowPos(hButton, HWND_TOP, i, k, 50, 50, SWP_SHOWWINDOW);
                k--;
                
            }

            if (y > k)
            {
                SetWindowPos(hButton, HWND_TOP, i, k, 50, 50, SWP_SHOWWINDOW);
                k++;
            }
            
            if (i == x && k == y)
            {
                oldX = x;
                oldY = y;
                KillTimer(hButton, IDT_TIMER1);
            }
        }
    }
}

void Load()
{
    ifstream file(file_name, ios::in);
    string buff, buffer;
    while (!file.eof())
    {
        getline(file, buff);
        buff += " ";
        buffer += buff;
    }

    strcat(text, buffer.c_str());
    file.close();
    SetWindowText(hEdit, text);
    memset(text, 0, strlen(text));

}

void MainWndAddMenu(HWND hWnd)
{
    HMENU RootMenu = CreateMenu();

    HMENU SubMenu = CreateMenu();
    HMENU SubActionMenu = CreateMenu();

    AppendMenu(SubActionMenu, MF_STRING, ID_MENU, "Russian");
    AppendMenu(SubActionMenu, MF_STRING, ID_MENU2, "English");
    AppendMenu(SubActionMenu, MF_STRING, ID_MENU3, "Deutsch");

    AppendMenu(SubMenu, MF_STRING, ID_OPEN, "Open file");
    AppendMenu(SubMenu, MF_STRING, ID_SAVE, "Save file");
    AppendMenu(SubMenu, MF_POPUP, (UINT_PTR)SubActionMenu, "Language");
    AppendMenu(SubMenu, MF_SEPARATOR, NULL, NULL);


    AppendMenu(SubMenu, MF_STRING, ID_MENU_EXIT, "Exit");


    AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, "File");
    SetMenu(hWnd, RootMenu);
}

LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    
    switch (msg)
    {

    case WM_CREATE:
    {
        MainWndAddMenu(wnd);
        hEditText = CreateWindow("static", "Notebook", WS_VISIBLE | WS_CHILD, 10, 10, 65, 20, wnd, (HMENU)ID_HEDITTEXT, 0, 0);
        hEdit = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 10, 30, 200, 200, wnd, (HMENU)ID_HEDIT, 0, 0);
        hButton = CreateWindow("button", "Button", WS_CHILD | WS_VISIBLE, 350, 350, 50, 50, wnd, (HMENU)ID_EDIT, 0, 0);
        time2 = CreateWindow("static", "", WS_CHILD | WS_VISIBLE, 350, 10, 60, 35, wnd, (HMENU)IDT_TIME, 0, 0);
        SetTimer(time2, IDT_TIMER2, 1000, (TIMERPROC)MyTimerProc);
        return 0;
    }

    case WM_MOUSEMOVE:
    {
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);
        char sx[40], sy[40];
        _itoa_s(x, sx, 10);
        _itoa_s(y, sy, 10);
        strcat_s(sx, "  ");
        strcat_s(sx, sy);
        SetWindowText(wnd, sx); // Отобразить текст в окне
        return 0;
    }


    case WM_TIMER:
    {
        if (wParam == IDT_TIMER1)
        {
           
        }
        
        return 0;
    }

    case WM_LBUTTONDOWN:
    {  
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        i = oldX, k = oldY;
        SetTimer(hButton, IDT_TIMER1, 1, (TIMERPROC)MyTimerProc);
        return 0;
    }

    case WM_COMMAND:
    {
        if (LOWORD(wParam) == ID_HEDIT)
        {
            GetWindowText(hEdit, text, 1000);
            return 0;
        }

        if (LOWORD(wParam) == ID_OPENOK)
        {   
            GetWindowText(hEditFile, file_name, 100);
            Load();
            DestroyWindow(hEditFileText);
            DestroyWindow(hEditFile);
            DestroyWindow(hButtOk);
            DestroyWindow(hButtCancel);
            return 0;
        }

        if (LOWORD(wParam) == ID_OPENCANCEL)
        {
            SetWindowText(hEditFile, "");
            return 0;
        }

        if (LOWORD(wParam) == ID_OPENNAME)
        {
            return 0;
        }
        
        switch (wParam)
        {

        case ID_MENU_EXIT:
        {
            KillTimer(time2, IDT_TIMER2);
            // закрыть приложение (процесс)
            PostQuitMessage(0);
            return 0;
        }

        case ID_MENU:
        {
            strcpy(clock2, "\nВремя");
            return 0;
        }
        case ID_MENU2:
        {
            strcpy(clock2, "\nTime");
        }
        case ID_MENU3:
        {
            strcpy(clock2, "\nZeit");
        }
        case ID_SAVE:
        {
            ofstream file("DB.txt", ios::out);
            file << text;
            file.close();
            return 0;
        }
        case ID_OPEN:
        { 
            hEditFileText = CreateWindow("static", "Enter file name: ", WS_VISIBLE | WS_CHILD, 300, 50, 150, 50, wnd, (HMENU)ID_OPENTEXT, 0, 0);
            hEditFile = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 300, 70, 150, 30, wnd, (HMENU)ID_OPENNAME, 0, 0); // диалог окно или пару кнопок.
            hButtOk = CreateWindow("button", "Ok", WS_VISIBLE | WS_CHILD, 300, 110, 50, 30, wnd, (HMENU)ID_OPENOK, 0, 0);
            hButtCancel = CreateWindow("button", "Clear", WS_VISIBLE | WS_CHILD | WS_BORDER, 400, 110, 50, 30, wnd, (HMENU)ID_OPENCANCEL, 0, 0); 
            Load();
           
            return 0;
        }
        default:
            break;
        }
        break;
    }

    // зарытие окна
    case WM_DESTROY:
    {
        KillTimer(time2, IDT_TIMER2);
        // закрыть приложение (процесс)
        PostQuitMessage(0);
        return 0;
    }

    case WM_KEYDOWN: // для нажатой клавиши
    {
        if (wParam == VK_ESCAPE) // если нажал на esc - закрыть окно
        {
            KillTimer(time2, IDT_TIMER2);
            PostQuitMessage(0);
        }
        return 0;
    }

    }

    // утилизация необработанных сообщений
    return DefWindowProc(wnd, msg, wParam, lParam);
}

// точка входа в программу
int APIENTRY WinMain(HINSTANCE hInstance,   // адрес экземпляра приложения
    HINSTANCE hPrevInstance,                // адрес экземпляра приложения, запустившего текущее
    LPSTR     lpCmdLine,                    // комендная строка
    int       nCmdShow)                     // флаги запуска окна
{
    // структура для класса окна
    WNDCLASS wc;

    // адрес одного окна (указатель на окно)
    HWND hwnd;

    // занесение свойств окна
    wc.hInstance = hInstance;

    // значок окна
    wc.hIcon = LoadIcon(NULL, IDI_EXCLAMATION);

    // курсор окна
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    // оконная функция
    wc.lpfnWndProc = WndProc;

    // адрес строки меню
    wc.lpszMenuName = NULL;

    // кисть окна
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 7);

    // назвние класса окна
    wc.lpszClassName = className;

    // стили окна
    wc.cbClsExtra = wc.cbWndExtra = wc.style = 0;

    // регистрация класса окна
    int k = RegisterClass(&wc);

    // создание главного окна приложения
    hwnd = CreateWindow(className, "Window", WS_VISIBLE | WS_SYSMENU,
        800, 200, 800, 800, NULL, NULL, hInstance, 0);

    // выйти с ошибкой
    if (!hwnd) return false;

    // цикл обработки сообщений
    while (GetMessage(&msg, 0, 0, 0))
    {
        TranslateMessage(&msg); // трансляция сообщений в текст поля
        // обработка сообщений окну
        DispatchMessage(&msg);
    }
    return 1;
}

/*
BOOL MoveWindow(

    HWND hWnd,    // дескриптор окна
    int x,        // позиция по горизонтали
    int y,        // позиция по вертикали
    int nWidth,   // ширина
    int nHeight,  // высота
    BOOL bRepaint // флажок перекраски
);

UINT_PTR SetTimer(

    HWND hWnd,
    UINT_PTR nIDEvent, // Указывает идентификатор таймера отличный от нуля.
    UINT uElapse, // Указывает значение времени простоя, в миллисекундах.
    TIMERPROC lpTimerFunc //Указатель на функцию, которая уведомляет, когда значение времени простоя истекает.
);

BOOL SetWindowPos(HWND hwnd,
    HWND	hWndlnsertAfter,	//дескриптор порядка размещения
    int	х,			//новая координата левого края
    int	у,			//новая координата верхнего края
    int	cx,			//новая ширина
    int	cy,			//новая высота
    UINT	uFlags			//флажок позиционирования
);
*/


/* if (x <= oldX && y <= oldY)
            {
                while (i != x && k != y)
                {
                    SetWindowPos(hButton, HWND_TOP, i - 20, k - 15, 50, 50, SWP_SHOWWINDOW);
                    i--, k--;
                }
            }
            if (x <= oldX && y >= oldY)
            {
                while (i != x && k != y)
                {
                    SetWindowPos(hButton, HWND_TOP, i - 20, k - 15, 50, 50, SWP_SHOWWINDOW);
                    i--, k++;
                }
            }

            if (x >= oldX && y <= oldY)
            {
                while (i != x && k != y)
                {
                    SetWindowPos(hButton, HWND_TOP, i - 20, k - 15, 50, 50, SWP_SHOWWINDOW);
                    i++, k--;
                }
            }

            if (x >= oldX && y >= oldY)
            {
                while (i != x && k != y)
                {
                    SetWindowPos(hButton, HWND_TOP, i - 20, k - 15, 50, 50, SWP_SHOWWINDOW);
                    i++, k++;
                }
            }*/