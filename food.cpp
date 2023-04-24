#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

string removeCount(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            result += s[i];
        }
    }
    return result;
}

map<char, int> getCount(string s) {
    map<char, int> count;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            char c = s[i];
            if (count.find(c) == count.end()) {
                count[c] = 1;
            }
            else {
                count[c]++;
            }
        }
    }
    return count;
}

string simplifyBoxes(string boxes) {
    string result = "";
    int currentCount = 1;
    for (int i = 0; i < boxes.length(); i++) {
        if (boxes[i] >= 'A' && boxes[i] <= 'Z') {
            if (currentCount > 1) {
                result += to_string(currentCount);
            }
            result += boxes[i];
            currentCount = 1;
        }
        else if (boxes[i] >= '0' && boxes[i] <= '9') {
            currentCount = currentCount * 10 + (boxes[i] - '0');
        }
    }
    if (currentCount > 1) {
        result += to_string(currentCount);
    }
    return result;
}

string simplify(string s) {
    string boxes = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '$' && s[i] <= '*') {
            boxes += s[i];
        }
    }
    string gems = removeCount(s);
    map<char, int> count = getCount(gems);
    string simplifiedBoxes = simplifyBoxes(boxes);
    map<char, int> boxCount;
    for (int i = 0; i < simplifiedBoxes.length(); i++) {
        char c = simplifiedBoxes[i];
        if (boxCount.find(c) == boxCount.end()) {
            boxCount[c] = 1;
        }
        else {
            boxCount[c]++;
        }
    }
    string result = "";
    for (char c = 'A'; c <= 'Z'; c++) {
        if (count.find(c) != count.end()) {
            result += c;
            result += to_string(count[c]);
        }
        if (boxCount.find(c) != boxCount.end() && boxCount[c] > 0) {
            result += c;
            result += to_string(boxCount[c]);
        }
    }
    return result;
}

int main() {
    string s1 = "$A5B;";
    string s2 = "$A4%BC&XB3,2:3;";
    cout << simplify(s1) << endl; // Output: A5B
    cout << simplify(s2) << endl; // Output: A4B21C3X6
    return 0;
}
