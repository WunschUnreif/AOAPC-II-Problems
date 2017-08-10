#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int nums[12];

struct Rect {
    int a;
    int b;
    bool operator < (Rect c) {
        return (a < c.a || (a == c.a) && b < c.b);
    }
    bool operator == (Rect c) {
        return a==c.a && b == c.b;
    }
};

Rect rects[6];

int main() {
    while(scanf("%d",&nums[0]) != EOF) {
        bool ok = true;
        for(int i = 1; i < 12; i++) scanf("%d", &nums[i]);
        for(int i = 0; i < 6; i++) {
            rects[i].a = std::min(nums[2 * i],nums[2 * i + 1]);
            rects[i].b = std::max(nums[2 * i],nums[2 * i + 1]);
        }
        std::sort(rects, rects + 6);
        if(rects[0]==rects[1] && rects[2]==rects[3] && rects[4]==rects[5] &&
            rects[0].a == rects[1].a && rects[1].a == rects[2].a && rects[2].a == rects[3].a &&
            rects[0].b == rects[1].b && rects[1].b == rects[4].a && rects[4].a == rects[5].a &&
            rects[2].b == rects[3].b && rects[3].b == rects[4].b && rects[4].b == rects[5].b) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");

    }
}
