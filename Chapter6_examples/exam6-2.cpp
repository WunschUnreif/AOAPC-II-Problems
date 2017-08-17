#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <map>
#include <queue>
using namespace std;

void sovle(int n) {
    int in[n];
    for(int i = 1; i <= n; i++) in[i-1] = i;
    int id;
    while((scanf("%d", &id)==1) && id) {
        queue<int> out;
        out.push(id);
        for(int i = 0; i < n - 1; i++) {
            scanf("%d", &id);
            out.push(id);
        }
        int ptr = 0;
        stack<int> station;
        // bool ok = false;
        while(ptr < n) {
            //if(!out.size())break;
            do{
                station.push(in[ptr++]);
            }while(station.top() != out.front() && ptr < n);
            while(station.top() == out.front()){
                //cout << station.top() << endl;
                station.pop();
                out.pop();
                if(!station.size() || !out.size()) break;
            }
        }
        if(!station.size())
            printf("Yes\n");
        else
            printf("No\n");
    }
    cout << endl;
}

int main() {
    int n;
    while((scanf("%d", &n)==1) && n)sovle(n);
    return 0;
}
