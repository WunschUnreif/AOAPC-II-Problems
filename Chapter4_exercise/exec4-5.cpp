#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct Address {
    long long add;
    Address(long long a, long long b, long long c, long long d) {
        add = (d << 24) + (c << 16) + (b << 8) + a;
        //char s[35];itoa(add,s,2);
        //printf("%s\n",s);
    }
    Address(long long n){add = n;}
    int numAt(int n){
        return ((add & (0x80000000 >> n)) == 0 ? 0 : 1);
    }
    void getString() {
        int a,b,c,d;
        a = (add & 0xff000000) >> 24;b = (add & 0x00ff0000) >> 16;
        c = (add & 0x0000ff00) >> 8;d = add & 0x000000ff;
        printf("%lld.%lld.%lld.%lld\n",a,b,c,d);
    }
};

int getint() {
    int ans = 0;
    char c;
    while(true){
        while(true){
            c = getchar();
            if(isdigit(c)) break; 
            else if(c=='.' || isspace(c)){
                //printf("%d\n",ans);
                return ans;
            }
        }
        
        ans = ans * 10 + c - '0';
    }
}

int main() {
    int m;
    while(scanf("%d",&m) != EOF) {
        vector<Address> ips;
        getchar();
        for(int i = 0; i < m; i++) {
            ips.push_back(Address(getint(),getint(),getint(),getint()));
        }
        int n = 0;
        bool ok = true;
        for(int i = 0; i < 32 && ok; i++) {
            int key = ips[0].numAt(i);
            for(int j = 1; j < m && ok; j++){
                if(ips[j].numAt(i) != key) ok = false;
            }
            if(ok) n++;
        }
        long long mask = 0ll;
        for(int i = 0; i < n; i++) {
            mask |= 0x0000000080000000 >> i;
        }
        long long minIP = 0ll;
        for(int i = 0; i < n; i++) {
            minIP |= ips[0].numAt(i) << (31 - i);
        }
        Address(minIP).getString();
        Address(mask).getString();
    }
    return 0;
}