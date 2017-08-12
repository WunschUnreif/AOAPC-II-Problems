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

struct task{
    int id;
    int priority;
    task(int id, int priority):id(id), priority(priority) {}
};

void solve() {
    int n, pos;
    cin >> n >> pos;
    queue<task*> printQueue;
    int priorities[10];
    for(int i = 1; i <= 9; i++) priorities[i] = 0;
    for(int i = 0; i < n; i++) {
        int prio;
        cin >> prio;
        printQueue.push(new task(i, prio));
        priorities[prio]++;
    }
    int time = 0;
    task *top = printQueue.front();
    while(true) {
        printQueue.pop();
        bool print = true;
        for(int i = top->priority + 1; i < 10; i++) {
            if(priorities[i] > 0){print = false;break;}
        }
        if(print) {time++;priorities[top->priority]--;if(top->id == pos) break;}
        else{printQueue.push(top);}
        top = printQueue.front();
    }
    cout << time << endl;
}

int main() {
    int kase;
    cin >> kase;
    while(kase--) solve();
    return 0;
}
