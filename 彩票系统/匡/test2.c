#include <windows.h>

#define ID_EDIT_PASSWORD 101
//#define IDOK 102
#define ID_RETURN 103

// �����Ѳ�ѯ�б�
char queriedList[3][50] = {"2022001", "2022002", "2022003"};

typedef struct {
    char issueID[50];
    char prizeInfo[100];
} PrizeWinnerInfo;

PrizeWinnerInfo prizeWinnerInfos[] = {
    {"2022001", "һ�Ƚ���1000Ԫ�����Ƚ���500Ԫ"},
    {"2022002", "һ�Ƚ���800Ԫ�����Ƚ���400Ԫ"},
    {"2022003", "һ�Ƚ���1200Ԫ�����Ƚ���600Ԫ"}
};

LRESULT CALLBACK WndProcAdminQuiryPwinner(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{   
    switch (message)
    {
    case WM_CREATE:
        CreateWindow("STATIC", "�ں�:", WS_VISIBLE | WS_CHILD, 50, 50, 100, 25, hWnd, NULL, NULL, NULL);
        CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 50, 150, 25, hWnd, (HMENU)ID_EDIT_PASSWORD, NULL, NULL);
        CreateWindow("BUTTON", "����", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 150, 100, 30, hWnd, (HMENU)ID_RETURN, NULL, NULL);
        CreateWindow("BUTTON", "��ѯ", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 150, 100, 100, 30, hWnd, (HMENU)IDOK, NULL, NULL);
        break;
    case WM_COMMAND: 
        if (LOWORD(wParam) == IDOK){   
            HWND hwndIssueID = GetDlgItem(hWnd, ID_EDIT_PASSWORD);
            char IssueID[50];
            GetWindowText(hwndIssueID, IssueID, 50); 

            // ��ѯ��Ϣ
            for (int i = 0; i < 3; i++) {
                if (strcmp(queriedList[i], IssueID) == 0) {
                    // ��ѯ����Ӧ�ں���Ϣ
                    MessageBox(hWnd, prizeWinnerInfos[i].prizeInfo, "�н���Ϣ", MB_OK);
                    break;
                }
            }
        }
        else if (LOWORD(wParam) == ID_RETURN) {
            ShowWindow(hWnd, SW_HIDE); // ���ص�ǰ����
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