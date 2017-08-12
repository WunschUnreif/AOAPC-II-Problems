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

void solve(int num) {
    queue<int> q;
    for(int i = 0; i < num; i++) q.push(i + 1);
    cout << "Discarded cards:";
    while(q.size() >= 2) {
        int removed = q.front();q.pop();
        int up = q.front(); q.pop();
        q.push(up);
        if(q.size() == 1) cout << ' ' << removed;
        else cout <<' ' << removed << ",";
    }
    cout << endl << "Remaining card: " << q.front() << endl;
}

int main() {
    int n;
    while(cin >> n && n) solve(n);
    return 0;
}
