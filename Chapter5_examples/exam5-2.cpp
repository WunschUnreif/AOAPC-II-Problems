#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

using namespace std;

vector<int> pile[30];
int n;

void findBlock(int num, int &p, int &h) {
    for(p = 0; p < n; p++) {
        for(h = 0; h < pile[p].size(); h++) {
            if(pile[p][h] == num) return;
        }
    }
}

void clearPile(int p, int h) {
    for(int i = h + 1; i < pile[p].size(); i++) {
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h + 1);
}

void moveOnto(int p, int h, int p2) {
    for(int i = h; i < pile[p].size(); i++) {
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}

void print() {
    for(int i = 0; i < n; i++) {
        printf("%d:", i);
        for(int j = 0; j < pile[i].size(); j++) {
            printf(" %d", pile[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a,b;
    string s1,s2;
    cin >> n; 
    for(int i = 0; i < n; i++) pile[i].push_back(i);
    while(cin >> s1 >> a >> s2 >> b) {
        int pa,ha, pb,hb;
        findBlock(a, pa, ha);
        findBlock(b, pb, hb);
        if(pa == pb) continue;
        if(s2 == "onto") clearPile(pb,hb);
        if(s1 == "move") clearPile(pa,ha);
        moveOnto(pa, ha, pb);
    }
    print();
    return 0;
}
