#include <iostream>
#include <cstdio>
#include <cstring>

int count1[10];
int count2[10];
int countR[10];
int a[1010];
int b[1010];
int A,B;

int main() {
    int gameCount = 0;
    int n;
    while((scanf("%d",&n) == 1) && n) {
        gameCount++;
        memset(count1,0,sizeof(count1));
        for(int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
            count1[a[i]]++;
        }
        printf("Game %d:\n", gameCount);
        while(true) {
            A = B = 0;
            memset(count2,0,sizeof(count2));
            memset(countR,0,sizeof(countR));
            for(int i = 0; i < n; i++) {
                scanf("%d", &b[i]);
                count2[b[i]]++;
                if(a[i] == b[i]) {A++;countR[b[i]]++;}
            }
            if(b[0] == 0) break;
            for(int i = 1; i <= 9; i++) {
                B += std::min(count1[i], count2[i]) - countR[i];
            }
            printf("    (%d,%d)\n",A,B);
        }
    }
    return 0;
}
