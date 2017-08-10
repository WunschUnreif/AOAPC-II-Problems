#include <iostream>
#include <cstdio>
#include <cstring>

bool check(char *s, int length, int k) {
    char a[100], b[100];
    strncpy(a,s,k);
    for(int i = 0; i < length / k - 1; i++) {
        strncpy(b,s + k * (i+1), k);
        //printf("%s %s\n",a ,b);
        if(strcmp(a,b)) return false;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    char s[100];
    while(t--) {
        scanf("%s", s);
        int length = strlen(s);
        for(int i = 1; i <= length; i++) {
            if(length % i == 0) {
                if(i == length) {printf("%d\n",i); break;}
                if(check(s,length,i)) {printf("%d\n",i); break;}
            }
        }
        if(t) printf("\n");
    }
    return 0;
}