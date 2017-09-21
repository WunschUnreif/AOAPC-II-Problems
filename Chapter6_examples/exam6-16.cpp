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

int inDeg[26];
int outDeg[26];

int main() {
    int t;
    cin >> t;
    while(t--) {
        int num;
        cin >> num;
        memset(inDeg, 0, sizeof(inDeg));
        memset(outDeg, 0, sizeof(outDeg));
        for(int i = 0; i < num; i++) {
            string s;
            cin >> s;
            inDeg[s[s.length() - 1] - 'a']++;
            outDeg[s[0] - 'a']++;
        }
        int cnt = 0;
        for(int i = 0;i < 26;i++) {
            if(inDeg[i] != outDeg[i]) {
                cnt++;
            }
        }
        if(cnt <= 2) cout << "Ordering is possible." << endl;
        else cout << "The door cannot be opened." << endl;
    }
    return 0;
}
