#include<iostream>
using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    double s = 0;
    for(int i = n; i <= m; i++){
        s += 1.0 / i / i;
    }
    printf("%.5f", s);
    return 0;
}