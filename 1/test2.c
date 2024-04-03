#include <windows.h>

#define ID_EDIT_PASSWORD 101
//#define IDOK 102
#define ID_RETURN 103

// 假设已查询列表
char queriedList[3][50] = {"2022001", "2022002", "2022003"};

typedef struct {
    char issueID[50];
    char prizeInfo[100];
} PrizeWinnerInfo;

PrizeWinnerInfo prizeWinnerInfos[] = {
    {"2022001", "一等奖：1000元；二等奖：500元"},
    {"2022002", "一等奖：800元；二等奖：400元"},
    {"2022003", "一等奖：1200元；二等奖：600元"}
};

LRESULT CALLBACK WndProcAdminQuiryPwinner(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "期号:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("BUTTON", "返回", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("BUTTON", "查询", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 100, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
            HWND hwndIssueID = GetDlgItem(hWnd, ID_EDIT_PASSWORD);
            char IssueID[50];
            GetWindowText(hwndIssueID, IssueID, 50); 

            // 查询信息
            for (int i = 0; i < 3; i++) {
                if (strcmp(queriedList[i], IssueID) == 0) {
                    // 查询到对应期号信息
                    MessageBox(hWnd, prizeWinnerInfos[i].prizeInfo, "中奖信息", MB_OK);
                    break;
                }
            }
        }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // 隐藏当前窗口
            //ShowWindow(g_hWndPrevious5, SW_SHOW);
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