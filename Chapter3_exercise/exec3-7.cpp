#include <iostream>
#include <cstdio>
#include <cstring>

int main() {
    int t;
    scanf("%d", &t);
    bool first = true;
    while(t--) {
        int m, n;
        scanf("%d%d", &m, &n);
        char dnas[m][n + 1];
        int count[n][26];
        memset(count, 0, sizeof(count));
        for(int i = 0; i < m; i++) {
            scanf("%s", dnas[i]);
            for(int j = 0; j < n; j++) {
                count[j][dnas[i][j] - 'A'] ++;
            }
        }
        char answer[n + 1];
        int max = 0;
        for(int i = 0; i < n; i++) {
            max = 0;
            for(int j = 0; j < 26; j++) {
                if(count[i][j] > count[i][max]) max = j;
            }
            answer[n] = '\0';
            answer[i] = 'A' + max;
        }
        printf("%s\n",answer);
        int hamming = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(dnas[i][j] != answer[j]) hamming ++;
            }
        }
        printf("%d\n",hamming);
        first = false;
    }
    return 0;
}
