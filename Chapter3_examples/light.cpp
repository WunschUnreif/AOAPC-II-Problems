#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 1010

int lightOn[maxn];

int main() {
    int n,k;
    scanf("%d%d", &n ,&k);
    memset(lightOn, 0, sizeof(lightOn));
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++){
            if(j % i == 0) {
                lightOn[j] = !lightOn[j];
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(lightOn[i]){
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}