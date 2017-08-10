#include <iostream>
#include <cstdio>
#include <cstring>

int main() {
    int ta,tb;
    int quo[3010], ql, rem[3010], rl;
    bool first = true;
    while(scanf("%d%d", &ta, &tb) == 2) {
        int a = ta, b = tb;
        if(a == b) {
                printf("%d/%d = 1.(0)\n   1 = number of digits in repeating cycle\n\n",a ,b);
            continue;
        }
        memset(quo, 0, sizeof(quo));
        memset(rem, 0, sizeof(rem));
        ql = rl = 0;
        int repStart = 0;
        int repLength = 1;
        bool notRep = true;
        while(notRep) {
            if(ql == 0) {
                quo[ql++] = a / b;
                rem[rl++] = a % b;
            } else {
                quo[ql++] = rem[rl - 1] * 10 / b;
                rem[rl] = rem[rl - 1] * 10 % b;rl++;
                if(rem[rl - 1] == 0) {
                    repStart = rl;
                    notRep = false;
                    break;
                }
                for(int i = 0; i < rl - 1; i++) {
                    if(rem[i] == rem[rl - 1]) {
                        repStart = i + 1;
                        repLength = ql - repStart;
                        notRep = false;
                        break;
                    }
                }
            }
        }
        //if(!first) printf("\n");
        int count = 0;
        printf("%d/%d = %d.", ta, tb, quo[0]);
        for(int i = 1; i < repStart; i++) {
            printf("%d", quo[i]);count ++;
            if(count >= 50) break;
        }
        if(repStart == rl && count < 50) {
            printf("(0)");
        } else if(count < 50) {
            printf("(");
            for(int i = repStart; i < ql; i++) {
                printf("%d",quo[i]);count++;
                if(count >= 50) break;
            }
            if(count < 50)printf(")"); else printf("...)");
        }
        printf("\n   %d = number of digits in repeating cycle\n\n", repLength);
        first = false;
    }
    return 0;
}