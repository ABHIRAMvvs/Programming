#include <iostream>
#include <string>

using namespace std;

int countOnes(string s) {
    int count = 0;
    for (char c : s) {
        count += (c & 1);
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2, s3;
        int n;
        cin >> s1 >> s2 >> s3 >> n;
        string s = s1 + s2;
        for (int i = 0; i < n; i++) {
            s += s2;
        }
        s += s3;
        cout << countOnes(s) << endl;
    }
    return 0;
}
