#include "head.h"
void menu_sign(HWND hWnd) {
    CreateWindow("BUTTON", "����Ա��¼", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "�û���¼", WS_CHILD | WS_VISIBLE, 10, 50, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "�û�ע��", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)3, NULL, NULL);
    CreateWindow("BUTTON", "�˳�����", WS_CHILD | WS_VISIBLE, 10, 130, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
void menu_admin(HWND hWnd) {
    CreateWindow("BUTTON", "�� �� �� Ʊ", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "��       ��", WS_CHILD | WS_VISIBLE, 10, 50, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "�� �� �� Ϣ", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)3, NULL, NULL);
    CreateWindow("BUTTON", "�� �� �� �� ��", WS_CHILD | WS_VISIBLE, 10, 130, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
void menu_adminquiry(HWND hWnd) {
    CreateWindow("BUTTON", "����Ա��Ϣ", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "��ʷ�н���Ϣ", WS_CHILD | WS_VISIBLE, 10, 50, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "���������Ϣ", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)3, NULL, NULL);
    CreateWindow("BUTTON", "���й�Ʊ��Ϣ", WS_CHILD | WS_VISIBLE, 10, 130, 120, 30, hWnd, (HMENU)4, NULL, NULL);
    CreateWindow("BUTTON", "������һ��", WS_CHILD | WS_VISIBLE, 10, 170, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
void menu_adminquiryticket(HWND hWnd) {
    CreateWindow("BUTTON", "���ڹ�Ʊ��¼", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "���ڹ�Ʊ��¼", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "������һ��", WS_CHILD | WS_VISIBLE, 10, 170, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
void menu_user(HWND hWnd) {
    CreateWindow("BUTTON", "��       Ʊ", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "�� �� �� Ϣ", WS_CHILD | WS_VISIBLE, 10, 50, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "�� �� �� Ϣ", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)3, NULL, NULL);
    CreateWindow("BUTTON", "�� �� �� ֵ", WS_CHILD | WS_VISIBLE, 10, 130, 120, 30, hWnd, (HMENU)4, NULL, NULL);
    CreateWindow("BUTTON", "�� �� �� �� ��", WS_CHILD | WS_VISIBLE, 10, 170, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
void menu_userquiry(HWND hWnd) {
    CreateWindow("BUTTON", "�� �� �� Ϣ", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "�� �� �� ¼", WS_CHILD | WS_VISIBLE, 10, 50, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "�� �� �� ¼", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)3, NULL, NULL);
    CreateWindow("BUTTON", "�� �� �� �� ��", WS_CHILD | WS_VISIBLE, 10, 130, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
