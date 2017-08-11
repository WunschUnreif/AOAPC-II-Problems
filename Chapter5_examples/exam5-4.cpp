#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

map<string, int> cnt;
vector<string> words;

string standardnize(const string& word) {
    string ans = word;
    for(int i = 0; i < ans.length(); i++) {
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s;
    while(cin >> s) {
        if(s[0] == '#') break;
        words.push_back(s);
        string r = standardnize(s);
        if(!cnt.count(r)) cnt[r] = 0;
        cnt[r]++;
    }
    vector<string> ans;
    for(int i = 0; i < words.size(); i++) {
        if(cnt[standardnize(words[i])] == 1) ans.push_back(words[i]);
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
