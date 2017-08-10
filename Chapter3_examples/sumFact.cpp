#include <iostream>
using namespace std;
int main() {
    const int mod = 1e6;
    int n;
    cin >> n;
    if(n > 25) n = 25;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        int fact =1;
        for(int j = i; j > 1; j--){
            fact = fact * j % mod;
        }
        sum = (sum + fact) % mod;
    }
    cout << sum << endl;
    return 0;
}