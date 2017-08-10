#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[10000];

int main() {
    int n,m,count = 0;
    while((cin >> n >> m) && n) {
        count++;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        cout << "CASE# " << count << ":" << endl;
        for(int i = 0; i < m; i++) {
            int ask, p = 0;
            cin >> ask;
            for(p = 0; p < n; p++) {
                if(a[p] == ask) break;
            }
            if(p != n) cout << ask << " found at " << p + 1 << endl;
            else cout << ask << " not found" << endl;
        }
    }
    return 0;
}
