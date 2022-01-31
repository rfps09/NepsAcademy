#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
using pii = pair<int,long long int>;
 
const int MAXN = 1e5+1;
const int MAXLOG = 17;

int n;
vector<pii> grafinho[MAXN];
pii pai[MAXN][MAXLOG];
int nivel[MAXN];

void limpar() {
    for(int i = 0; i < n; i++) {
        vector<pii> grafo;
        swap(grafinho[i],grafo);
    }
}
 
void troca(int &x, int &y) {
    int aux = y;
    y = x;
    x = aux;
}
 
void dfs(int x) {
    for(int i = 0; i < grafinho[x].size(); i++) {
        pii y = grafinho[x][i];
        nivel[y.first] = nivel[x]+1;
        pai[y.first][0] = pii(x,y.second);
        for(int j = 1; j < MAXLOG; j++) {
            pai[y.first][j] = pai[pai[y.first][j-1].first][j-1];
            pai[y.first][j].second += pai[y.first][j-1].second;
        }
        dfs(y.first);
    }
}
 
long long int lca(int x, int y) {
    long long int ans = 0;
    if(nivel[y] > nivel [x]) troca(x,y);
 
    for(int i = MAXLOG-1; i >= 0; i--) {
        if(nivel[x] - (1<<i) >= nivel[y]) {
            ans += pai[x][i].second;
            x = pai[x][i].first;
        }
    }
 
    if(x == y) return ans;
 
    for(int i = MAXLOG-1; i >= 0; i--) {
        if(pai[x][i].first != pai[y][i].first) {
            ans += pai[x][i].second;
            ans += pai[y][i].second;
            x = pai[x][i].first;
            y = pai[y][i].first;
        }
    }
 
    ans += pai[x][0].second;
    ans += pai[y][0].second;
 
    return ans;
}
 
int main() {
    ios::sync_with_stdio(0);
    int c = 0;
    long long int x=0, y=0;
 
    while(cin >> n && n) {
        limpar();
        
        for(int i = 1; i < n; i++) {
            cin >> x >> y;
            grafinho[x].push_back(pii(i,y));
        }
 
        dfs(0);
 
        cin >> c;
        c--;
        string ans;
        for(int i = 0; i < c; i++) {
            cin >> x >> y;
            ans += to_string(lca(x,y));
            ans+= " ";
        }
        cin >> x >> y;
        ans += to_string(lca(x,y));
 
        cout << ans << "\n";
    }
 
    return 0;
}
