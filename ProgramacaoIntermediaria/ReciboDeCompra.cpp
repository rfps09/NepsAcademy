#include <iostream>

using namespace std;

int solve(int opcao, int k, int valor) {
    if(!k) return valor == 0;

    int ans = 0;
    for(int i = opcao+1; i <= valor; i++)
        ans += solve(i,k-1,valor-i);

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int r=0,k=0;

    cin >> r >> k;

    cout << solve(0,k,r) << "\n";

    return 0;
}