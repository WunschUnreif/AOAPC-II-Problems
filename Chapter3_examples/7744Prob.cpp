#include <iostream>
using namespace std;

int main() {
    for(int x = 32; ; x++) {
        int n = x * x;
        //cout << n << endl;
        if(n >= 10000) break;
        int hi = n / 100;
        int lo = n % 100;
        if(hi / 10 == hi % 10 && lo / 10 == lo % 10) {
            cout << n << endl;
        }
    }
    return 0;
}