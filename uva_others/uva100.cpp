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

#define ll long long

int count(ll n) {
    int ans = 0;
    while(n != 1) {
        if(n % 2 == 0) n /= 2;
        else n = 3 * n + 1;
        ans++;
    }
    return ans;
}

int main() {
    unsigned nn, mm;
    while(cin >> nn >> mm) {
        unsigned n = min(nn,mm);
        unsigned m = max(nn,mm);
        int max = 0;
        for(ll i = n; i <= m; i++) {
            int step = count(i);
            if(step > max) {
                max = step;
            }
        }
        printf("%d %d %d\n", nn, mm, max+1);
    }
    return 0;
}
