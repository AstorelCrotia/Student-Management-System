#include "head.h"
void menu_sign(HWND hWnd) {
    CreateWindow("BUTTON", "管理员登录", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "用户登录", WS_CHILD | WS_VISIBLE, 10, 50, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "用户注册", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)3, NULL, NULL);
    CreateWindow("BUTTON", "退出程序", WS_CHILD | WS_VISIBLE, 10, 130, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
void menu_admin(HWND hWnd) {
    CreateWindow("BUTTON", "发 行 彩 票", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "开       奖", WS_CHILD | WS_VISIBLE, 10, 50, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "查 看 信 息", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)3, NULL, NULL);
    CreateWindow("BUTTON", "返 回 主 菜 单", WS_CHILD | WS_VISIBLE, 10, 130, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
void menu_adminquiry(HWND hWnd) {
    CreateWindow("BUTTON", "管理员信息", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "历史中奖信息", WS_CHILD | WS_VISIBLE, 10, 50, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "彩民基本信息", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)3, NULL, NULL);
    CreateWindow("BUTTON", "所有购票信息", WS_CHILD | WS_VISIBLE, 10, 130, 120, 30, hWnd, (HMENU)4, NULL, NULL);
    CreateWindow("BUTTON", "返回上一级", WS_CHILD | WS_VISIBLE, 10, 170, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
void menu_adminquiryticket(HWND hWnd) {
    CreateWindow("BUTTON", "当期购票记录", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "往期购票记录", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "返回上一级", WS_CHILD | WS_VISIBLE, 10, 170, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
void menu_user(HWND hWnd) {
    CreateWindow("BUTTON", "购       票", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "查 看 信 息", WS_CHILD | WS_VISIBLE, 10, 50, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "修 改 信 息", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)3, NULL, NULL);
    CreateWindow("BUTTON", "余 额 充 值", WS_CHILD | WS_VISIBLE, 10, 130, 120, 30, hWnd, (HMENU)4, NULL, NULL);
    CreateWindow("BUTTON", "返 回 主 菜 单", WS_CHILD | WS_VISIBLE, 10, 170, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
void menu_userquiry(HWND hWnd) {
    CreateWindow("BUTTON", "个 人 信 息", WS_CHILD | WS_VISIBLE, 10, 10, 120, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindow("BUTTON", "购 买 记 录", WS_CHILD | WS_VISIBLE, 10, 50, 120, 30, hWnd, (HMENU)2, NULL, NULL);
    CreateWindow("BUTTON", "中 奖 记 录", WS_CHILD | WS_VISIBLE, 10, 90, 120, 30, hWnd, (HMENU)3, NULL, NULL);
    CreateWindow("BUTTON", "返 回 主 菜 单", WS_CHILD | WS_VISIBLE, 10, 130, 120, 30, hWnd, (HMENU)0, NULL, NULL);
}
