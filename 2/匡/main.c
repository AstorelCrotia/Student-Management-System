#include "head.h"
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    int select =0;
    switch (msg) {
        case WM_CREATE:
            U=getUser_txt();
            I=getIssue_txt();
            T=getticket_txt();
            Pwinner=getprvewinner_txt();
            menu_sign(hWnd);
            break;
        case WM_COMMAND:
            select = LOWORD(wParam);
            switch (select) {
                case 1:
                    ShowWindow(hWnd,SW_HIDE);
                    admin_loginw(hWnd); // 跳转到管理员登录界面
                    break;
                case 2:
                    ShowWindow(hWnd,SW_HIDE);
                    user_loginw(hWnd);
                    break;
                case 3:
                    // 处理用户注册逻辑
                    break;
                case 0:
                    MessageBox(hWnd, "欢迎下次光临！", "提示", MB_OK);
                    PostQuitMessage(0);
                    break;
                default:
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, msg, wParam, lParam);
    }

    return 0;
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);
    HWND hwnd = CreateWindow("MyWindowClass", "Menu Window", WS_OVERLAPPEDWINDOW, 100, 100, 400, 200, NULL, NULL, hInstance, NULL);
    ShowWindow(hwnd, nCmdShow);
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}