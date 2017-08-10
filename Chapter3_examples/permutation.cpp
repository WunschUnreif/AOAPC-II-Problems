#include <iostream>
using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)

int main() {
    FOR(a,1,10)
    FOR(b,1,10)
    FOR(c,1,10)
    FOR(d,1,10)
    FOR(e,1,10)
    FOR(f,1,10)
    FOR(g,1,10)
    FOR(h,1,10)
    FOR(i,1,10)
    {   
        int use[10] = {1,0,0,0,0,0,0,0,0,0};
        bool flag = true;
        use[a]++;use[b]++;use[c]++;use[d]++;use[e]++;use[f]++;use[g]++;use[h]++;use[i]++;
        for(int i : use) if(i == 0) flag = false;
        if(flag) {
            int x = 100 * a + 10 * b + c;
            int y = 100 * d + 10 * e + f;
            int z = 100 * g + 10 * h + i;
            if(z == 3 * x && y == 2 * x)
                printf("%d %d %d \n", x, y, z);
        }
    }
    return 0;
}