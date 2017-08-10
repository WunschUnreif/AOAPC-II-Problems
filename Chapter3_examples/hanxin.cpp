#include <iostream>
using namespace std;
int main() {
    int a,b,c,n =0;
    while(scanf("%d%d%d", &a, &b, &c) == 3) {
        n++;
        int i;
        for(i = 10; i <= 100; i++){
            if(i % 3 == a && i % 5 == b && i % 7 == c){
                printf("Case %d: %d\n", n, i);
                break;
            }
        }
        if(i == 101) printf("Case %d: No answer.\n", n);
    }
    return 0;
}