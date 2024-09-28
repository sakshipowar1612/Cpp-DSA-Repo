#include <iostream>
#include <string>
using namespace std;

void rotate(string &s) {
    int n = s.length();
    char temp = s[n-1];
    for (int i = n-2; i >= 0; i--) {
        swap(s[i], s[i+1]);
    }
    s[0] = temp;
}

bool areRotations(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }
    int n = s1.length();
    bool areSame = false;
    for (int i = 0; i < n; i++) {
        if (s1 == s2) {
            areSame = true;
            break;
        }
        rotate(s1);
    }
    return areSame;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    if (areRotations(s1, s2)) {
        cout << "The strings are rotations of each other." << endl;
    } else {
        cout << "The strings are not rotations of each other." << endl;
    }

    return 0;
}
