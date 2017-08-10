#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int bar1[300];
int bar2[300];
int len1, len2;

bool check(int k){
    for(int i = 0; i < (len2 + k > len1) ? len1 - k : len2; i++) {
        if(bar1[i + k] + bar2[i] > 3) return false;
    }
    return true;
}
bool checkRev(int k){
    for(int i = 0; i < len2 - k; i++) {
        if(bar1[i] + bar2[i + k] > 3) return false;
    }
    return true;
}

int main() {
    char s1[300], s2[300];
    while(scanf("%s%s",s1,s2) == 2) {
        memset(bar1,0,sizeof(bar1));
        memset(bar2,0,sizeof(bar2));
        len1 = strlen(s1);len2 = strlen(s2);
        for(int i = 0; i < len1; i++) bar1[i] = s1[i] - '0';
        for(int i = 0; i < len2; i++) bar2[i] = s2[i] - '0';
        int ans = 0x3f3f3f3f;
        for(int i = 0; i <= len1; i++){
            if(check(i)) {
                ans = std::max(len1, len2 + i);
                //printf("%d %d\n", i, check(i));
                break;
            }
        }
        for(int i = 0; i <= len2; i++){
            if(checkRev(i)) {
                ans = std::min(len1 + i,ans);
                //printf("%dr%d\n", i, checkRev(i));
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
