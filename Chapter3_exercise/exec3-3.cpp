#include <iostream>
#include <cstdio>
#include <cstring>

int count[10];

void digit(int n) {
    while(n) {
        count[n % 10] ++;
        n /= 10;
    }
}

void solve(int n) {
    memset(count,0,sizeof(count));
    for(int i = 1; i <= n; i++) {
        digit(i);
    }
    printf("%d",count[0]);
    for(int i = 1; i < 10; i++) {
        printf(" %d", count[i]);
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        solve(n);
    }
}
