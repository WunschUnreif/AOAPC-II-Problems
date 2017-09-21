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

int graph[32][32];
int cnt;
char s[1400];

void draw(char *s, int &pos, int x, int y, int w) {
    char cmd = s[pos++];
    if(cmd == 'p') {
        draw(s, pos, x, y + w / 2, w / 2);
        draw(s, pos, x, y, w / 2);
        draw(s, pos, x + w / 2, y, w / 2);
        draw(s, pos, x + w / 2, y + w / 2, w / 2);        
    } else if(cmd == 'f') {
        for(int i = x; i < x + w; i++) {
            for(int j = y; j < y + w; j++) {
                if(graph[i][j] != 1) {graph[i][j] = 1; cnt++;}
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i < 2; i++) {
            cin >> s;
            int p = 0;
            draw(s, p, 0, 0, 32);
        }
        cout << "There are " << cnt << " black pixels." << endl;
        cnt = 0;
    }
    return 0;
}