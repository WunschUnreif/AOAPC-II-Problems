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

char text[100010];
int next[100010];
int used = 1;
int cursor = 0;
int last = 0;
void init() {
    memset(text, 0, sizeof text);
    memset(next, 0, sizeof next);
    used = 1;
    cursor = 0;
    last = 0;
}

void addAfter(char c) {
    text[used] = c;
    next[used] = next[cursor];
    next[cursor] = used;
    if(cursor == last) last = used;
    cursor = used++;
}

bool run() {
    init();
    char c;
    while((c = getchar())) {
        if(c == EOF) return false;
        if(c == '\n' || c == '\r') break;
        if(c == '[') {
            cursor = 0;
        } else if(c == ']') {
            cursor = last;
        } else {
            addAfter(c);
        }
    }
    for(int i = next[0]; i != 0; i = next[i]) {
        putchar(text[i]);
    }
    putchar('\n');
    return true;
}

int main() {
    while(run());
    return 0;
}
