#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;

int main() {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    set<ll> s;
    pq.push(1);
    s.insert(1);
    for(int i = 1; ; i++) {
        ll x = pq.top(); pq.pop();
        if(i == 1500) {cout << "The 1500'th ugly number is " << x << '.' << endl;break;}
        ll x2 = x * 2;if(!s.count(x2)) {s.insert(x2);pq.push(x2);}
        x2 = x * 3;if(!s.count(x2)) {s.insert(x2);pq.push(x2);}
        x2 = x * 5;if(!s.count(x2)) {s.insert(x2);pq.push(x2);}
    }
    return 0;
}
