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

int mleft[100010];
int mright[100010];
bool rev = false;
int cnt = 0;

void link(int l, int r) {
    mleft[r] = l;
    mright[l] = r;
}

void clear(int n) {
    for(int i = 0; i <= n; i++) {
        link(i, i+1);
    }
    rev = false;
    cnt++;
}

void print(int n) {
    int ptr = rev ? n + 1 : 0;
    while(true){
        ptr = rev ? mleft[ptr] : mright[ptr];
        if(ptr == (rev ? 0 : n + 1))break;
        cout << ptr << ' ';
    }
}

void solve(int n, int m) {
    clear(n);
    while(m--) {
        int cmd;
        cin >> cmd;
        if(cmd == 4) rev = !rev;
        else{
            int x, y;
            cin >> x >> y;
            if(cmd == 1) {
                mright[mleft[x]] = mright[x];
                mleft[mright[x]] = mleft[x];
                if(!rev) {
                    mright[mleft[y]] = x;
                    mleft[x] = mleft[y];
                    mright[x] = y;
                    mleft[y] = x;
                } else {
                    mleft[mright[y]] = x;
                    mright[x] = mright[y];
                    mleft[x] = y;
                    mright[y] = x;
                }
            } else if(cmd == 2) {
                mright[mleft[x]] = mright[x];
                mleft[mright[x]] = mleft[x];
                if(rev) {
                    mright[mleft[y]] = x;
                    mleft[x] = mleft[y];
                    mright[x] = y;
                    mleft[y] = x;
                } else {
                    mleft[mright[y]] = x;
                    mright[x] = mright[y];
                    mleft[x] = y;
                    mright[y] = x;
                }
            } else {
                if(mleft[x] == y) {
                    mleft[x] = mleft[y];
                    mright[y] = mright[x];
                    mright[mleft[y]] = x;
                    mleft[mright[x]] = y;
                    mleft[y] = x;
                    mright[x] = y;
                } else if(mright[x] == y) {
                    mleft[y] = mleft[x];
                    mright[x] = mright[y];
                    mright[mleft[x]] = y;
                    mleft[mright[y]] = x;
                    mright[y] = x;
                    mleft[x] = y;
                } else {
                    mleft[mright[y]] = x;
                    mright[mleft[y]] = x;
                    mleft[mright[x]] = y;
                    mright[mleft[x]] = y;
                    int tl = mleft[x], tr = mright[x];
                    mleft[x] = mleft[y]; mright[x] = mright[y];
                    mleft[y] = tl; mright[y] = tr;
                }
            }
        }
        //print(n);
    }
    int ptr = rev ? n + 1 : 0;
    long long sum = 0;
    bool add = true;
    while(ptr != (rev ? 0 : n + 1)) {
        ptr = rev ? mleft[ptr] : mright[ptr];
        if(ptr == (rev ? 0 : n + 1)) break;
        if(add){sum += ptr;}
        add = !add;
    }
    cout << "Case " << cnt << ": " << sum << endl;
}

int main() {
    int n,m;
    while(cin >> n >> m)solve(n,m);
    return 0;
}
