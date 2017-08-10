#include <iostream>
#include <cstdio>
#include <cstring>

int main() {
    char s[100010], t[100010];
    while(scanf("%s%s",s,t) == 2) {
        int sl, tl;
        sl = strlen(s); tl = strlen(t);
        //printf("%s %d %s %d\n", s, sl, t, tl);
        if(sl > tl) {
            printf("No\n");
            continue;
        } else if(sl == tl) {
            if(!strcmp(s,t)) printf("Yes\n");
            else printf("No\n");
            continue;
        } else {
            int k = 0;
            for(int i = 0; i < sl && k < tl; i++, k++) {
                while(s[i] != t[k] && k < tl) k++;
            }
            if(k <= tl) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
