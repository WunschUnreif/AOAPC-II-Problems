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

void print(const string& s, int n, char fill) {
    cout << s;
    n -= s.length();
    for(int i = 0; i < n; i++) cout << fill;
}

void solve(int fileNumber) {
    vector<string> nameList;
    int maxLength = 0;
    for(int i = 0; i < fileNumber; i++) {
        string name;
        cin >> name;
        nameList.push_back(name);
        if(name.length() > maxLength) maxLength = name.length();
    }
    int numInLine = (60 - maxLength) / (maxLength + 2) + 1;
    int lines = (fileNumber - 1) / numInLine + 1;
    sort(nameList.begin(), nameList.end());
    print("", 60, '-'); cout << endl;
    // if(fileNumber == 1){cout << nameList[0] << endl;return;}
    for(int r = 0; r < lines; r++) {
        for(int c = 0; c < numInLine; c++) {
            if(r + c * lines < fileNumber) print(nameList[r + c * lines], c == numInLine - 1 ? maxLength : maxLength + 2, ' ');
        }
        cout << endl;
    }
    
}

int main() {
    int num;
    while(cin >> num) solve(num);
    return 0;
}
