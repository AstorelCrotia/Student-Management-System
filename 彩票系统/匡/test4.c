#include <windows.h>
#include <stdio.h>

void menu_sign() {
    printf("1. Admin Login\n");
    printf("2. User Login\n");
    printf("3. Register User\n");
    printf("0. Exit\n");
}

void admin_login() {
    // 实现管理员登录功能
}

void user_login() {
    // 实现用户登录功能
}

void registerUser() {
    // 实现用户注册功能
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static int U, I, T, Pwinner;
    int select=0;
    switch (msg) {
        case WM_CREATE:
            menu_sign();
            break;

        case WM_CHAR:
            select = wParam - '0';
            switch (select) {
                case 1:
                    admin_login(U, I, T, Pwinner);
                    break;
                case 2:
                    user_login(U, I, T, Pwinner);
                    break;
                case 3:
                    registerUser(U);
                    break;
                case 0:
                    MessageBox(hwnd, "欢迎下次光临！", "提示", MB_OK);
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
            return DefWindowProc(hwnd, msg, wParam, lParam);
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