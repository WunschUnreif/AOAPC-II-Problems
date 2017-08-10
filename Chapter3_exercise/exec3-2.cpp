#include <iostream>
#include <cstdio>
#include <cstring>

double C = 12.01, H = 1.008, O = 16.00, N = 14.01;

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    while(t--) {
        double ans = 0;
        int count = 0;
        double massNow = 0;
        char s[100];
        scanf("%s",s);
        int i = 0;
        while(i != strlen(s)){
            char c = s[i];
            i++;
            if(c >= 'A' && c <= 'Z') {
                ans += massNow * (count ? count : 1);
                count = 0;
                switch(c) {
                    case 'C' :massNow = C;break;
                    case 'H' :massNow = H;break;
                    case 'N' :massNow = N;break;
                    case 'O' :massNow = O;break;
                }
            } else if(c >= '0' && c <= '9') {
                count = count * 10 + (c - '0');
            } else {
                break;
            }
        }
        ans += massNow * (count ? count : 1);
        printf("%.3f\n",ans);
    }
    return 0;
}
