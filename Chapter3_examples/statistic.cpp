#include <iostream>
#include <cstdio>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int n = 0, mmin = INF, mmax = -INF, sum = 0;
    int x;
    while(scanf("%d", &x) == 1){
        n ++;
        sum += x;
        if(x > mmax) mmax = x;
        if(x < mmin) mmin = x;
    }
    printf("%d %d %.3f",mmin, mmax, (double)sum / n);
    return 0;
}