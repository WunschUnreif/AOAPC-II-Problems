#include <iostream>
#include <ctime>
using namespace std;
int main() {
    int n,a,b,c = 0;
    cin >> n;
    a = clock();
    while(n--){
        c++;
    }
    b = clock();
    cout << double(b-a) / CLOCKS_PER_SEC <<' ' << c <<endl;
}