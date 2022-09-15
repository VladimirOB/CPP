#include <windows.h>
#include "resource.h"
#define ID_BUTTON1 1000
#define ID_BUTTON2 1000
#define ID_EDIT1 1001
#define ID_EDIT2 1002
#pragma comment(lib, "msimg32.lib") // для AlphaBlend
// название класса окна
char className[] = "WindowClass1";

char text[] = "Группа PD112";

char buffer[40];
// структура, хранящая информацию о сообщении
MSG msg;

HWND mHwnd; // main window Handle (указатель на главное окно)

HWND hbutton, hbutton2[100];

HWND hedit, hres_edit;

HWND del;

int cnt = 1, cnt_button = 0;

int num =0;

RECT clientRect; // размер клиентской области

HBITMAP pattern; // Хендл на картинку.

HBITMAP key; // Хендл на картинку по имени.

HBITMAP key2; // Хендл на картинку по имени.

BLENDFUNCTION blf = { AC_SRC_OVER, 0, 255, 0 }; // для вывода полупрозрачной картинки

bool forward = true; // для "анимации"
int alpha = 0;
int alpha2 = 255;

bool isDrawing = true; // для отрисовки

HDC hdc;

HDC backDC; // бек буффер (фоновый контекст)

HBITMAP backBMP;

void DrawFrame();

