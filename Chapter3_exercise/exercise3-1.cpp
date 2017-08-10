#include <iostream>
#include <cstdio>
#include <cstring>

int scores[100];

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(scores,0,sizeof(scores));
        int ans = 0;
        char s[100];
        scanf("%s",s);
        for(int i = 1; i <= strlen(s); i++) {
            if(s[i - 1] == 'O') scores[i] = scores[i - 1] + 1;
            ans += scores[i];
            //printf("score %d = %d\n",i,scores[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
