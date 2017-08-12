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

void solve() {
    int pointNumber;
    cin >> pointNumber;
    vector<vector<int>*> countOnY;
    set<double> averageCoordinate;
    map<int, vector<int>*> vecCache;
    while(pointNumber--) {
        int x, y;
        cin >> x >> y;
        if(vecCache.count(y)) vecCache[y]->push_back(x);
        else {
            vecCache[y] = new vector<int>();
            countOnY.push_back(vecCache[y]);
            vecCache[y]->push_back(x);
            // for(auto i : *vecCache[y]) cout << i << endl;
        }
    }
    //cout << 'a' << endl;
    for(auto v : countOnY) {
        int sum = 0;
        for(auto i : *v) sum += i;
        averageCoordinate.insert((double)sum / v->size());
        // cout << (double)sum / v->size() << endl;
    }
    if(averageCoordinate.size() != 1) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    int kase;
    cin >> kase;
    while(kase--) solve();
    return 0;
}