// оконная функция
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {

        //case WM_TIMER:
        //{
        //    RedrawWindow(wnd, NULL, NULL, RDW_INVALIDATE); // NULL(1) - какую часть окна перерисовать, можно Rect. NULL(2) - область
        //    return 0;
        //}


        case WM_PAINT:
        {   
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(wnd, &ps);
           
            // вся отрисовка происходит не в момент обновления окна, а в фоне. Как только кадр готов, окно перерисовывается.
            BitBlt(hdc, 0, 0, clientRect.right, clientRect.bottom, backDC, 0, 0, SRCCOPY);
            TextOut(hdc, 400, 120, text, strlen(text));
            EndPaint(wnd, &ps);

            return 0;
        }

        case WM_MOUSEMOVE:
        {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            char sx[40], sy[40];
            _itoa_s(x,sx, 10);
            _itoa_s(y,sy, 10);
            strcat_s(sx, "  ");
            strcat_s(sx, sy);
            SetWindowText(wnd, sx); // Отобразить текст в окне
            return 0;
        }

        case WM_CREATE:
        {
            //hbutton =  CreateWindow("button", "Start", WS_CHILD | WS_VISIBLE, 20, 540, 200, 20, wnd, (HMENU)ID_BUTTON1, 0, 0);

            del = CreateWindow("button", "Обработать", WS_CHILD | WS_VISIBLE, 20, 560, 200, 20, wnd, (HMENU)ID_BUTTON2, 0, 0);

            hedit = CreateWindow("edit", "Введите текст", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,
                20, 320, 300, 200, wnd, (HMENU)ID_EDIT1, 0, 0);

           // hres_edit = CreateWindow("edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,
           //   20, 350, 200, 200, wnd, (HMENU)ID_EDIT2, 0, 0);

            return 0;
        }

        /*Пользователь указывает количество кнопок и нажимает на кнопку Start
        Программа создаёт указанное количество кнопок и размещает их в случайных позициях в окне*/

        case WM_COMMAND:
        {
            int code = LOWORD(wParam);
            int mes = HIWORD(wParam);

            if ((LOWORD(wParam) == ID_BUTTON2) && (mes == BN_CLICKED))
            {
                char hh[500];

                GetWindowText(hedit,hh,500);

                int i = 0;

                while (hh[i] != 0) 
                {
                    if (hh[i] >= '0' && hh[i] <= '9') 
                    {
                        while (hh[i] != 0) 
                        {
                            hh[i] = hh[i + 1];
                            i++;
                        }
                    }
                    else 
                    {
                        i++;
                    }
                }
                SetWindowText(hedit,hh);
                

               /* for (size_t i = 0, i2=0; i < strlen(s); i++)
                {
                    if (!isdigit(s[i]))
                    {
                        s2[i2++] = s[i];
                    }
                }
                SetWindowText(hedit, s2);*/
               

            }

            /*if ((LOWORD(wParam) == ID_BUTTON1) && (mes == BN_CLICKED))
            {
                char s[10];
                GetWindowText(hedit, s, 10);
                cnt_button = atoi(s);
                for (size_t i = 0; i < cnt_button; i++)
                {
                    
                    char s[40];
                    _itoa_s(num + 1, s, 10);

                    hbutton2[num++] = CreateWindow("button", s, WS_CHILD | WS_VISIBLE,
                        rand()%1000, rand()%700, 30, 30, wnd, (HMENU)(300 + num), 0, 0);
                    
                }
            }*/

           /* if (code >= 300 && code <= 500 && (HIWORD(wParam) == BN_CLICKED))
            {
                DestroyWindow(hbutton2[code - 300]);
            }*/


           /* if ((LOWORD(wParam) == ID_BUTTON1) && (mes == BN_CLICKED))
            {
                char s[400], s2[400];
                GetWindowText(hres_edit, s2, 400);
                GetWindowText(hedit, s, 400);
                strcat_s(s2, "\r\n");
                strcat_s(s2, s);
                SetWindowText(hres_edit, s2);
                SetWindowText(hedit, "");
            }*/

            //if ((LOWORD(wParam) == ID_BUTTON1) && (mes == BN_CLICKED))
            //{
            //    //WinExec("calc.exe", SW_SHOW);
            //    //ShellExecute(0, "explore", "V:\\", NULL, NULL, SW_SHOWNORMAL);
            //    //ShellExecute(0, "open", "mspaint", "v:\\t\\1.jpg", NULL, SW_SHOWNORMAL);
            //    //ShellExecute(0, "print", "v:\\t\\1.jpg", NULL, NULL, SW_SHOWNORMAL);

            //    //GetWindowText(hbutton[id], buffer, 39);
            //    //DestroyWindow(hbutton); // убивает окно
            //}
            return 0;
        }


        case WM_LBUTTONDOWN:
        {
            int x = LOWORD(lParam);
            int y = HIWORD(lParam);
            char sx[40], sy[40], but[10];
            _itoa_s(x, sx, 10);
            _itoa_s(y, sy, 10);
            strcat_s(sx, "  ");
            strcat_s(sx, sy);
            if (num < 100)
            {
                char s[40];
                _itoa_s(num+1, s, 10);

                hbutton2[num++] = CreateWindow("button", s, WS_CHILD | WS_VISIBLE,
                    x, y, 20, 20, wnd, (HMENU)(300 + num), 0, 0);
            }
          
            //_itoa_s(cnt++, but, 10);
            //hbutton = CreateWindow("button", but, WS_CHILD | WS_VISIBLE, x, y, 20, 20, wnd, (HMENU)ID_BUTTON1, 0, 0);
            /*int res = MessageBox(wnd, sx, "Button", MB_OKCANCEL);

            if (res == IDOK) MessageBox(wnd, "Ok", "Title of message", MB_OK);
            else MessageBox(wnd, "Cancel", "Title of message", MB_OK);*/

            //// Получаем индекс контекста устройства
            //hdc = GetDC(mHwnd);
            //// Выводим текстовую строку
            //TextOut(hdc, 400, 100, "Щёлк!", 5);
            //
            //// Отдаем индекс контекста устройства
            //ReleaseDC(mHwnd, hdc);



            return 0;
        }

        // зарытие окна
        case WM_DESTROY:
        {
            isDrawing = false; // завершение потока отрисовки

            // закрыть приложение (процесс)
            PostQuitMessage(0);
            return 0;
        }

        case WM_KEYDOWN: // для нажатой клавиши
        {
            if (wParam == VK_ESCAPE) // если нажал на esc - закрыть окно
                PostQuitMessage(0);
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
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    // назвние класса окна
    wc.lpszClassName = className;

    // стили окна
    wc.cbClsExtra = wc.cbWndExtra = wc.style = 0;

    // регистрация класса окна
    int k = RegisterClass(&wc);

    pattern = LoadBitmap(wc.hInstance, MAKEINTRESOURCE(IDB_BITMAP1));

    key = LoadBitmap(wc.hInstance, MAKEINTRESOURCE(IDB_BITMAP2));

    key2 = LoadBitmap(wc.hInstance, MAKEINTRESOURCE(IDB_BITMAP2));

    // создание главного окна приложения
    hwnd = CreateWindow(className, "Prived world!", WS_VISIBLE | WS_OVERLAPPEDWINDOW,
        300, 200, 1024, 720, NULL, NULL, hInstance, 0);

    // выйти с ошибкой
    if (!hwnd) return false;

    mHwnd = hwnd;

    //SetTimer(hwnd, 1000, 1000 / 60, NULL); // 1000/60 = это значит 60 раз в секунду
    CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)&DrawFrame, NULL, NULL, NULL); // создали поток для DrawFrame

    // цикл обработки сообщений
    while (GetMessage(&msg, 0, 0, 0)) {

       
        TranslateMessage(&msg); // трансляция сообщений в текст поля
        DispatchMessage(&msg); // обработка сообщений окну
    }

    return 1;
}

