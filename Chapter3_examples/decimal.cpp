#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    double s = double(a) / b;
    printf("%.*f", c, s);
    return 0;
}