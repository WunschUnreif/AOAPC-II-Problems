#include <cstdio>

int main(){
    int c, q = 1;
    while((c = getchar()) != EOF) {
        if(c == '"'){
            if(q) {
                printf("%s","``");
                q = 0;
            } else {
                printf("%s","''");
                q = 1;
            }
        } else {
            printf("%c",c);
        }
    }
    return 0;
}