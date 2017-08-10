#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

set<string> dict;

int main() {
    string s, currWord;
    while(cin >> s) {
        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])) s[i] = tolower(s[i]);
            else s[i] = ' ';
        }
        stringstream ss(s);
        while(ss >> currWord) dict.insert(currWord);
    }
    for(auto i = dict.begin(); i != dict.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}
