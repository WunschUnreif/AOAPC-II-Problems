#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

const int maxn = 10010;

int n, inOrder[maxn], postOrder[maxn], lchild[maxn], rchild[maxn];

bool readList(int *a) {
    string line;
    if(getline(cin, line)) {
        stringstream ss(line);
        n = 0;
        int w;
        while(ss >> w)a[n++] = w;
        return true;
    }
    return false;
}

int buildTree(int L1, int R1, int L2, int R2) {
    if(L1 > R1) return 0;
    int root = postOrder[R2];
    int p = L1;
    while(inOrder[p] != root) p++;
    int cnt = p - L1;
    lchild[root] = buildTree(L1, p - 1, L2, L2 + cnt - 1);
    rchild[root] = buildTree(p + 1, R1, L2 + cnt, R2 - 1);
    return root;
}

int best, bestSum;

void dfs(int root, int sum) {
    sum += root;
    if(!lchild[root] && !rchild[root]) {
        if(sum < bestSum || (sum == bestSum && root < best)) {
            bestSum = sum;
            best = root;
        }
    } else {
        if(lchild[root]) dfs(lchild[root], sum);
        if(rchild[root]) dfs(rchild[root], sum);
    }
}

int main() {
    while(readList(inOrder)) {
        readList(postOrder);
        bestSum = 0x3f3f3f3f;
        buildTree(0, n - 1, 0, n - 1);
        dfs(postOrder[n - 1], 0);
        cout << best << endl;
    }
    return 0;
}
