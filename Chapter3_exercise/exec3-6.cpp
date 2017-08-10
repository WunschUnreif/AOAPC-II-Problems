#include <iostream>
#include <cstdio>
#include <cstring>

char words[15][15];
int number[15][15];
int numUse = 0;

int main() {
    int r, c, game = 0;
    while(scanf("%d%d", &r, &c) == 2) {
        game++;
        memset(words, 0, sizeof(words));
        memset(number, 0, sizeof(number));
        numUse = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                scanf("%c",&words[i][j]);
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(words[i][j] != '*') {
                    if(i-1<0 || words[i-1][j] == '*' || j-1<0 || words[i][j-1] == '*') {
                        number[i][j] = ++numUse;
                    }
                }
            }
        }
        printf("puzzle #%d\n",game);
        char s[13] = "";
        int startnum = 0, len = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(words[i][j] == '*' && len) {
                    printf("%3d.%s\n",startnum, s);
                    startnum = 0;s = "";len = 0;
                }
            }
        }
    }
}
