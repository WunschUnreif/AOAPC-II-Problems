#include<iostream>
#include<cmath>
using namespace std;
int main() {
    long long n;
    while(~scanf("%lld", &n) && n) {
        if((long long)sqrt(n) * (long long)sqrt(n) == n) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
