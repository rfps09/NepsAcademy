#include <iostream>
#include <climits>

using namespace std;

const int MAXN = 205;
int grafinho[MAXN][MAXN];
int count;

int dfs(int x, int y) {
    count++;
    
    int atual = grafinho[x][y];
    
    grafinho[x][y] = -1;
    
    if(grafinho[x+1][y] == atual) dfs(x+1,y);
    if(grafinho[x-1][y] == atual) dfs(x-1,y);
    if(grafinho[x][y+1] == atual) dfs(x,y+1);
    if(grafinho[x][y-1] == atual) dfs(x,y-1);
    
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    int h = 0, l = 0, aux = 0;
    int min = INT_MAX, conex = 0;
    
    cin >> h >> l;
    
    for(int i = 0; i <= h+1; i++) 
    for(int j = 0; j <= l+1; j++) 
    grafinho[i][j] = -1;
    
    for(int i = 1; i <= h; i++) 
    for(int j = 1; j <= l; j++) 
    cin >> grafinho[i][j];
    
    for(int i = 1; i <= h; i++) 
    for(int j = 1; j <= l; j++) 
    if(grafinho[i][j] != -1) {
        conex = dfs(i,j);
        min = conex < min ? conex : min;
        count = 0;
    }
    
    cout << min << endl;
    
    return 0;
}
