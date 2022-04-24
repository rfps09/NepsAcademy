#include <iostream>

using namespace std;

const long long int cresc = 0;
const long long int desc = 1;
const long long int MAXN = 1e5+1;
const long long int INF = 1e9+10;

long long int dp[MAXN];
long long int atual[MAXN];
long long int anterior[MAXN];

void troca(long long int &a, long long int &b) {
    long long int aux = a;
    a = b;
    b = aux;
}

void solve(long long int *vetor, long long int len, long long int order, long long int *ans) {
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
        long long int p = lower_bound(dp,dp+len+1,vetor[i]) - dp;
        dp[p] = vetor[i];
        if(atual[p] == -1)atual[p] = i;
        anterior[i] = atual[p-1];
    }

    for(int i=1; i<=len; i++) {
        if(dp[i] < INF) dp[0] = i;
    }
    
    ans[0] = dp[0];
    long long int count = 1;
    long long int value = atual[dp[0]];

    for(int i=dp[0]; i>0; i--) {
        ans[count] = value;
        value = anterior[value];
        count++;
    }
}

int main() {
    long long int m=0;

    cin >> m;

    long long int vetor[m];

    for(int i=0; i<m; i++) {
        cin >> vetor[i];
    }

    long long int ansCresc[MAXN];
    solve(vetor,m,cresc,ansCresc);
    long long int ansDesc[MAXN];
    solve(vetor,m,desc,ansDesc);

    long long int iCresc= 1;
    long long int iDesc= 1;

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
    
    long long int ans=0;
    
    ans = min(ansCresc[0],ansDesc[0]) * 2 - 1;

    cout << ans << endl;

    return 0;
}