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
map<int,int> tree;
bool readTree(int pos) {
    int weight;
    if(!(cin >> weight)) return false;
    if(weight == -1) return false;
    if(!tree.count(pos)) tree[pos] = weight;
    else tree[pos] += weight;
    readTree(pos - 1);
    readTree(pos + 1);
    return true;
}
struct pair_ {
    int pos;
    int weight;
    bool operator < (pair_ & p) {
        return pos < p.pos;
    }
};

int main() {
    int kase = 0;
    while(readTree(0)) {
        kase++;
        pair_ t[100010];
        int i = 0;
        for(auto it = tree.begin(); it != tree.end(); it++, i++) {
            t[i].pos = it->first;
            t[i].weight = it->second;
        }
        sort(t, t + i);
        cout << "Case " << kase << ':' << endl;
        for(int c = 0; c < i; c++) {
            cout << t[c].weight;
            if(c != i - 1) cout << ' ';
        }
        cout << endl << endl;
        tree.clear();
    }
    return 0;
}