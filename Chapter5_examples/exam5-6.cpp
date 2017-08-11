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

map<int, int> getGroup;

bool getMap() {
    int n; cin >> n;
    if(!n) return false;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        while(a--) {
            int b; cin >> b;
            getGroup[b] = i;
        }
    }
    return true;
}

void simulate(int kase) {
    queue<int> groupQueue;
    queue<int> memberQueue[1005];
    cout << "Scenario #" << kase << endl;
    string cmd;
    while(cin >> cmd) {
        if(cmd[0] == 'S') {cout << endl;return;}

        if(cmd[0] == 'E') {
            int member; cin >> member;
            int groupNumber = getGroup[member];
            if(memberQueue[groupNumber].empty()) groupQueue.push(groupNumber);
            memberQueue[groupNumber].push(member);
        }

        if(cmd[0] == 'D') {
            int groupNumber = groupQueue.front();
            int member = memberQueue[groupNumber].front();memberQueue[groupNumber].pop();
            if(memberQueue[groupNumber].empty()) groupQueue.pop();
            cout << member << endl;
        }
    }
}

int main() {
    int n = 0;
    while(getMap()) simulate(++n);
    return 0;
}
