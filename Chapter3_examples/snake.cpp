#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 1010
int snake[100][100];

int main(){
    int n;
    cin >> n;
    memset(snake, 0, sizeof(snake));
    int dir2[4] = {0,-1,0,1};
    int dir1[4] = {1,0,-1,0};
    int start1 = 0;
    int start2 = n - 1;
    int dir = 0;
    for(int i = 0; i < n * n; i++){
        //cout << start1 << 's' << start2 << endl;
        snake[start1][start2] = i+1;
        if(snake[start1 + dir1[dir % 4]][start2 + dir2[dir % 4]] == 0 && 
            start1 + dir1[dir % 4] < n && start2 + dir2[dir % 4] < n &&
            start1 + dir1[dir % 4] >= 0 && start2 + dir2[dir % 4] >= 0){
            start1 += dir1[dir%4];
            start2 += dir2[dir%4];
        } else {
            dir++;
            start1 += dir1[dir%4];
            start2 += dir2[dir%4];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << snake[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}