#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

using pii = pair<int,int>;

const int MAXN = 1002;
const int INF = INT_MAX;

int n, m;
int s, t, b;

vector<pii> grafinho[MAXN];
int distancia[MAXN];
int processado[MAXN];

void dijkstra(int start){
  for(int i = 0; i <= n; i++)
    distancia[i] = INF;
  distancia[start] = 0;

  priority_queue<pii,vector<pii>, greater<pii>> fila;

  fila.push(pii(distancia[start], start));

  while(true) {
    int youTurn = -1;

    while(!fila.empty()) {
      int atual = fila.top().second;
      fila.pop();

      if(!processado[atual]) {
        youTurn = atual;
        break;
      }
    }

    if(youTurn == -1) break;

    processado[youTurn] = true;

    for(int i = 0; i < grafinho[youTurn].size(); i++) {
      int dist = grafinho[youTurn][i].second;
      int no = grafinho[youTurn][i].first;

      if(distancia[no] > distancia[youTurn]+dist) {
        distancia[no] = distancia[youTurn]+dist;
        fila.push(pii(distancia[no], no));
      }
    }
  }
}

int main() {
  cin >> n >> m;
  n++;

  for(int i = 0; i < m; i++){
    cin >> s >> t >> b;
    grafinho[s].push_back(pii(t,b));
    grafinho[t].push_back(pii(s,b));
  }

  dijkstra(0);

  cout << distancia[n];

  return 0;
} 
