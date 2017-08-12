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

set<string> dict;

int main() {
    string wd;
    while(cin >> wd)dict.insert(wd);
    for(auto it = dict.begin(); it != dict.end(); it++) {
        string currWord = *it;
        if(currWord.length() < 2) continue;
        for(int i = 1; i < (int)currWord.length(); i++) {
            if(dict.count(currWord.substr(0, i)) && dict.count(currWord.substr(i, currWord.length())))
                {cout << currWord << endl;break;}
        }
    }
    return 0;
}
