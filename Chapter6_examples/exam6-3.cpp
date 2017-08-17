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

struct Matrix {
    int r;
    int c;
    Matrix(int r, int c):r(r), c(c) {}
    int operator * (const Matrix & m) {
        if(c == m.r) return r * c * m.c;
        else return 0;
    }
    Matrix mul(const Matrix &m) {
        return Matrix(r, m.c);
    }
};

map<char,Matrix*> matrixDict;

void readMatrix() {
    int n;
    cin >> n;
    while(n--) {
        char c; int a,b;
        cin >> c >> a >> b;
        matrixDict[c] = new Matrix(a,b);
    }
}

void cal() {
    string s;
    while(cin >> s) {
        stringstream ss(s);
        if(s.length() == 1) cout << 0 << endl;
        else {
            int sum = 0;
            stack<Matrix> expr;
            char c;
            int ans = 1;
            bool ok = true;
            while(ss >> c) {
                //cout << c;
                if(ans == 0) {ok = false; break;}
                if(c == '(') continue;
                if(c == ')') {
                    Matrix a = expr.top();expr.pop();
                    Matrix b = expr.top();expr.pop();
                    //cout << a.c << ' ' << b.r << endl;
                    ans = (b * a);
                    sum += ans;
                    //cout << a * b << endl;
                    if(ans) expr.push(b.mul(a));
                } else {
                    expr.push(*matrixDict[c]);
                }
            }
            if(ans && ok) cout << sum << endl;
            else cout << "error" << endl;
        }
    }
}

int main() {
    readMatrix();
    cal();
    return 0;
}
