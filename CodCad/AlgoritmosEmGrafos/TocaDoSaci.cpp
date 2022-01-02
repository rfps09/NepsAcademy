#include <iostream>

using namespace std;

const int MAXN = 1002;

int grafinho[MAXN][MAXN];
int count;

void dfs(int x, int y,int contador) {
    int it = contador;
    it++;
    
    if(grafinho[x][y] == 3) count = it;
    
    grafinho[x][y] = 0;
    
    if(grafinho[x+1][y] > 0) dfs(x+1, y, it);
    if(grafinho[x-1][y] > 0) dfs(x-1, y, it);
    if(grafinho[x][y+1] > 0) dfs(x, y+1, it);
    if(grafinho[x][y-1] > 0) dfs(x, y-1, it);
}

int main() {
    int n = 0, m = 0;
    int x = 0, y = 0;
    int contador = 0;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> grafinho[i][j];
            if(grafinho[i][j] == 2) {
                x = i;
                y = j;
            }
        }
    }
    
    dfs(x,y,contador);
    
    cout << count << endl;
    
    return 0;
}
