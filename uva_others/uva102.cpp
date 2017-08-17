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

int main() {
    ll a[9];
    while(cin >> a[0]) {
        for(int i = 1; i < 9; i++) {
            cin >> a[i];
        }
        int step = a[1] + a[2] + a[3] + a[4] + a[6] + a[8];
        string ans = "BCG";

        int s = a[1] + a[2] + a[3] + a[5] + a[6] + a[7];
        if(s < step) {step = s; ans = "BGC";}

        s = a[1] + a[0] + a[4] + a[5] + a[6] + a[8];
        if(s < step) {step = s; ans = "CBG";}

        s = a[1] + a[0] + a[3] + a[5] + a[8] + a[7];
        if(s < step) {step = s; ans = "CGB";}

        s = a[0] + a[2] + a[4] + a[5] + a[6] + a[7];
        if(s < step) {step = s; ans = "GBC";}

        s = a[0] + a[2] + a[3] + a[4] + a[8] + a[7];
        if(s < step) {step = s; ans = "GCB";}

        cout << ans << ' ' << step << endl;
    }
    return 0;
}
