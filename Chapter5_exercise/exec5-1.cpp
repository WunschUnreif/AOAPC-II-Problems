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

vector<int> widthOfCol;

void print(string word, int width, char fill) {
    cout << word;
    width -= word.length();
    while(width--) cout << fill;
}

void solve() {
    string lineStr;
    vector<vector<string>> programBuffer;
    while(getline(cin, lineStr)) {
        stringstream ss(lineStr);
        int wordCount = 0;
        string word;
        vector<string> currLine;
        while(ss >> word) {
            wordCount++;
            currLine.push_back(word);
            if(wordCount > (int)widthOfCol.size()) widthOfCol.push_back(word.length());
            else if(widthOfCol[wordCount - 1] < (int)word.length()) widthOfCol[wordCount - 1] = word.length();
        }
        programBuffer.push_back(currLine);
    }
    for(int i = 0; i < (int)programBuffer.size(); i++) {
        for(int j = 0; j < (int)programBuffer[i].size(); j++) {
            if(j == (int)(programBuffer[i].size() - 1)) {cout << programBuffer[i][j];break;}
            print(programBuffer[i][j], widthOfCol[j] + 1, ' ');
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
