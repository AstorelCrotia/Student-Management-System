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
    // �����µĴ�������ʾ����Ա��¼����
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
        CreateWindow("STATIC", "�û���:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_USERNAME, NULL, NULL);
        CreateWindow("STATIC", "����:", WS_VISIBLE | WS_CHILD, 50, 100, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 150, 100, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("BUTTON", "����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 200, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("BUTTON", "��¼", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
                HWND hwndUsername = GetDlgItem(hWnd, ID_EDIT_USERNAME); // ��ȡ�û����������
                HWND hwndPassword = GetDlgItem(hWnd, ID_EDIT_PASSWORD); // ��ȡ�����������
                char username[50];
                char password[50];
                GetWindowText(hwndUsername, username, 50); // ��ȡ������û���
                GetWindowText(hwndPassword, password, 50); // ��ȡ���������
                strcpy(name1,username);
                if (user_login(username, password)){
                    MessageBox(hWnd, "��¼�ɹ���", "��ʾ", MB_OK);
                    ShowWindow(hWnd, SW_HIDE);
                    user_function(hWnd);
                }
                else{   
                    errorCount1--;
                    if (errorCount1 == 0){
                        MessageBox(hWnd, "����������࣬�˳�����", "��ʾ", MB_OK);
                        ExitProcess(0);
                    }
                    char message[100];
                    sprintf(message, "�û�����������󣡻�ʣ�������%d�Σ����������룡", errorCount1);
                    MessageBox(hWnd, message, "��ʾ", MB_OK);
                }
            }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // ���ص�ǰ����
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
    // �����µĴ�������ʾ����Ա���ܽ���
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
                    user_ticketissue(hWnd); // ��Ʊ����
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
    // �����µĴ�������ʾ����Ա���ܽ���
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
        CreateWindow("STATIC", "ע��(1~5):", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_USERNAME, NULL, NULL);
        CreateWindow("STATIC", "������룺", WS_VISIBLE | WS_CHILD, 50, 100, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 100, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("BUTTON", "����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        CreateWindow("BUTTON", "����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 200, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("LISTBOX", "���ڲ�Ʊ��Ϣ", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 25, 250, 550, 40, hWnd, (HMENU)ID_LISTBOX8, NULL, NULL);
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
            ShowWindow(hWnd, SW_HIDE); // ���ص�ǰ����
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
    // �����µĴ�������ʾ����Ա���ܽ���
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
                    user_quiryinf(hWnd); // ������Ϣ
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
    // �����µĴ�������ʾ����Ա���ܽ���
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
        CreateWindow("LISTBOX", "������Ϣ", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 25, 50, 550, 40, hWnd, (HMENU)ID_LISTBOX9, NULL, NULL);
        CreateWindow("BUTTON", "����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 200, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        quiry_userinf(hWnd,name1);
        break;
    case WM_COMMAND: 
         if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // ���ص�ǰ����
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