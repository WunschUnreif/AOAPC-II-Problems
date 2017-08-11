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
#include <cstdlib>
#include <ctime>
using namespace std;

void fillRandInt(vector<int> &v, int num) {
    v.clear();
    for(int i = 0; i < num; i++) 
        v.push_back(rand() % 100 + 1);
}

void printVector(const vector<int> &v) {
    for(int i : v) cout << i << endl;
}

int main() {
    srand(time(NULL));
    vector<int> v;
    fillRandInt(v, 10);
    sort(v.begin(), v.end());
    printVector(v);
    return 0;
}
