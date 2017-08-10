#include <iostream>
#include <cstdio>

int main() {
    char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char c;
    while((c = getchar()) != EOF){
        auto a = s;
        while(true) {
            if(*(++a) == c){
                putchar(*(--a));
                break;
            }
            if(*a == '\0'){
                putchar(c);
                break;
            }
        }
    }
    return 0;
}
