#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    char s[2*n];
    for(int i = 0; i < 2*n-1; i++) s[i] = '*';
    s[2 * n - 1] ='\0';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++) {
            if(j == 2 * n - 2 - j) break;
            s[j] = s[2 * n - 2 - j] = ' ';
        }
        printf("%s\n", s);
    }
    return 0;
}