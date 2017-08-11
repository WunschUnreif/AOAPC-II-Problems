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
#include <cstdlib>
#include <ctime>

struct BigInteger {
    std::vector<int> nums;
    BigInteger(long long number = 0) {
        while(number) {
            nums.push_back(number % 10);
            number /= 10;
        }
    }
    BigInteger(std::string numStr) {
        for(int i = numStr.length() - 1; i >= 0; i--)
            nums.push_back(numStr[i] - '0');
    }
    BigInteger operator = (long long number) {
        nums.clear();
        while(number) {
            nums.push_back(number % 10);
            number /= 10;
        }
        return *this;
    }

    BigInteger operator = (const std::string &numStr) {
        nums.clear();
        for(int i = numStr.length() - 1; i >= 0; i--)
            nums.push_back(numStr[i] - '0');
        return *this;
    }
};

std::ostream& operator << (std::ostream &out, const BigInteger &bign) {
    for(int i = bign.nums.size() - 1; i >= 0; i--) {
        out << bign.nums[i];
    }
    return out;
}

std::istream& operator >> (std::istream &in, BigInteger &bign) {
    std::string inStr;
    if(!(in >> inStr)) return in;
    bign = inStr;
    return in;
}

int main() {
    BigInteger bing = 1;
    std::cout << bing << std::endl;
    std::cin >> bing;
    std::cout << bing << std::endl;  
    return 0;
}
