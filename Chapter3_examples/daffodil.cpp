#include <iostream>
using namespace std;
int main() {
    for(int a = 1; a <= 9; a++) {
        for(int b = 0; b <= 9; b++) {
            for(int c = 0; c <= 9; c++) {
                int n = 100 * a + 10 * b + c;
                if(n == a*a*a + b*b*b + c*c*c)
                    printf("%d\n", n);
            }
        }
    }
    return 0;
}