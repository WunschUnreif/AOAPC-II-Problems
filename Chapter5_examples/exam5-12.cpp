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

struct Building {
    int id;
    double x, y, w, d, h;
    bool operator < (const Building &b) {
        return x < b.x || (x == b.x && y < b.y);
    }
};

Building buildings[105];
int buildingNumber = 0;
double setX[210];

bool cover(int id, double mx) {
    return mx >= buildings[id].x && mx <=buildings[id].x + buildings[id].w;
}

bool visible(int id, double mx) {
    if(!cover(id, mx)) return false;
    for(int i = 0; i < buildingNumber; i++) {
        if(cover(i, mx) && buildings[i].y < buildings[id].y && buildings[i].h >= buildings[id].h)
            return false;
    }
    return true;
}

int main() {
    int kase = 0;
    while(scanf("%d", &buildingNumber) == 1 && buildingNumber) {
        for(int i = 0; i < buildingNumber; i++) {
            scanf("%lf%lf%lf%lf%lf", &buildings[i].x, &buildings[i].y,
                    &buildings[i].w, &buildings[i].d, &buildings[i].h);
            buildings[i].id = i + 1;
            setX[2 * i] = buildings[i].x;
            setX[2 * i + 1] = buildings[i].x + buildings[i].w;
        }
        sort(buildings, buildings + buildingNumber);
        sort(setX, setX + buildingNumber * 2);
        int uniqueX = unique(setX, setX + buildingNumber * 2) - setX;
        if(kase++) printf("\n");
        printf("For map #%d, the visible buildings are numbered as follows:\n%d",
                    kase, buildings[0].id);
        for(int i = 1; i < buildingNumber; i++) {
            bool vis = false;
            for(int j = 0; j < uniqueX; j++) {
                if(visible(i, setX[j])){vis = true; break;}
            }
            if(vis) printf(" %d", buildings[i].id);
        }
        printf("\n");
    }
    return 0;
}
