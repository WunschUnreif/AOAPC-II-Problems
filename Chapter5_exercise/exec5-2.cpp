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

bool isAllZero(const vector<int>& ducci) {
    for(int i = 0; i < (int)ducci.size(); i++) {
        if(ducci[i] != 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> DucciSecquence;
    set<vector<int>> seqs;
    for(int i = 0; i < n; i++) {int num; cin >> num; DucciSecquence.push_back(num);}
    seqs.insert(DucciSecquence);
    while(!isAllZero(DucciSecquence)) {
        vector<int> newSeq;
        for(int i = 0; i < n; i++) {
            newSeq.push_back(abs(DucciSecquence[i] - DucciSecquence[(i+1) % n]));
        }
        if(seqs.count(newSeq)) {cout << "LOOP" << endl; return;}
        seqs.insert(newSeq);
        DucciSecquence = newSeq;
    }
    cout << "ZERO" << endl;
}

int main() {
    int kase;
    cin >> kase;
    while(kase--) solve();
    return 0;
}
