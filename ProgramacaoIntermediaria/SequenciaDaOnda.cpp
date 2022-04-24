#include <iostream>

using namespace std;

const int cresc = 0;
const int desc = 1;
const int MAXN = 1e5+1;
const int INF = 1e9+10;

int dp[MAXN];
int atual[MAXN];
int anterior[MAXN];

void troca(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

void solve(int *vetor, int len, int order, int *ans) {
    if(order) {
        for(int i=0; i<len/2; i++) {
            troca(vetor[i], vetor[len-i-1]);
        }
    }

    dp[0] = -INF;
    for(int i=1; i<= len; i++) {
        dp[i] = INF;
        atual[i] = -1;
    }

    for(int i=0;i<len;i++) {
        int p = lower_bound(dp,dp+len+1,vetor[i]) - dp;
        dp[p] = vetor[i];
        if(atual[p] == -1)atual[p] = i;
        anterior[i] = atual[p-1];
    }

    for(int i=1; i<=len; i++) {
        if(dp[i] < INF) dp[0] = i;
    }
    
    ans[0] = dp[0];
    int count = 1;
    int value = atual[dp[0]];

    for(int i=dp[0]; i>0; i--) {
        ans[count] = value;
        value = anterior[value];
        count++;
    }
}

int main() {
    int m=0;

    cin >> m;

    int vetor[m];

    for(int i=0; i<m; i++) {
        cin >> vetor[i];
    }

    int ansCresc[MAXN];
    solve(vetor,m,cresc,ansCresc);
    int ansDesc[MAXN];
    solve(vetor,m,desc,ansDesc);

    int iCresc= 1;
    int iDesc= 1;

    while(ansCresc[iCresc] > abs(ansDesc[iDesc]-(m-1))) {
        if(ansCresc[0] > ansDesc[0]) {
            ansCresc[0]--;
            iCresc++;
        }
        else {
            ansDesc[0]--;
            iDesc++;
        }
    }
    
    int ans=0;
    
    ans = min(ansCresc[0],ansDesc[0]) * 2 - 1;

    cout << ans << endl;

    return 0;
}