#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e3+1;
vector<int> grafinho[MAXN];
int component[MAXN];
int count;

void dfs(int x) {
    int y = 0;
    component[x] = count;
    
    for(int i = 0; i < grafinho[x].size(); i++) {
        y = grafinho[x][i];
        if(component[y] == -1) dfs(y);
    }
}

int main() {
    int n = 0, m = 0, x = 0, y = 0;
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        grafinho[x].push_back(y);
        grafinho[y].push_back(x);
    }
    
    for(int i = 0; i <= n; i++) {
        component[i] = -1;
    }
    
    for(int i = 1; i <= n; i++) {
        if(component[i] == -1) {
            count++;
            dfs(i);
        }
    }

    cout << count << "\n";
    
    return 0;
}