void DrawFrame()
{
    GetClientRect(mHwnd, &clientRect); // постоянно получает координаты окна
    hdc = GetDC(mHwnd); // получаем основной контекст устройства окна.
    backDC = CreateCompatibleDC(hdc);
    backBMP = CreateCompatibleBitmap(hdc, clientRect.right, clientRect.bottom);
    HGDIOBJ oldBMP = SelectObject(backDC, backBMP); // вновь созданный всегда нужно выбирать.

    ReleaseDC(mHwnd, hdc);

    while (isDrawing)
    {

        HPEN newPen = CreatePen(PS_SOLID, 5, RGB(0, 0, 255)); // создание ручки

        //CreatePatternBrush() - для картинки
        HBRUSH newBrush = CreatePatternBrush(pattern);
        //HBRUSH newBrush = CreateSolidBrush(RGB(255, 255, 0));

          //HGDIOBJ oldBrush = SelectObject(hdc, GetStockObject(BLACK_BRUSH));
        HGDIOBJ oldBrush = SelectObject(backDC, newBrush);

        // HGDIOBJ oldPen - сохранение старого если PEN, то PEN.
        //HGDIOBJ oldPen = SelectObject(hdc, GetStockObject(NULL_PEN));
        HGDIOBJ oldPen = SelectObject(backDC, newPen);


        Rectangle(backDC, clientRect.left + 10, clientRect.top + 10, clientRect.right - 10, clientRect.bottom - 10); // создание фигуры.

        BITMAP keyObject; // объект картинки
        GetObject(key, sizeof(BITMAP), &keyObject); // sizeof(BITMAP) - чтоб система поняла сколько байт скопировать на объект из хендла.

        BITMAP keyObject2; // объект картинки
        GetObject(key2, sizeof(BITMAP), &keyObject2); // sizeof(BITMAP) - чтоб система поняла сколько байт скопировать на объект из хендла.

        HDC memDC = CreateCompatibleDC(backDC); // временный совместимый контекст, чтоб картинка отображалась правильно.

        HDC memDC2 = CreateCompatibleDC(backDC); // временный совместимый контекст, чтоб картинка отображалась правильно.

        SelectObject(memDC, key);

        SelectObject(memDC2, key2);

        //BitBlt(hdc, 30, 50, keyObject.bmWidth, keyObject.bmHeight, memDC, 0, 0, SRCCOPY); // наложение новых пикселей на исходные.


        //BitBlt(hdc, 150, 200, keyObject.bmWidth, keyObject.bmHeight, memDC, 0, 0, MERGEPAINT);


        //StretchBlt(hdc, 30, 50, keyObject.bmWidth-100, keyObject.bmHeight+50, memDC, 0, 0, keyObject.bmWidth, keyObject.bmHeight, SRCCOPY); // помимо копирования, может растянуть или сжать изобр.


        if (alpha >= 255) forward = false;
        if (alpha <= 0) forward = true;

        if (forward)
        {
           alpha += 5;
           alpha2 -= 5;
        }
        else
        {
            alpha -= 5;
            alpha2 += 5;
        }
        blf.SourceConstantAlpha = alpha; // для полупрозрачного изображения (0-255)
        AlphaBlend(backDC, 30, 50, keyObject.bmWidth, keyObject.bmHeight, memDC, 0, 0,
            keyObject.bmWidth, keyObject.bmHeight, blf);



        blf.SourceConstantAlpha = alpha2; // для полупрозрачного изображения (0-255)
        AlphaBlend(backDC, 720, 50, keyObject2.bmWidth, keyObject2.bmHeight, memDC, 0, 0,
            keyObject2.bmWidth, keyObject2.bmHeight, blf);


        DeleteDC(memDC);
        DeleteDC(memDC2);

        SelectObject(backDC, oldPen);
        SelectObject(backDC, oldBrush);

        DeleteObject(newPen); // удаляем созданную ручку. Если не удалить, будет утечка.
        DeleteObject(newBrush);

        //TextOut(hdc, 100, 500, "PD 112!", lstrlen("PD 112!"));
        RedrawWindow(mHwnd, NULL, NULL, RDW_INVALIDATE); // перерисовка окна
        Sleep(1000 / 60);

        // reinterpret_cast<HBRUSH> - явное приведение типа // (HBRUSH)GetStockObject(BLACK_BRUSH)); это Cи
       // FillRect(hdc, &clientRect, reinterpret_cast<HBRUSH>(GetStockObject(BLACK_BRUSH))); // заливка окна
    }

    SelectObject(backDC, oldBMP);
    DeleteObject(backBMP);
    DeleteDC(backDC);
}