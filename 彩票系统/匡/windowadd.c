#include "head.h"
HWND g_hWndPrevious22 = NULL;
void user_add(HWND hWnd) {
    g_hWndPrevious22=hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdd;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AddWindowClass";
    RegisterClass(&wc);
    HWND AddHwnduser = CreateWindow("AddWindowClass", "Add User Window", WS_OVERLAPPEDWINDOW, 200, 200, 400, 500, NULL, NULL, NULL, NULL);
    ShowWindow(AddHwnduser, SW_SHOW);
}
LRESULT CALLBACK WndProcAdd(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "用户名:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_USERNAME, NULL, NULL);
        CreateWindow("STATIC", "密码:", WS_VISIBLE | WS_CHILD, 50, 100, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 150, 100, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("STATIC", "再次输入:", WS_VISIBLE | WS_CHILD, 50, 150, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 150, 150, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD1, NULL, NULL);
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 250, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("BUTTON", "修改", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 200, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
                HWND hwndAddname = GetDlgItem(hWnd, ID_EDIT_USERNAME); // 获取修改输入框句柄
                HWND hwndAddpassword = GetDlgItem(hWnd, ID_EDIT_PASSWORD);
                HWND hwndAddpassword1 = GetDlgItem(hWnd, ID_EDIT_PASSWORD1); // 获取再次修改输入框句柄
                char addname[50];
                char addpassword[50];
                char addpassword1[50];
                GetWindowText(hwndAddname, addname, 50); 
                GetWindowText(hwndAddpassword, addpassword, 50);
                GetWindowText(hwndAddpassword1, addpassword1, 50);
                if(!strcmp(addpassword,addpassword1)){
                    if(!registerUser(hWnd,addname,addpassword)){
                        MessageBox(hWnd,"注册成功！","提示",MB_OK);
                    }
                }else{
                    MessageBox(hWnd,"两次输入密码不一致！","提示",MB_OK);
                }
                
            }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious22, SW_SHOW);
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