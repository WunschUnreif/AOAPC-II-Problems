#include <iostream>
#include <cstdio>
#include <cstring>

char puzzle[5][5];
int blankRow = 0,blankCol = 0;

bool A() {
    if(blankRow == 0) return false;
    puzzle[blankRow][blankCol] = puzzle[blankRow - 1][blankCol];
    blankRow--;
    puzzle[blankRow][blankCol] = ' ';
    return true;
}
bool B() {
    if(blankRow == 4) return false;
    puzzle[blankRow][blankCol] = puzzle[blankRow + 1][blankCol];
    blankRow++;
    puzzle[blankRow][blankCol] = ' ';
    return true;
}
bool L() {
    if(blankCol == 0) return false;
    puzzle[blankRow][blankCol] = puzzle[blankRow][blankCol-1];
    blankCol--;
    puzzle[blankRow][blankCol] = ' ';
    return true;
}
bool R() {
    if(blankRow == 4) return false;
    puzzle[blankRow][blankCol] = puzzle[blankRow][blankCol + 1];
    blankCol++;
    puzzle[blankRow][blankCol] = ' ';
    return true;
}

int main() {
    bool notEnd = true;
    int gameCount = 0;
    while(true) {
        gameCount ++;
        memset(puzzle, 0, sizeof(puzzle));
        blankRow = 0,blankCol = 0;
        char s[100];
        fgets(s, 100, stdin);
        //printf("len %s\n",s);
        if(strlen(s) == 1) break;
        for(int i = 0; i < 5; i++){puzzle[0][i] = s[i];if(!isalpha(s[i]))blankCol = i;if(!isalpha(puzzle[0][i]))puzzle[0][i] = ' ';}
        for(int i = 1; i <= 4; i++) {
            fgets(s, 100, stdin);
            for(int j = 0; j < 5; j++){puzzle[i][j] = s[j];if(!isalpha(s[j])){blankRow = i;blankCol = j;}if(!isalpha(puzzle[i][j]))puzzle[i][j] = ' ';}
        }
        if(gameCount != 1) printf("\n");
        printf("Puzzle #%d:\n", gameCount);
        char cmd;
        bool legal = true;
        while((cmd = getchar()) != '0') {
            // for(int i =0; i < 5; i++) {
            //     for(int j = 0; j < 5; j++) {
            //         if(j == 0)printf("%c",puzzle[i][j]);else printf(" %c",puzzle[i][j]);
            //     }
            //     printf("\n");
            // }
            if(cmd >= 'A' && cmd <= 'Z' && legal) {
                switch(cmd) {
                    case 'A':if(!A()){printf("This puzzle has no final configuration.");legal = false;}break;
                    case 'B':if(!B()){printf("This puzzle has no final configuration.");legal = false;}break;
                    case 'R':if(!R()){printf("This puzzle has no final configuration.");legal = false;}break;
                    case 'L':if(!L()){printf("This puzzle has no final configuration.");legal = false;}break;
                    default:printf("This puzzle has no final configuration.");legal = false;
                }
            }
        }
        if(legal) {
            for(int i =0; i < 5; i++) {
                for(int j = 0; j < 5; j++) {
                    if(j == 0)printf("%c",puzzle[i][j]);else printf(" %c",puzzle[i][j]);
                }
                printf("\n");
            }
        }
        fgets(s, 100, stdin);
    }
    return 0;
}
