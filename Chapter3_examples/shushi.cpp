#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int num = 0;
    char numSet[20], nums[100];
    scanf("%s",numSet);
    for(int i = 100; i <= 999; i++) {
        for(int j = 10; j <= 99; j++) {
            int x = i * (j % 10);
            int y = i * (j / 10);
            int ok = 1;
            sprintf(nums,"%d%d%d%d%d",i,j,x,y,i*j);
            //cout << nums << endl;
            for(int k = 0; k < strlen(nums); k++) {
                if(strchr(numSet,nums[k]) == NULL) ok = 0;
            }
            if(ok) {
                num ++;
                printf("<%d>\n",num);
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",i,j,x,y,i*j);
            }
        }
    }
    printf("The number of solutions is: %d\n", num);
    return 0;
}