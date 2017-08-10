#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int a[10000010];
int b[10000010];
int used = 0;

void getTable() {
    int i = 0;
    bool flag = false;
    while(used < 10000000){
        flag = !flag;
        i += 1;
        if(!flag){
            for(int j = 0; j < i && used < 10000000; j++){
                a[used] = j + 1;
                b[used++] = i - j;
            }
        } else {
            for(int j = i; j > 0 && used < 10000000; j--){
                a[used] = j;
                b[used++] = i - j + 1;
            }
        }
    }
}

int main() {
    getTable();
    int term;
    while(scanf("%d", &term) != EOF){
        printf("TERM %d IS %d/%d\n",term, a[term-1], b[term-1]);
    }
    return 0;
}
