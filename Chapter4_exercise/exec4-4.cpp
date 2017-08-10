#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
char a[13];

int main() {
    while(scanf("%s",a) != EOF){
        int cnt = 0;
        for(int i = 0; i < 6; i ++) {
            for(int j = 6; j < 12; j++) {
                if(a[i] == a[j]&&a[5-i] == a[17-j] && a[i] && a[j] && a[5-i] && a[17-j]) {
                    cnt++;a[i]=a[5-i]=a[j]=a[17-j]=0;
                }
            }
        }
        if(cnt==3)printf("TRUE\n");
        else printf("FALSE\n");
    }
    return 0;
}
