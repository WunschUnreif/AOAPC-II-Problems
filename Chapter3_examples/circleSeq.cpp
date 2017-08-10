#include <iostream>
#include <cstdio>
#include <cstring>

bool less(std::string s1, std::string s2) {
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] < s2[i]) return true;
        if(s1[i] == s2[i])continue;
        if(s1[i] > s2[i]) return false;
    }
    return true;
}

int main() {
    std::string ans;
    int t;
    std::cin >> t;
    while(t--) {
        std::cin >> ans;
        std::string pri(ans);
        for(int i = 0; i < ans.length() - 1; i++) {
            std::string newStr(pri);
            for(int j = 0; j < ans.length(); j++) {
                newStr[j] = pri[(j + i + 1) % ans.length()];
            }
            // std::cout << newStr << std::endl;
            if(less(newStr,ans)) ans = newStr;
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
