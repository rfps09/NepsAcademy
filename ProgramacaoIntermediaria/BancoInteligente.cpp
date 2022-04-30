#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 6;
const int MAXQ = 501;
const int MAXS = 5010;

int val[MAXN] = {2,5,10,20,50,100};
int qtd[MAXN];
int memo[MAXN][MAXQ][MAXS];

int solve(int i, int s) {
    if(!i || !s) return s==0;

    if(memo[i-1][qtd[i-1]][s] != -1)
        return memo[i-1][qtd[i-1]][s];

    int ans = 0;

    if(s >= val[i-1] && qtd[i-1]) {
        qtd[i-1]--;
        ans += solve(i,s-val[i-1]);
        qtd[i-1]++;
    }    

    ans += solve(i-1,s);

    return memo[i-1][qtd[i-1]][s] = ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int s;

    cin >> s;

    for(int i=0; i<MAXN; i++)
        cin >> qtd[i];

    memset(memo,-1,sizeof(memo));

    cout << solve(MAXN,s) << endl;

    return 0;
}