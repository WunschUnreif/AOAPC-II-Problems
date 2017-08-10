#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

int a[1000],n;
int b[1000],quan[1000],height[1000],area[1000],used;

bool solve(int regionNum) {
    int c,d;
    scanf("%d%d",&c,&d);
    if(c == d && !c) return false;
    n = c*d;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a+n);
    b[0] = a[0];quan[0] = 1;
    used = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] != b[used - 1]) {
            b[used] = a[i];
            height[used-1] = a[i] - b[used-1];
            quan[used++] = 1;
        } else {
            quan[used-1]++;
        }
    }
    area[0] = 100 * quan[0];
    for(int i = 1; i < used; i ++) {
        area[i] = area[i-1] + 100 * quan[i];
    }
    double vol;
    int yanmuo = 0;
    scanf("%lf", &vol);
    double currVol = 0;
    double currHeight = 0;
    int i;
    for(i = 0; i < used - 1; i++) {
        yanmuo += quan[i];
        //std::cout << vol << std::endl;
        if(currVol < vol && currVol + area[i] * height[i] >= vol) {
            currHeight += (vol - currVol) / area[i];
            break;
        } else {
            currVol += area[i] * height[i];
            currHeight += height[i];
        }
    }
    //printf("%f %f %f\n", vol, currVol, currHeight);
    if(i == used - 1) {
        currHeight += (vol - currVol) / double(100 * n);
        yanmuo = n;
    }
    //printf("%lf %lf %lf\n", vol, currVol, currHeight);
    currHeight += b[0];
    printf("Region %d\n", regionNum);
    printf("Water level is %.2lf meters.\n", currHeight);
    printf("%.2lf percent of the region is under water.\n\n",yanmuo/double(n)*100.0);
    return true;
}
int main() {
    int rgn = 0;
    while(solve(++rgn));
    return 0;
}
