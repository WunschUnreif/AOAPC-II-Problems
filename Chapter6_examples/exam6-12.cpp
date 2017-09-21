#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <map>
#include <queue>
using namespace std;

int graph[101][101];
int dir_x[8] = {0,0,-1,1,1,-1,1,-1};
int dir_y[8] = {1,-1,0,0,1,1,-1,-1};
int r, c;

void dfs(int x, int y){
    graph[x][y] = 2;
    for(int i = 0; i < 8; i++) {
        if(x + dir_x[i] >= r || x + dir_x[i] < 0 ||
            y + dir_y[i] >= c || y + dir_y[i] < 0) continue;
        if(graph[x + dir_x[i]][y + dir_y[i]] == 1)
            dfs(x + dir_x[i], y + dir_y[i]);
    }
}

bool read() {
    memset(graph, 0, sizeof(graph));
    cin >> r >> c;
    if(r == 0) return false;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            char c;
            cin >> c;
            if(c == '@') graph[i][j] = 1;
        }
    }
    return true;
}

int main() {
    while(read()) {
        int cnt = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(graph[i][j] == 1) {dfs(i, j); cnt++;}
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
