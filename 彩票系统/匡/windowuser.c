#include "head.h"
int errorCount1=3;
char name1[50];
HWND g_hWndPrevious11 = NULL;
HWND g_hWndPrevious12 = NULL;
HWND g_hWndPrevious13 = NULL;
HWND g_hWndPrevious14 = NULL;
HWND g_hWndPrevious15 = NULL;
HWND g_hWndPrevious16 = NULL;
HWND g_hWndPrevious17 = NULL;
HWND g_hWndPrevious18 = NULL;
HWND g_hWndPrevious19 = NULL;
HWND g_hWndPrevious20 = NULL;
HWND g_hWndPrevious21 = NULL;
void user_loginw(HWND hWnd) {
    g_hWndPrevious11=hWnd;
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
                    user_quiry(hWnd);//��ѯ����
                    break;
                case 3:
                    ShowWindow(hWnd,SW_HIDE);
                    user_modify(hWnd);//�޸Ľ���
                    break;
                case 4:
                    ShowWindow(hWnd,SW_HIDE);
                    user_recharge(hWnd);//����ֵ
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
                    ShowWindow(hWnd,SW_HIDE);
                    user_quiryticket(hWnd);//�����¼
                    break;
                case 3:
                    ShowWindow(hWnd,SW_HIDE);
                    user_quirywin(hWnd);//�н���¼
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
        CreateWindow("BUTTON", "����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 25, 120, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
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
void user_quiryticket(HWND hWnd) {
    g_hWndPrevious16 = hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcUserQuiryticket;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "UserWindowClass14";
    RegisterClass(&wc);
    HWND userHwndquiryticket = CreateWindow("UserWindowClass14", "User quiryticket Window", WS_OVERLAPPEDWINDOW, 200, 200, 1000, 1000, NULL, NULL, NULL, NULL);
    ShowWindow(userHwndquiryticket, SW_SHOW);
}
LRESULT CALLBACK WndProcUserQuiryticket(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("LISTBOX", "������Ϣ", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 25, 50, 950, 300, hWnd, (HMENU)ID_LISTBOX10, NULL, NULL);
        CreateWindow("BUTTON", "����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 400, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        quiry_buyticket(hWnd,name1);
        break;
    case WM_COMMAND: 
         if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // ���ص�ǰ����
            ShowWindow(g_hWndPrevious16, SW_SHOW);
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
void user_quirywin(HWND hWnd) {
    g_hWndPrevious17 = hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcUserQuirywin;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "UserWindowClass15";
    RegisterClass(&wc);
    HWND userHwndquirywin = CreateWindow("UserWindowClass15", "User quirywin Window", WS_OVERLAPPEDWINDOW, 200, 200, 1000, 1000, NULL, NULL, NULL, NULL);
    ShowWindow(userHwndquirywin, SW_SHOW);
}
LRESULT CALLBACK WndProcUserQuirywin(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("LISTBOX", "�н���Ϣ", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 25, 50, 950, 300, hWnd, (HMENU)ID_LISTBOX11, NULL, NULL);
        CreateWindow("BUTTON", "����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 400, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        quiry_userwin(hWnd,name1);
        break;
    case WM_COMMAND: 
         if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // ���ص�ǰ����
            ShowWindow(g_hWndPrevious17, SW_SHOW);
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
void user_modify(HWND hWnd) {
    g_hWndPrevious18 = hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcUserModify;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "UserWindowClass16";
    RegisterClass(&wc);
    HWND userHwndmodify = CreateWindow("UserWindowClass16", "User modify Window", WS_OVERLAPPEDWINDOW, 200, 200, 600, 500, NULL, NULL, NULL, NULL);
    ShowWindow(userHwndmodify, SW_SHOW);
}
LRESULT CALLBACK WndProcUserModify(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    int select =0;
    switch (msg) {
        case WM_CREATE:
            menu_usermodify(hWnd);
            break;
        case WM_COMMAND:
            select = LOWORD(wParam);
            switch (select) {
                case 1:
                    ShowWindow(hWnd,SW_HIDE);
                    user_modifyname(hWnd); // �޸��û���
                    break;
                case 2:
                    ShowWindow(hWnd,SW_HIDE);
                    user_modifypassword(hWnd);//�޸�����
                    break;
                case 0:
                    ShowWindow(hWnd,SW_HIDE);
                    ShowWindow(g_hWndPrevious18,SW_SHOW);
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
void user_modifyname(HWND hWnd) {
    g_hWndPrevious19 = hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcUserModifyName;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "UserWindowClass17";
    RegisterClass(&wc);
    HWND userHwndmodifyname = CreateWindow("UserWindowClass17", "User modifyname Window", WS_OVERLAPPEDWINDOW, 200, 200, 600, 500, NULL, NULL, NULL, NULL);
    ShowWindow(userHwndmodifyname, SW_SHOW);
}
LRESULT CALLBACK WndProcUserModifyName(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "�޸��û���:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_USERNAME, NULL, NULL);
        CreateWindow("BUTTON", "����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 200, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("BUTTON", "�޸�", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
                HWND hwndModifyname = GetDlgItem(hWnd, ID_EDIT_USERNAME); // ��ȡ�޸��û����������
                char modifyname[50];
                GetWindowText(hwndModifyname, modifyname, 50); // ��ȡ������޸��û���
                if(!modify_userName(hWnd,name1,modifyname)){
                    strcpy(name1,modifyname);
                }
            }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // ���ص�ǰ����
            ShowWindow(g_hWndPrevious19, SW_SHOW);
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
void user_modifypassword(HWND hWnd) {
    g_hWndPrevious20 = hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcUserModifyPassword;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "UserWindowClass18";
    RegisterClass(&wc);
    HWND userHwndmodifypassword = CreateWindow("UserWindowClass18", "User modifypassword Window", WS_OVERLAPPEDWINDOW, 200, 200, 600, 500, NULL, NULL, NULL, NULL);
    ShowWindow(userHwndmodifypassword, SW_SHOW);
}
LRESULT CALLBACK WndProcUserModifyPassword(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "����:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("STATIC", "�ٴ�����:", WS_VISIBLE | WS_CHILD, 50, 100, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_PASSWORD, 150, 100, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD1, NULL, NULL);
        CreateWindow("BUTTON", "����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 200, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("BUTTON", "�޸�", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
                HWND hwndModifypassword = GetDlgItem(hWnd, ID_EDIT_PASSWORD); // ��ȡ�޸��������
                HWND hwndModifypassword1 = GetDlgItem(hWnd, ID_EDIT_PASSWORD1); // ��ȡ�ٴ��޸��������
                char modifypassword[50];
                char modifypassword1[50];
                GetWindowText(hwndModifypassword, modifypassword, 50); 
                GetWindowText(hwndModifypassword1, modifypassword1, 50);
                if(!strcmp(modifypassword,modifypassword1)){
                    modify_userPassword(hWnd,modifypassword,name1);
                }else{
                    MessageBox(hWnd,"�������벻һ�£�����������!","��ʾ",MB_OK);
                }
            }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // ���ص�ǰ����
            ShowWindow(g_hWndPrevious20, SW_SHOW);
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
void user_recharge(HWND hWnd) {
    g_hWndPrevious21 = hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcUserrecharge;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "UserWindowClass19";
    RegisterClass(&wc);
    HWND userHwndrecharge = CreateWindow("UserWindowClass19", "User recharge Window", WS_OVERLAPPEDWINDOW, 200, 200, 600, 500, NULL, NULL, NULL, NULL);
    ShowWindow(userHwndrecharge, SW_SHOW);
}
LRESULT CALLBACK WndProcUserrecharge(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "��ֵ���:", WS_VISIBLE | WS_CHILD, 50,100,100,25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150,100,150,25, hWnd, (HMENU)ID_EDIT_USERNAME, NULL, NULL);
        CreateWindow("BUTTON", "����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150,200,100,30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("BUTTON", "ȷ�ϳ�ֵ", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,150,150,100,30, hWnd, (HMENU)IDOK, NULL, NULL);
        CreateWindow("LISTBOX", "���", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 50,50,200,40, hWnd, (HMENU)ID_LISTBOX11, NULL, NULL);
        banlance(hWnd,name1);
        break;
    case WM_COMMAND: 
        if(LOWORD(wParam) == IDOK){
            HWND hwndrecharge = GetDlgItem(hWnd, ID_EDIT_USERNAME); // ��ȡ�޸��������
            char rechargemoney[50];
            GetWindowText(hwndrecharge, rechargemoney, 50); 
            int money=atoi(rechargemoney);
            recharge(hWnd,name1,money);
        }else if (LOWORD(wParam) == ID_RETURN){
            ShowWindow(hWnd, SW_HIDE); // ���ص�ǰ����
            ShowWindow(g_hWndPrevious21, SW_SHOW);
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