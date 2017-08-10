#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
char codeHead[1000];int headLen = 0;
void readHead(){
    char c;
    headLen = 0;
    while((c = getchar()) != EOF) {
        if(c == '\n' || c == '\r') break;
        codeHead[headLen++] = c;
    }
    codeHead[headLen] = '\0';
    //printf("%s",codeHead);
}

void printCode(){
    while(true) {
        int len = 0;
        char c;
        while((c = getchar()) == '\n' || c == '\r');if(c == '1')len += 4;
        while((c = getchar()) == '\n' || c == '\r');if(c == '1')len += 2;
        while((c = getchar()) == '\n' || c == '\r');if(c == '1')len += 1;
        if(len == 0)break;
        while(true) {
            int code = 0;
            for(int i = 0; i < len; i++) {
                while((c = getchar()) == '\n' || c == '\r');if(c == '1')code += 1 << (len - i - 1);
            }
            if(code == (1 << len) - 1) break;
            //printf("code%d",code);
            printf("%c",codeHead[code + ((1 << len) - len - 1)]);
        }
    }
    printf("\n");
}

int main() {
    while(true){
        readHead();
        if(headLen == 0)break;
        printCode();
        getchar();
    }
    return 0;
}
