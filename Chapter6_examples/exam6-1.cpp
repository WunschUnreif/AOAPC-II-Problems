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

struct command {
    void (*func)(char, char);
    bool lock = false;
    char var = 0;
    char cst = 0;
    int time;
    command(void (*func)(char,char), char var = 0, char cst = 0, int time = 0):func(func), var(var), cst(cst), time(time){}
};

queue<int> waiting;
deque<int> running;
queue<command> prog[12];
int costTime[5];
bool lock = false;
int varibles[26];
int progTime[12];
int quantum = 0;
deque<int> ready;

void cls() {
    waiting = queue<int>();
    running = deque<int>();
    for(int i = 0; i < 12; i++) {
        prog[i] = queue<command>();
    }
    for(int i = 0; i < 26; i++) varibles[i] = 0;
    for(int i = 0; i < 12; i++) progTime[i] = 0;
}

void assign(char var, char cst) {
    varibles[var - 'a'] = cst;
    //cout << var << cst << endl;
    //cout << "assign " << var << " = " << int(cst) << endl;
}

void print(char var, char id) {
    //cout << "print ";
    cout << int(id) + 1 << ": " << varibles[var-'a'] << endl;
}

void lockV(char var, char id) {
    if(lock == false) {
         lock = true;
         prog[(int)id].pop();
         //cout << "lock by " << int(id) + 1 << endl;
    }
    else {
        waiting.push(running.front());
        progTime[running.front()] = 0;
        running.pop_front();
        //cout << "lock failed by " << int(id) + 1 << endl;
    }
}

void unlock(char var, char id) {
    lock = false;
    //cout << "unlock by " << int(id) + 1 << endl;
    if(waiting.size() > 0) {
        ready.push_front(waiting.front());
        waiting.pop();
    }
}

void end(char var, char id) {running.pop_front();}

void readProg(int id){
    string cmd;
    while(cin >> cmd && cmd != "end") {
        if(cmd == "print") {
            char var;
            cin >> var;
            prog[id].push(command(print,var,id,costTime[1]));
        } else if(cmd == "lock") {
            prog[id].push(command(lockV, 0, id, costTime[2]));
            prog[id].back().lock = true;
        } else if(cmd == "unlock") {
            prog[id].push(command(unlock, 0, id, costTime[3]));
        } else {
            char eq; int constant;
            cin >> eq >> constant;
            prog[id].push(command(assign, cmd[0], constant, costTime[0]));
        }
        //cout << "\t" << cmd << ' ' << id << endl;
    }
    prog[id].push(command(end, 0, id, costTime[4]));
    //cout << "prog end" << id << endl;
}

void runProg() {
    while(running.size() || waiting.size() || ready.size()) {
        if(running.size() == 0 && ready.size()) {
            running.push_front(ready.front()) ; ready.pop_front();
        } else if(running.size() == 0 && waiting.size() != 0) {
            running.push_front(waiting.front());
            waiting.pop();
        }
        int currid = running.front();
        if(progTime[currid] >= quantum) {
            running.push_back(running.front());
            running.pop_front();
            progTime[currid] = 0;
            if(ready.size()) {running.push_front(ready.front()) ; ready.pop_front();}
        }
        currid = running.front();
        //cout << currid + 1 << endl;
        command currcmd = prog[currid].front();
        progTime[currid] += currcmd.time;
        if(!currcmd.lock) {
            prog[currid].pop();
            //cout << "l ";
        }
        currcmd.func(currcmd.var, currcmd.cst);
    }
}

int main() {
    int kase;
    cin >> kase;
    while(kase--) {
        cls();
        int n;
        cin >> n;
        for(int i = 0; i < 5; i++) {
            cin >> costTime[i];
        }
        cin >> quantum;
        for(int i = 0; i < n; i++) {
            readProg(i);
            running.push_back(i);
        }
        runProg();
        cout << endl;
    }
    return 0;
}
