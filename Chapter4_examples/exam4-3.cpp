#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int a[100], b[100], n, k, m;

int goA(int A) {
    int tk = k;
    while(tk--) do{A = (A + n) % n + 1;}while(a[A] != 0);
    return A;
}
int goB(int B) {
    int tm = m;
    while(tm--) do{ B = (B + n) % n + 1;}while(b[B] != 0);
    return B;
}

int main() {
    while(scanf("%d%d%d", &n, &k, &m) == 3) {
        if(n == 0) break;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int A = 0, B = 0;
        int left = n;
        bool first = true;
        while(left){
            A = goA(A); B = goB(B);
            if(!first) printf(",");
            if(A==(n + 1 - B)) {
                a[A] = b[n + 1 - A] = 1;
                printf("%3d",A); left--;
            } else {
                a[A] = b[n + 1 - A] = a[n+1-B] = b[B] = 1;
                printf("%3d%3d",A,n + 1 - B);left -= 2;
            }
            first = false;
        }
        printf("\n");
    }
    return 0;
}
