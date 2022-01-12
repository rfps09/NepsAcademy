#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

using pii = pair<int,int>;
using pip = pair<int,pii>;

int n;
const int MAXN = 104;
const int INF = INT_MAX;

int grafinho[MAXN][MAXN];
int distancia[MAXN][MAXN];
int processado[MAXN][MAXN];

void dijkstra(int x, int y) {
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    distancia[i][j] = INF;
    
    distancia[x][y] = 0;
    
    priority_queue<pip, vector<pip>, greater<pip>> fila;
    
    fila.push(pip(distancia[x][y], pii(x,y)));
    
    while(true) {
        pii youTurn(-1,-1);
        
        while(!fila.empty()) {
            pii atual = fila.top().second;
            fila.pop();
            
            if(!processado[atual.first][atual.second]) {
                youTurn = atual;
                break;
            }
        }
        
        if(youTurn.first == -1 && youTurn.second == -1) break;
        if(youTurn.first == n && youTurn.second == n) break;
        
        processado[youTurn.first][youTurn.second] = true;
        
        int X = youTurn.first;
        int Y = youTurn.second;
        
        if(grafinho[X+1][Y] != -1) {
            if(distancia[X+1][Y] > distancia[X][Y] + grafinho[X+1][Y]) {
                distancia[X+1][Y] = distancia[X][Y] + grafinho[X+1][Y];
                fila.push(pip(distancia[X+1][Y],pii(X+1,Y)));
            }
        }
        if(grafinho[X-1][Y] != -1) {
            if(distancia[X-1][Y] > distancia[X][Y] + grafinho[X-1][Y]) {
                distancia[X-1][Y] = distancia[X][Y] + grafinho[X-1][Y];
                fila.push(pip(distancia[X-1][Y],pii(X-1,Y)));
            }
        }
        if(grafinho[X][Y+1] != -1) {
            if(distancia[X][Y+1] > distancia[X][Y] + grafinho[X][Y+1]) {
                distancia[X][Y+1] = distancia[X][Y] + grafinho[X][Y+1];
                fila.push(pip(distancia[X][Y+1],pii(X,Y+1)));
            }
        }
        if(grafinho[X][Y-1] != -1) {
            if(distancia[X][Y-1] > distancia[X][Y] + grafinho[X][Y-1]) {
                distancia[X][Y-1] = distancia[X][Y] + grafinho[X][Y-1];
                fila.push(pip(distancia[X][Y-1],pii(X,Y-1)));
            }
        }
    }
}

int main() {
    cin >> n;
    
    //Anulando as laterais
    for(int j = 0; j <= n+1; j++)
        grafinho[0][j] = -1;
    for(int i = 0; i <= n+1; i++)
        grafinho[i][0] = -1;
    for(int j = 0; j <= n+1; j++)
        grafinho[n+1][j] = -1;
    for(int i = 0; i <= n+1; i++)
        grafinho[i][n+1] = -1;
    
    //criando o grafo em forma de matriz
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> grafinho[i][j];
        }
    }
    
    dijkstra(1,1);
    
    cout << distancia[n][n] << endl;

    return 0;
}
