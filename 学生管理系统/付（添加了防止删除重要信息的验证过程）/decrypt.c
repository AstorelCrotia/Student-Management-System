#include "head.h"

char *decrypt(char *code){//获取解密后的密码
    int len=strlen(code);
    for(int i=0;i<len;i++){
        char c=code[i];
        if(c>='a'&&c<='z'){
            if(c+5%26<='z'){
                code[i]=(char)(c+5%26);
            }else{
                code[i]=(char)(c+5%26-26);
            }
        }else if(c>='A'&&c<='Z'){
            if(c+5%26<='Z'){
                code[i]=(char)(c+5%26);
            }else{
                code[i]=(char)(c+5%26-26);
            }
        }else{
                code[i]=c;
        }
    }
    return code;
}
