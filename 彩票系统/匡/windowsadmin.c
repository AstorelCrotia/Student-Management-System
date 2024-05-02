#include "head.h"
int errorCount=3;//验证次数
HWND g_hWndPrevious1 = NULL;
HWND g_hWndPrevious2 = NULL;
HWND g_hWndPrevious3 = NULL;
HWND g_hWndPrevious4 = NULL;
HWND g_hWndPrevious5 = NULL;
HWND g_hWndPrevious6 = NULL;
HWND g_hWndPrevious7 = NULL;
HWND g_hWndPrevious8 = NULL;
HWND g_hWndPrevious9 = NULL;
HWND g_hWndPrevious10 = NULL;
char name1[50];
char id[50];
void admin_loginw(HWND hWnd) {
    g_hWndPrevious1=hWnd;
    // 创建新的窗口来显示管理员登录界面
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdmin;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AdminWindowClass";
    RegisterClass(&wc);
    HWND adminHwndlogin = CreateWindow("AdminWindowClass", "Admin Login Window", WS_OVERLAPPEDWINDOW, 200, 200, 400, 300, NULL, NULL, NULL, NULL);
    ShowWindow(adminHwndlogin, SW_SHOW);
}
void admin_function(HWND hWnd) {
    g_hWndPrevious2 = hWnd;
    // 创建新的窗口来显示管理员功能界面
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdminfun;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AdminWindowClassFUN";
    RegisterClass(&wc);
    HWND adminHwndfun = CreateWindow("AdminWindowClassFUN", "Admin Function Window", WS_OVERLAPPEDWINDOW, 200, 200, 400, 300, NULL, NULL, NULL, NULL);
    ShowWindow(adminHwndfun, SW_SHOW);
}
void admin_issueLottery(HWND hWnd) {
    g_hWndPrevious3 = hWnd;
    // 创建新的窗口来显示管理员功能界面
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdminIssueLottery;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AdminWindowClassil";
    RegisterClass(&wc);
    HWND adminHwndissueLottery = CreateWindow("AdminWindowClassil", "Admin IssueLottery Window", WS_OVERLAPPEDWINDOW, 200, 200, 400, 300, NULL, NULL, NULL, NULL);
    ShowWindow(adminHwndissueLottery, SW_SHOW);
}
void admin_quiry(HWND hWnd) {
    g_hWndPrevious4 = hWnd;
    // 创建新的窗口来显示管理员功能界面
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdminQuiry;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AdminWindowClassQuiry";
    RegisterClass(&wc);
    HWND adminHwndquiry = CreateWindow("AdminWindowClassQuiry", "Admin Quiry Window", WS_OVERLAPPEDWINDOW, 200, 200, 400, 300, NULL, NULL, NULL, NULL);
    ShowWindow(adminHwndquiry, SW_SHOW);
}
LRESULT CALLBACK WndProcAdmin(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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
                if (admin_login(username, password)){
                    MessageBox(hWnd, "登录成功！", "提示", MB_OK);
                    ShowWindow(hWnd, SW_HIDE);
                    admin_function(hWnd);
                }
                else{   
                    errorCount--;
                    if (errorCount == 0){
                        MessageBox(hWnd, "错误次数过多，退出程序！", "提示", MB_OK);
                        ExitProcess(0);
                    }
                    char message[100];
                    sprintf(message, "用户名或密码错误！还剩余次数：%d次，请重新输入！", errorCount);
                    MessageBox(hWnd, message, "提示", MB_OK);
                }
            }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious1, SW_SHOW);
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
LRESULT CALLBACK WndProcAdminfun(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    int select =0;
    switch (msg) {
        case WM_CREATE:
            menu_admin(hWnd);
            break;
        case WM_COMMAND:
            select = LOWORD(wParam);
            switch (select) {
                case 1:
                    ShowWindow(hWnd,SW_HIDE);
                    admin_issueLottery(hWnd); // 跳转到发售彩票界面
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
                    ShowWindow(g_hWndPrevious2,SW_SHOW);
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
LRESULT CALLBACK WndProcAdminIssueLottery(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "彩票单价:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_USERNAME, NULL, NULL);
        CreateWindow("STATIC", "当期新添奖金:", WS_VISIBLE | WS_CHILD, 50, 100, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 100, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("BUTTON", "发行", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 200, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
                HWND hwndunitprice = GetDlgItem(hWnd, ID_EDIT_USERNAME); 
                HWND hwndcurrpool = GetDlgItem(hWnd, ID_EDIT_PASSWORD); 
                char unitPriceText[50];
                char currPoolText[50];
                GetWindowText(hwndunitprice, unitPriceText, 50);
                GetWindowText(hwndcurrpool, currPoolText, 50);
                int unitPrice = atoi(unitPriceText);
                int currPool = atoi(currPoolText); 
                Issue_lottery(unitPrice,currPool,hWnd);
            }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious3, SW_SHOW);
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
LRESULT CALLBACK WndProcAdminQuiry(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    int select =0;
    switch (msg) {
        case WM_CREATE:
            menu_adminquiry(hWnd);
            break;
        case WM_COMMAND:
            select = LOWORD(wParam);
            switch (select) {
                case 1:
                    quire_admin(hWnd);//管理员信息
                    break;
                case 2:
                    ShowWindow(hWnd,SW_HIDE);
                    admin_quiryPwinner(hWnd);
                    break;
                case 3:
                    ShowWindow(hWnd,SW_HIDE);
                    admin_quiryuser(hWnd);
                    break;
                case 4:
                    ShowWindow(hWnd,SW_HIDE);
                    admin_quiryticket(hWnd);
                    break;
                case 0:
                    ShowWindow(hWnd,SW_HIDE);
                    ShowWindow(g_hWndPrevious4,SW_SHOW);
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
void admin_quiryPwinner(HWND hWnd) {
    g_hWndPrevious4 = hWnd;
    // 创建新的窗口来显示管理员登录界面
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdminQuiryPwinner;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AdminWindowClass1";
    RegisterClass(&wc);
    HWND adminHwndpwinner = CreateWindow("AdminWindowClass1", "Admin Pwinner Window", WS_OVERLAPPEDWINDOW, 200, 200, 500, 500, NULL, NULL, NULL, NULL);
    ShowWindow(adminHwndpwinner, SW_SHOW);
}
LRESULT CALLBACK WndProcAdminQuiryPwinner(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "期号:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("BUTTON", "查询", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 100, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        CreateWindow("LISTBOX", "已开奖期号", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 150, 200, 200, 130, hWnd, (HMENU)ID_LISTBOX, NULL, NULL);
        quire_Pwinner(hWnd);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
                HWND hwndIssueID = GetDlgItem(hWnd, ID_EDIT_PASSWORD);
                char IssueID[50];
                GetWindowText(hwndIssueID, IssueID, 50); 
                quire_Pwinner1(hWnd,IssueID);
            }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious4, SW_SHOW);
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
void admin_quiryuser(HWND hWnd) {
    g_hWndPrevious5 = hWnd;
    // 创建新的窗口来显示管理员登录界面
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdminQuiryuser;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AdminWindowClass3";
    RegisterClass(&wc);
    HWND adminHwndUser = CreateWindow("AdminWindowClass3", "Admin User Window", WS_OVERLAPPEDWINDOW, 200, 200, 500, 500, NULL, NULL, NULL, NULL);
    ShowWindow(adminHwndUser, SW_SHOW);
}
LRESULT CALLBACK WndProcAdminQuiryuser(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "查询用户名:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("BUTTON", "查询", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 100, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        CreateWindow("LISTBOX", "存在的用户", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 150, 200, 200, 130, hWnd, (HMENU)ID_LISTBOX1, NULL, NULL);
        quire_admintoUserlist(hWnd);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
                HWND hwndname = GetDlgItem(hWnd, ID_EDIT_PASSWORD);
                char name[50];
                GetWindowText(hwndname, name, 50); 
                strcpy(name1,name);
                ShowWindow(hWnd, SW_HIDE); 
                admin_quiryuserinf(hWnd);
            }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious5, SW_SHOW);
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
void admin_quiryuserinf(HWND hWnd) {
    g_hWndPrevious6 = hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdminQuiryuserinf;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AdminWindowClass4";
    RegisterClass(&wc);
    HWND adminHwndUserinf = CreateWindow("AdminWindowClass4", "Admin Userinf Window", WS_OVERLAPPEDWINDOW, 200, 200, 1100, 1000, NULL, NULL, NULL, NULL);
    ShowWindow(adminHwndUserinf, SW_SHOW);
}
LRESULT CALLBACK WndProcAdminQuiryuserinf(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 600, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("LISTBOX", "购买信息", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 100, 100, 900, 200, hWnd, (HMENU)ID_LISTBOX2, NULL, NULL);
        CreateWindow("LISTBOX", "中奖信息", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 100, 350, 900, 200, hWnd, (HMENU)ID_LISTBOX3, NULL, NULL);
        CreateWindow("LISTBOX", "用户信息", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 100, 30, 200, 50, hWnd, (HMENU)ID_LISTBOX4, NULL, NULL);
        quire_admintoUser(hWnd,name1);
        break;
    case WM_COMMAND: 
        if(LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious6, SW_SHOW);
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
void admin_quiryticket(HWND hWnd) {
    g_hWndPrevious7 = hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdminQuiryTicket;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AdminWindowClass5";
    RegisterClass(&wc);
    HWND adminHwndTicket = CreateWindow("AdminWindowClass5", "Admin ticket Window", WS_OVERLAPPEDWINDOW, 200, 200,400,300, NULL, NULL, NULL, NULL);
    ShowWindow(adminHwndTicket, SW_SHOW);
}
LRESULT CALLBACK WndProcAdminQuiryTicket(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    int select =0;
    switch (message) {
        case WM_CREATE:
            menu_adminquiryticket(hWnd);
            break;
        case WM_COMMAND:
            select = LOWORD(wParam);
            switch (select) {
                case 1:
                    ShowWindow(hWnd,SW_HIDE);
                    admin_quiryticketcurr(hWnd);//管理员信息
                    break;
                case 2:
                    ShowWindow(hWnd,SW_HIDE);
                    admin_quiryticketprve(hWnd);
                    break;
                case 0:
                    ShowWindow(hWnd,SW_HIDE);
                    ShowWindow(g_hWndPrevious7,SW_SHOW);
                    break;
                default:
                    break;
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
void admin_quiryticketcurr(HWND hWnd) {
    g_hWndPrevious8 = hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdminQuiryTicketcurr;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AdminWindowClass6";
    RegisterClass(&wc);
    HWND adminHwndTicketcurr = CreateWindow("AdminWindowClass6", "Admin ticketcurr Window", WS_OVERLAPPEDWINDOW,200,200,1100,600, NULL, NULL, NULL, NULL);
    ShowWindow(adminHwndTicketcurr, SW_SHOW);
}
LRESULT CALLBACK WndProcAdminQuiryTicketcurr(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 500, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("LISTBOX", "当期购买情况", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 100, 100, 900, 200, hWnd, (HMENU)ID_LISTBOX5, NULL, NULL);
        quire_curr(hWnd);
        break;
    case WM_COMMAND: 
        if(LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious8, SW_SHOW);
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
void admin_quiryticketprve(HWND hWnd){
    g_hWndPrevious9 = hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdminQuiryTicketprve;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AdminWindowClass7";
    RegisterClass(&wc);
    HWND adminHwndTicketprve = CreateWindow("AdminWindowClass7", "Admin ticketprve Window", WS_OVERLAPPEDWINDOW,200,200,1100,600, NULL, NULL, NULL, NULL);
    ShowWindow(adminHwndTicketprve, SW_SHOW);
}
LRESULT CALLBACK WndProcAdminQuiryTicketprve(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "查询期号:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("BUTTON", "查询", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 100, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        CreateWindow("LISTBOX", "往期期号", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 150, 200, 400, 130, hWnd, (HMENU)ID_LISTBOX6, NULL, NULL);
        quire_prvelist(hWnd);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
                HWND hwndissueprveID = GetDlgItem(hWnd, ID_EDIT_PASSWORD);
                char issueprveID[50];
                GetWindowText(hwndissueprveID,issueprveID,50); 
                strcpy(id,issueprveID);
                ShowWindow(hWnd, SW_HIDE); 
                admin_quiryticketprveinf(hWnd);
            }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious9, SW_SHOW);
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
void admin_quiryticketprveinf(HWND hWnd){
    g_hWndPrevious10 = hWnd;
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProcAdminQuiryTicketprveinf;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "AdminWindowClass8";
    RegisterClass(&wc);
    HWND adminHwndTicketprveinf = CreateWindow("AdminWindowClass8", "Admin ticketprveinf Window", WS_OVERLAPPEDWINDOW,200,200,1100,600, NULL, NULL, NULL, NULL);
    ShowWindow(adminHwndTicketprveinf, SW_SHOW);
}
LRESULT CALLBACK WndProcAdminQuiryTicketprveinf(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 600, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("LISTBOX", "购买信息", WS_VISIBLE | WS_CHILD | LBS_STANDARD | LBS_NOTIFY, 100, 100, 900, 200, hWnd, (HMENU)ID_LISTBOX7, NULL, NULL);
        quire_prve(hWnd,id);
        break;
    case WM_COMMAND: 
        if(LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            ShowWindow(g_hWndPrevious10, SW_SHOW);
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