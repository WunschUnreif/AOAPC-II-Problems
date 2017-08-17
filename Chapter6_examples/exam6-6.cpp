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

inline int leftChild(int n) {return 2 * n;}
inline int rightChild(int n) {return 2 * n + 1;}

bool touchGround(int id, int n) {
    if(id >= (1 << (n-1))) return true;
    return false;
}

void solve() {
    int d, ball;
    cin >> d >> ball;
    int currPos = 1;
    while(!touchGround(currPos, d)) {
        if(ball % 2 == 0) {
            currPos = rightChild(currPos);
            ball /= 2;
        } else {
            currPos = leftChild(currPos);
            ball = (ball + 1) / 2;
        }
    }
    cout << currPos << endl;
}

int main() {
    int kase;
    cin >> kase;
    while(kase--) solve();
    return 0;
}
