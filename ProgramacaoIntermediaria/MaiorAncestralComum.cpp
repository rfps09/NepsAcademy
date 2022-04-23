#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e3+10;
const int MAXM = 1e3+10;

int memo[MAXN][MAXM];

int solve(int *vetorN,int *vetorM,int n,int m) {
    if(!n || !m) return 0;

    if(memo[n][m] != -1) return memo[n][m];

    int ans = 0;

    if(vetorN[n-1] != vetorM[m-1]) {
        ans = solve(vetorN,vetorM,n,m-1);
        ans = max(ans,solve(vetorN,vetorM,n-1,m));
    } else ans = solve(vetorN,vetorM,n-1,m-1)+1;

    return memo[n][m] = ans;
}

int main() {
    int n,m;

    cin >> n >> m;

    int vetorN[n], vetorM[m];

    for(int i=0; i<n; i++)
        cin >> vetorN[i];

    for(int i=0; i<m; i++)
        cin >> vetorM[i];

    memset(memo,-1,sizeof(memo));

    int ans = solve(vetorN,vetorM,n,m);

    cout << n-ans << " " << m-ans << "\n";

    return 0;
}