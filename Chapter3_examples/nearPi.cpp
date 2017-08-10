#include <iostream>
using namespace std;

int main(){
    double piDiv4 = 0.0;
    double i = 1,n = 1;
    while(true){
        piDiv4 += int(n)%2==0? (-1.0/i) : 1.0/i;
        if(1.0 / i < 1e-8) break;
        i += 2;
        n ++;
    }
    piDiv4 *= 4;
    printf("%.6f %d", piDiv4, n);
    return 0;
}
