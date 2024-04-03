#include "head.h"
int errorCount1=3;
char name1[50];
HWND g_hWndPrevious11 = NULL;
HWND g_hWndPrevious12 = NULL;
HWND g_hWndPrevious13 = NULL;
HWND g_hWndPrevious14 = NULL;
HWND g_hWndPrevious15 = NULL;
void user_loginw(HWND hWnd) {
    g_hWndPrevious11=hWnd;
    // 创建新的窗口来显示管理员登录界面
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcUser;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "UserWindowClass9";
    RegisterClass(&wc);
    HWND userHwndlogin = CreateWindow("UserWindowClass9", "User Login Window", WS_OVERLAPPEDWINDOW, 200, 200, 400, 300, NULL, NULL, NULL, NULL);
    ShowWindow(userHwndlogin, SW_SHOW);
}
LRESULT CALLBACK WndProcUser(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "用户名:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_USERNAME, NULL, NULL);
        CreateWindow("STATIC", "密码:", WS_VISIBLE | WS_CHILD, 50, 100, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 150, 100, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 200, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("BUTTON", "登录", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
                HWND hwndUsername = GetDlgItem(hWnd, ID_EDIT_USERNAME); // 获取用户名输入框句柄
                HWND hwndPassword = GetDlgItem(hWnd, ID_EDIT_PASSWORD); // 获取密码输入框句柄
                char username[50];
                char password[50];
                GetWindowText(hwndUsername, username, 50); // 获取输入的用户名
                GetWindowText(hwndPassword, password, 50); // 获取输入的密码
                strcpy(name1,username);
                if (user_login(username, password)){
                    MessageBox(hWnd, "登录成功！", "提示", MB_OK);
                    ShowWindow(hWnd, SW_HIDE);
                    user_function(hWnd);
                }
                else{   
                    errorCount1--;
                    if (errorCount1 == 0){
                        MessageBox(hWnd, "错误次数过多，退出程序！", "提示", MB_OK);
                        ExitProcess(0);
                    }
                    char message[100];
                    sprintf(message, "用户名或密码错误！还剩余次数：%d次，请重新输入！", errorCount1);
                    MessageBox(hWnd, message, "提示", MB_OK);
                }
            }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious11, SW_SHOW);
            return 0;
            }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
void user_function(HWND hWnd) {
    g_hWndPrevious12 = hWnd;
    // 创建新的窗口来显示管理员功能界面
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcUserfun;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "UserWindowClass10";
    RegisterClass(&wc);
    HWND userHwndfun = CreateWindow("UserWindowClass10", "User Function Window", WS_OVERLAPPEDWINDOW, 200, 200, 400, 300, NULL, NULL, NULL, NULL);
    ShowWindow(userHwndfun, SW_SHOW);
}
LRESULT CALLBACK WndProcUserfun(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    int select =0;
    switch (msg) {
        case WM_CREATE:
            menu_user(hWnd);
            break;
        case WM_COMMAND:
            select = LOWORD(wParam);
            switch (select) {
                case 1:
                    ShowWindow(hWnd,SW_HIDE);
                    user_ticketissue(hWnd); // 购票界面
                    break;
                case 2:
                    ShowWindow(hWnd,SW_HIDE);
                    user_quiry(hWnd);
                    break;
                case 3:
                    ShowWindow(hWnd,SW_HIDE);
                    admin_quiry(hWnd);
                    break;
                case 0:
                    ShowWindow(hWnd,SW_HIDE);
                    ShowWindow(g_hWndPrevious12,SW_SHOW);
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
void user_ticketissue(HWND hWnd) {
    g_hWndPrevious13 = hWnd;
    // 创建新的窗口来显示管理员功能界面
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcUserticketissue;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "UserWindowClass11";
    RegisterClass(&wc);
    HWND userHwndticketissue = CreateWindow("UserWindowClass11", "User ticketissue Window", WS_OVERLAPPEDWINDOW, 200, 200, 600, 500, NULL, NULL, NULL, NULL);
    ShowWindow(userHwndticketissue, SW_SHOW);
}
LRESULT CALLBACK WndProcUserticketissue(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "注数(1~5):", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_USERNAME, NULL, NULL);
        CreateWindow("STATIC", "购买号码：", WS_VISIBLE | WS_CHILD, 50, 100, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 100, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("BUTTON", "购买", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 200, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("LISTBOX", "当期彩票信息", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 25, 250, 550, 40, hWnd, (HMENU)ID_LISTBOX8, NULL, NULL);
        userquire_curr(hWnd);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
                HWND hwndbet = GetDlgItem(hWnd, ID_EDIT_USERNAME); 
                HWND hwndnum = GetDlgItem(hWnd, ID_EDIT_PASSWORD); 
                char bet[50];
                char num[50];
                int arr[7];
                int betint;
                GetWindowText(hwndbet, bet, 50);
                GetWindowText(hwndnum, num, 50);
                char *token = strtok(num, " ");
                betint = atoi(bet);
                int i = 0;
                while (token != NULL) {
                    arr[i++] = atoi(token);
                    token = strtok(NULL, " ");
                } 
                ticket_issue(hWnd,name1,betint,arr);
            }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious13, SW_SHOW);
            return 0;
            }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
void user_quiry(HWND hWnd) {
    g_hWndPrevious14 = hWnd;
    // 创建新的窗口来显示管理员功能界面
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcUserQuiry;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "UserWindowClass12";
    RegisterClass(&wc);
    HWND userHwndquiry = CreateWindow("UserWindowClass12", "User quiry Window", WS_OVERLAPPEDWINDOW, 200, 200, 600, 500, NULL, NULL, NULL, NULL);
    ShowWindow(userHwndquiry, SW_SHOW);
}
LRESULT CALLBACK WndProcUserQuiry(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    int select =0;
    switch (msg) {
        case WM_CREATE:
            menu_userquiry(hWnd);
            break;
        case WM_COMMAND:
            select = LOWORD(wParam);
            switch (select) {
                case 1:
                    ShowWindow(hWnd,SW_HIDE);
                    user_quiryinf(hWnd); // 个人信息
                    break;
                case 2:
                    Draw_lottery(hWnd);
                    break;
                case 3:
                    ShowWindow(hWnd,SW_HIDE);
                    admin_quiry(hWnd);
                    break;
                case 0:
                    ShowWindow(hWnd,SW_HIDE);
                    ShowWindow(g_hWndPrevious14,SW_SHOW);
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
void user_quiryinf(HWND hWnd) {
    g_hWndPrevious15 = hWnd;
    // 创建新的窗口来显示管理员功能界面
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcUserQuiryinf;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "UserWindowClass13";
    RegisterClass(&wc);
    HWND userHwndquiryinf = CreateWindow("UserWindowClass13", "User quiryinf Window", WS_OVERLAPPEDWINDOW, 200, 200, 600, 200, NULL, NULL, NULL, NULL);
    ShowWindow(userHwndquiryinf, SW_SHOW);
}
LRESULT CALLBACK WndProcUserQuiryinf(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("LISTBOX", "个人信息", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 25, 50, 550, 40, hWnd, (HMENU)ID_LISTBOX9, NULL, NULL);
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 200, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        quiry_userinf(hWnd,name1);
        break;
    case WM_COMMAND: 
         if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious15, SW_SHOW);
            return 0;
            }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}