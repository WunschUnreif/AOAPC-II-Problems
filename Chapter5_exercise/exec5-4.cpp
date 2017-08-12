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

string getPair(int a, int b) {
    string s1 = to_string(a) + "#" + to_string(b);
    // cout << s1 << endl;
    return s1;
}

map<string, int> IDcache;
vector<int> exchangeCount;

int getID(string pair) {
    if(IDcache.count(pair)) return IDcache[pair];
    exchangeCount.push_back(0);
    return IDcache[pair] = exchangeCount.size() - 1;
}

void solve(int wishNumber) {
    if(wishNumber % 2 != 0) {
        for(int i = 0; i < wishNumber; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
        }
        printf("NO\n");
        return;
    }
    IDcache.clear();
    exchangeCount.clear();
    for(int i = 0; i < wishNumber; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a < b) exchangeCount[getID(getPair(a, b))]++;
        else exchangeCount[getID(getPair(b, a))]--;
    }
    bool ok = true;
    for(int i = 0; i < (int)exchangeCount.size(); i++) {
        if(exchangeCount[i] != 0) {ok = false; break;}
    }
    if(ok) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int wishNumber;
    while(cin >> wishNumber && wishNumber) solve(wishNumber);
    return 0;
}
