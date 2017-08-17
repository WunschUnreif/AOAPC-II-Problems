#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int primes[110];
int cnt[110];

void solve(int n, int m) {
    memset(cnt, 0, sizeof cnt);
    int maxPrime = 2;
    while(n >= 2) {
        for(int i = 2; i <= n; i++) {
            if(n % i == 0 && primes[i]){
                //printf("%d has %d \n", n, i);
                int tmp = n;
                while(!(tmp%i)){cnt[i]++; tmp /= i;}
                if(i > maxPrime) maxPrime = i;
            }
        }
        n--;
    }
    printf("%3d! =", m);
    int k = 0;
    for(int i = 0; i <= maxPrime; i++) {
        if(primes[i]) {
            if(k && k % 15 == 0) printf("\n      ");
            k++;
            printf("%3d", cnt[i]);
        }
    }
    printf("\n");
}

int main() {
    for(int i = 2; i < 100; i++) {
        bool ok = true;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) {ok = false; break;}
        }
        primes[i] = ok;
    }
    int n;
    while(~scanf("%d", &n) && n) solve(n, n);
    return 0;
}
