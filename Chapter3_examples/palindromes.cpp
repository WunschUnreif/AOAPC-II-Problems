#include <iostream>
#include <cstdio>
#include <cstring>

char reverse[] = "1SE Z  8        A   3  HIL JM O   2TUVWXY5";

bool testPali(char *s, int length) {
    for(int i = 0; i < length; i++) {
        if(s[i] != s[length - 1 - i])
            return false;
    }
    return true;
}

bool testRev(char *s, int length) {
    for(int i = 0; i < length; i++) {
        char rev = reverse[s[i] - '1'];
        //printf("%c %c\n", s[i], rev);
        if(s[length - 1 - i] != rev)
            return false;
    }
    return true;
}

int main() {
    char s[100];
    while(scanf("%s", s) == 1) {
        bool a = testPali(s, strlen(s));
        bool b = testRev(s, strlen(s));
        //std::cout << reverse['E' - '1'] << std::endl;
        if(a && b) printf("%s -- is a mirrored palindrome.\n\n",s);
        if(a && !b) printf("%s -- is a regular palindrome.\n\n",s);
        if(!a && b) printf("%s -- is a mirrored string.\n\n",s);
        if(!a && !b) printf("%s -- is not a palindrome.\n\n",s);
    }
    return 0;
}
