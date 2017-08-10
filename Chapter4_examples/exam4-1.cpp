#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int cnt1[26];
int cnt2[26];

bool check(){
    for(int i = 0; i < 26; i++)
        if(cnt1[i] != cnt2[i])
            return false;
    return true;
}


bool solve() {
    char src[200], dst[200];
    if(scanf("%s %s",src, dst) != 2) return false;
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for(int i = 0; i < strlen(src); i++) {
        cnt1[src[i] - 'A']++;
        cnt2[dst[i] - 'A']++;
    }
    std::sort(cnt1, cnt1 + 26);
    std::sort(cnt2, cnt2 + 26);
    if(check()) printf("YES\n");
    else printf("NO\n");
    return true;
}

int main() {
    while(solve());
    return 0;
}