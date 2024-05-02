#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HWND hButton1, hButton2;
    static HWND hPage1, hPage2;
    static int currentPage = 1;

    switch (msg) {
        case WM_CREATE: {
            hButton1 = CreateWindow("BUTTON", "Page 1", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 50, 50, 100, 30, hwnd, (HMENU)1, NULL, NULL);
            hButton2 = CreateWindow("BUTTON", "Page 2", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 50, 100, 100, 30, hwnd, (HMENU)2, NULL, NULL);

            hPage1 = CreateWindow("STATIC", "This is Page 1", WS_VISIBLE | WS_CHILD | SS_CENTER, 200, 50, 150, 100, hwnd, NULL, NULL, NULL);
            hPage2 = CreateWindow("STATIC", "This is Page 2", WS_CHILD, 200, 50, 150, 100, hwnd, NULL, NULL, NULL);
            ShowWindow(hPage2, SW_HIDE);

            break;
        }
        case WM_COMMAND: {
            if (LOWORD(wParam) == 1) {
                ShowWindow(hPage1, SW_SHOW);
                ShowWindow(hPage2, SW_HIDE);
                currentPage = 1;
            } else if (LOWORD(wParam) == 2) {
                ShowWindow(hPage1, SW_HIDE);
                ShowWindow(hPage2, SW_SHOW);
                currentPage = 2;
            }
            break;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "OptionsWindow";
    RegisterClass(&wc);

    HWND hwnd = CreateWindow("OptionsWindow", "Options Window", WS_OVERLAPPEDWINDOW, 100, 100, 400, 200, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}