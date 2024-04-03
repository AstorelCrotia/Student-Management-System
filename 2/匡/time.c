#include "head.h"

void delay(int seconds){//延时函数
    clock_t start_time=clock();
    while(clock()<start_time+seconds*CLOCKS_PER_SEC);
}
char *Verification_code(){
    static char ver[4];
    srand(time(0));
    for(int i=0;i<4;i++){
        if(i%2==0){
            ver[i]=rand()%26+'a';
        }else{
            ver[i]=rand()%26+'A';
        }
    }
    ver[4]='\0';
    return ver;
}
 void Countdown(int seconds){
    while(--seconds>=0){
        Sleep(1000);
        printf("请等待%-2ds后再进行验证！\r",seconds);
    }
 }
void getData(char *date){
    time_t now;
    struct tm *local_time; // 存储日期的字符串，格式为"YYYY-MM-DD"
    time(&now);
    local_time = localtime(&now);
    strftime(date, 11, "%Y-%m-%d", local_time);
}