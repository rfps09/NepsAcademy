#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int solve(string entrada) {
    int ans = 0;
    int len = entrada.length();
    char dp[len+1];

    memset(dp,'[',sizeof(dp));
    dp[0] = 64;

    for(int i=0; i<len; i++) {
        int p = upper_bound(dp, dp + len + 1, entrada[i]) - dp;
        dp[p] = entrada[i];
    }

    for(int i=1; i<=len; i++) {
        if(dp[i] < '[') ans = i;
    }

    return ans;
}

int main() {
    string entrada;

    cin >> entrada;

    cout << solve(entrada) << "\n";

    return 0;
}