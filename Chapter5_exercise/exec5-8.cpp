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

struct Book {
    string name;
    string author;
    bool borrowed = false;
    bool returning = false;
    Book(string name, string author):name(name), author(author) {}
    bool operator < (const Book &b) {
        return author < b.author || (author == b.author && name < b.name);
    }
};

vector<Book> shelf;

void printShelf() {
    for(auto b : shelf) {
        cout << b.name << ' ' << b.author << endl;
    }
}

string readName() {
    char name[100];
    char c;
    while((c = getchar()) != '\"') if(c == 'E'){getchar();getchar();getchar();return "";};
    name[0] = '\"';
    int len = 1;
    while((c = getchar()) != '\"') {
        name[len++] = c;
    }
    name[len] = '\"';name[len + 1] = '\0';
    return string(name);
}

string readAuthor() {
    char author[100];
    int len = 1;
    char c;
    while(isspace(c = getchar()));
    author[0] = c;
    while((c = getchar()) != '\n' && c != '\r') {
        author[len++] = c;
    }
    author[len] = '\0';
    return string(author);
}

void readBook() {
    string name, author;
    while((name = readName()) != "") {
        string by;cin >> by;
        author = readAuthor();
        shelf.push_back(Book(name, author));
    }
    sort(shelf.begin(), shelf.end());
}

Book findBookBefore(Book book) {
    Book ret("","");
    for(int i = 0; i < (int)shelf.size(); i++) {
        if(shelf[i].name == book.name) return ret;
        else if(!shelf[i].borrowed) ret = shelf[i];
    }
    return ret;
}

void borrowBook(Book book, bool borrow = true) {
    for(int i = 0; i < (int)shelf.size(); i++) {
        if(shelf[i].name == book.name) {
            if(borrow) shelf[i].borrowed = true;
            else shelf[i].returning = true;
            break;
        }
    }
}

void simulate() {
    string command;
    while(cin >> command && command != "END") {
        if(command[0] == 'B') {
            string name = readName();
            borrowBook(Book(name,""));
        } else if(command[0] == 'R') {
            string name = readName();
            borrowBook(Book(name,""), false);
        } else {
            for(int i = 0; i < (int)shelf.size(); i++) {
                if(shelf[i].returning == true) {
                    Book before = findBookBefore(shelf[i]);
                    if(before.name == "") cout << "Put " << shelf[i].name << " first" << endl;
                    else cout << "Put " << shelf[i].name << " after " << before.name << endl;
                    shelf[i].returning = false;
                    shelf[i].borrowed = false;
                }
            }
            cout << "END" << endl;
        }
    }
}

int main() {
    readBook();
    simulate();
    return 0;
}
