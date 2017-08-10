#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct Grid{
    int r;int c;
};
struct Cmd{
    char what[10];
    int n;
    vector<int> parameters;
};
bool solve(int num) {
    vector<Cmd> cmds;
    vector<Grid> grids;
    int r,cc;
    scanf("%d%d",&r,&cc);
    int cmdN;
    scanf("%d",&cmdN);
    for(int i = 0; i < cmdN; i++) {
        char cmd[10];scanf("%s",cmd);
        if(cmd[0] == 'E') {
            int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
            Cmd cm;strcpy(cm.what,cmd);cm.parameters.push_back(a);
            cm.parameters.push_back(b);cm.parameters.push_back(c);cm.parameters.push_back(d);
            cmds.push_back(cm);
        } else {
            Cmd c;strcpy(c.what,cmd);
            int n;scanf("%d",&n);c.n = n;
            while(n--){int x;scanf("%d",&x);c.parameters.push_back(x);}sort(c.parameters.begin(),c.parameters.end());
            cmds.push_back(c);
        }
    }
    int gridN;scanf("%d",&gridN);
    for(int i =0; i < gridN; i++) {
        int a,b;scanf("%d%d",&a,&b);Grid g = {a,b};grids.push_back(g);
    }
    vector<Grid> grido = grids;
    for(int i = 0; i < cmdN; i++){
        Cmd c = cmds[i];
        if(c.what[0] == 'E') {
            int r1=c.parameters[0],c1=c.parameters[1],r2=c.parameters[2],c2=c.parameters[3];
            Grid *g1 = NULL, *g2 = NULL;
            for(auto j = grids.begin(); j != grids.end(); j++) {
                if(*j.r == r1 && *j.c == c1)g1 = &j;
                if(*j.r == r2 && *j.c == c2)g2 = &j;
            }
            if(g1&&g2){Grid tmp = *g1;*g1 = *g2;*g2 = tmp;}
            else{if(g1 == NULL){*g2.r = r1;*g2.c = c1;}else{*g1.r = r2;*g1.c = c2;}}
        } else {
            if(c.what[0] == 'I') {
                if(c.what[1] == 'R') {
                    for(auto k = grids.begin(); k != grids.end(); k++){
                        int kr = *k.r
                        for(auto j = c.parameters.begin(); j != c.parameters.end(); j++) {
                            if(*k.r >= *j)kr++;
                        }
                        *k.r = kr;
                    }
                } else {
                    for(auto k = grids.begin(); k != grids.end(); k++){
                        int kc = *k.c
                        for(auto j = c.parameters.begin(); j != c.parameters.end(); j++) {
                            if(*k.c >= *j)kc++;
                        }
                        *k.c = kc;
                    }
                }
            } else {
                if(c.what[1] == 'R') {
                    for(auto k = grids.begin(); k != grids.end(); k++){
                        int kr = *k.r;
                        for(auto j = c.parameters.begin(); j != c.parameters.end(); j++) {
                            if(*k.r == *j)kr = 0;
                            if(*k.r > *j)kr--;
                        }
                        *k.r = kr;
                    }
                } else {
                    for(auto k = grids.begin(); k != grids.end(); k++){
                        int kc = *k.c;
                        for(auto j = c.parameters.begin(); j != c.parameters.end(); j++) {
                            if(*k.c == *j)kc = 0;
                            if(*k.c > *j)kc--;
                        }
                        *k.c = kc;
                    }
                }
            }
        }
    }
    printf("Spreadsheet #%d\n",num);
    for(int i = 0; i < gridN; i++){
        printf("Cell data in (%d,%d) ",grido[i].r,grido[i].c);
        if(!(grids[i].r && grids[i].c))printf("GONE\n");
        else printf("moved to (%d,%d)\n",grids[i].r,grids[i].c);
    }
    return true;
}

int main() {
    int i = 1;
    while(solve(i))i++;
    return 0;
}
