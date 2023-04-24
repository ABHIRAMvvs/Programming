#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;

int dp[MAXN][MAXN];

int main() {
    int n, sum = 0;
    cin >> n;

    vector<int> rates(n);
    for (int i = 0; i < n; i++) {
        cin >> rates[i];
        sum += rates[i];
    }

    sum /= 2;
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j >= rates[i-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-rates[i-1]] + rates[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << abs(sum-dp[n][sum]-dp[n][sum]) << endl;

    return 0;
}
