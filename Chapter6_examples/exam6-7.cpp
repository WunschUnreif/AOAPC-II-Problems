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

bool root = false;

struct Node {
    int value;
    string pos;
    bool operator < (const Node &n) {
        return pos.length() < n.pos.length() ||
            (pos.length() == n.pos.length() && pos < n.pos);
    }
    bool isroot = false;
    bool father = false;
    Node(int value = 0, string pos = ""):value(value), pos(pos) {if(pos.length()==0) {isroot=true;root = true;}}
};

Node *the_root;
vector<Node> tree;

bool stop = false;
bool notFull = false;

void getFather(Node &n) {
    if(n.isroot) return;
    if(n.pos.length()==1){n.father=true;return;}
    string fat = n.pos.substr(0, n.pos.length()-1);
    for(auto &n2 : tree) {
        if(n2.pos == fat) {
            n.father = true;
            break;
        }
    }
}

bool firstAssign(string s) {
    for(auto n : tree) {
        if(s == n.pos && s.length())return false;
    }
    return true;
}

bool readNode() {
    char s[300];
    if(scanf("%s", s)==EOF){stop = true; return false;}
    if(!strcmp(s, "()")) return false;
    char *c = s+1;
    int val = 0;
    while(*c != ',') {
        val = val * 10;
        val += *c - '0';
        c++;
    }
    c++;
    char pos[280];int used = 0;
    while(*c != ')') {
        pos[used++] = *c;
        c++;
    }
    pos[used] = '\0';
    if(!firstAssign(string(pos))) {notFull = true;}
    tree.push_back(Node(val, string(pos)));
    if(root){root = false; the_root = &tree[tree.size()-1];}
    return true;
}

void pt() {
    for(auto n : tree) {
        printf("%d %d\n", n.value, n.father);
    }
}

bool solve() {
    notFull = false;
    tree.clear();
    while(readNode());
    if(notFull) {
        printf("not complete\n");
        return true;
    }
    if(stop) return false;
    sort(tree.begin(), tree.end());
    int rc = 0;
    for(auto it = tree.begin(); it != tree.end(); it++) {
        getFather(*it);
        if(it->isroot)rc++;
    }
    bool ok = true;
    if(rc <= 0) ok = false;
    if(ok) {
        for(auto n : tree) {
            if(!(n.isroot || n.father)) {ok = false; break;}
        }
    }
    if(ok) {
        bool first = true;
        for(auto n : tree) {
            if(!first)putchar(' ');
            printf("%d", n.value);
            first = false;
        }
        printf("\n");
    } else {
        printf("not complete\n");
    }
    return true;
}

int main() {
    while(solve());
    return 0;
}
