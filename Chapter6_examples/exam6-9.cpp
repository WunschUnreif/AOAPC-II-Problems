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

struct pair_ {int a; int b;};

bool ok = true;

pair_ read() {
    int wl, dl, wr, dr;
    cin >> wl >> dl >> wr >> dr;
    if(wl == 0) {
        pair_ left = read();
        wl += left.a + left.b;
    }
    if(wr == 0) {
        pair_ right = read();
        wr += right.a + right.b;
    }
    if(wl * dl != wr * dr) {
        ok = false;
    }
    pair_ ret = {wl, wr};
    return ret;
}

void solve(){
    ok = true;
    read();
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    bool first = true;
    while(t--) {
        solve();
        if(t) cout << endl;
    }
    return 0;
}