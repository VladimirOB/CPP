//#define _CRT_SECURE_NO_WARNINGS
//#include <windows.h>
//#include <time.h>
//
//#define USE_TIMER_PROC
//
//#define MY_TIMERID1 100
//#define MY_TIMERID2 101
//
//#ifdef USE_TIMER_PROC
//VOID __stdcall MyTimerProc(HWND hWnd, UINT uMsg, UINT idEvent, DWORD dwTime)
//{
//    time_t rawtime;
//    struct tm* timeinfo;
//    char buffer[80];
//    if (WM_TIMER == uMsg) {
//        if (idEvent == MY_TIMERID2) {
//            time(&rawtime);
//            timeinfo = localtime(&rawtime);
//            strftime(buffer, 80, "Now time is %I:%M:%S%p.", timeinfo);
//            SetWindowText(hWnd, buffer);
//        }
//    }
//}
//#endif
//LRESULT CALLBACK WndProc(HWND hWnd,
//    UINT message,
//    WPARAM wParam,
//    LPARAM lParam);
//
//int APIENTRY WinMain(HINSTANCE hInstance,
//    HINSTANCE hPrevInstance,
//    LPSTR     lpCmdLine,
//    int       nCmdShow)
//{
//    WNDCLASS wc;
//    MSG msg;
//    HWND hWnd;
//    ZeroMemory(&wc, sizeof(WNDCLASS));
//
//    wc.style = CS_HREDRAW | CS_VREDRAW;
//    wc.lpfnWndProc = (WNDPROC)WndProc;
//    wc.hInstance = hInstance;
//    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//    wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
//    wc.lpszClassName = (LPCTSTR)"TimerDemoClass";
//    RegisterClass(&wc);
//
//    hWnd = CreateWindow("TimerDemoClass", "SetTimer/KillTimer Demo", WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
//
//    ShowWindow(hWnd, nCmdShow);
//    UpdateWindow(hWnd);
//    while (GetMessage(&msg, NULL, 0, 0))
//    {
//        DispatchMessage(&msg);
//    }
//    return 0;
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    time_t rawtime;
//    struct tm* timeinfo;
//    char buffer[80];
//    switch (message)
//    {
//#ifndef USE_TIMER_PROC
//    case WM_TIMER:
//        if (wParam == MY_TIMERID1) {
//            time(&rawtime);
//            timeinfo = localtime(&rawtime);
//            strftime(buffer, 80, "Now time is %I:%M:%S%p.", timeinfo);
//            SetWindowText(hWnd, buffer);
//        }
//        break;
//    case WM_LBUTTONDOWN:
//        SetTimer(hWnd, MY_TIMERID1, 1000, NULL);
//        break;
//    case WM_RBUTTONDOWN:
//        KillTimer(hWnd, MY_TIMERID1);
//        break;
//#else
//    case WM_LBUTTONDOWN:
//        SetTimer(hWnd, MY_TIMERID2, 1000, (TIMERPROC)MyTimerProc);
//        break;
//    case WM_RBUTTONDOWN:
//        KillTimer(hWnd, MY_TIMERID2);
//        break;
//#endif
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}