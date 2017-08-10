#include <iostream>
#include <cstdio>
#include <cstring>

int gen[100010];

int sumOfDigits(int n){
    int ans = 0;
    while(n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    for(int i = 1; i <= 100000; i++) {
        if(gen[i + sumOfDigits(i)] == 0) gen[i + sumOfDigits(i)] = i;
    }
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",gen[n]);
    }
    return 0;
}

