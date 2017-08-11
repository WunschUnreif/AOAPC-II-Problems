#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <map>
#include <queue>
using namespace std;

int Pair(int a, int b) {return a * 100000 + b;}
map<string, int> IDCache;
int number = 0;
int getID(string str) {
    if(IDCache.count(str)) return IDCache[str];
    return IDCache[str] = number++;
}
void solve(int rows, int cols) {
    getchar();
    int table[rows][cols];
    number = 0;
    IDCache.clear();
    for(int i = 0; i < rows; i++) {
        int j = 0;
        char s[82];int used = 0;
        char c;
        while(c = getchar()) {
            if(c == ',' || c == '\n' || c == EOF) {
                s[used] = '\0';
                table[i][j] = getID(string(s));
                //printf("%d,%d:%s\n",i,j,s);
                j++;
                used = 0;
            } else {
                s[used++] = c;
            }
            if(j == cols) break;
        }
    }
    //cout << rows << ' ' << cols << endl;
    for(int c1 = 0; c1 < cols; c1++) {
        for(int c2 = c1 + 1; c2 < cols; c2++) {
            map<int, int> rowAccount;
            for(int r = 0; r < rows; r++) {
                if(!rowAccount.count(Pair(table[r][c1], table[r][c2]))) rowAccount[Pair(table[r][c1], table[r][c2])] = r;
                else {
                    cout << "NO" << endl << (rowAccount[Pair(table[r][c1], table[r][c2])] + 1) << ' ' << (r + 1) << endl <<
                        (c1 + 1) << ' ' << (c2 + 1) << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
}

int main() {
    int r,c;
    while(scanf("%d%d",&r,&c) == 2) solve(r,c);
    return 0;
}

