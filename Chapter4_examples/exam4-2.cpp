#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int used[260];
char answer[110];
char guess[110];
bool win = false;
bool lose = false;

void solve() {
    int wrongTime = 0;
    int rightNum = 0;
    scanf("%s%s", answer, guess);
    int glen = strlen(guess), alen = strlen(answer);
    for(int i = 0; i < glen; i++) {
        bool ok = false;
        for(int j = 0; j < alen; j++){
            if(answer[j] == guess[i]) {
                answer[j] = ' ';
                rightNum++;
                ok = true;
            }
        }
        //printf("guess %c, rt=%d\n",guess[i],rightNum);
        if(!ok)wrongTime++;
        if(wrongTime > 6) {lose = true;return;}
        if(rightNum == alen){win = true; return;}
    }
}

int main() {
    int gameRound = 0;
    while(scanf("%d", &gameRound)) {
        if(gameRound == -1) break;
        memset(used, 0, sizeof(used));
        win = lose = false;
        solve();
        printf("Round %d\n",gameRound);
        if(win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}
