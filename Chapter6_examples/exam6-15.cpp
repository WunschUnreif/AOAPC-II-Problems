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

vector<int> next_[110];
int prev_[110];
int been[110];
int n = 0;

bool read() {
    int n, m;
    cin >> n >> m;
    if(!n) return false;
    ::n = n;
    for(int i = 1; i <= n; i++) {
        next_[i].clear();
        prev_[i] = 0;
        been[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        next_[a].push_back(b);
        prev_[b]++;
    }
    return true;
}

void topo() {
    int cnt = n;
    while(cnt) {
        for(int i = 1; i <= n; i++) {
            if(!been[i] && prev_[i] == 0) {
                been[i] = 1;
                cout << i;
                if(cnt > 1) cout << ' ';
                for(auto n2 : next_[i]) prev_[n2]--;
                cnt--;
                break;
            }
        }
    }
}

int main() {
    while(read()) {
        topo();
        cout << endl;
    }
    return 0;
}
