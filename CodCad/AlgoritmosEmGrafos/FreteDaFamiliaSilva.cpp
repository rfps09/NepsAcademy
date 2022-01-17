#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
using pii = pair<int,int>;

const int MAXN = 1000;
const int INF = INT_MAX;

int n,m;
int p,q,u;
vector<pii> grafinho[MAXN];
int distancia[MAXN];
int processado[MAXN];

int prim(int x) {
  int ans = 0;

  for(int i = 0; i < n; i++) distancia[i] = INF;
  distancia[x] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> fila;
  fila.push(pii(distancia[x],x));

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

      if(distancia[no] > dist && !processado[no]) {
        distancia[no] = dist;
        fila.push(pii(distancia[no],no));
      }
    }
  }

  for(int i = 0; i < n; i++) {
    ans += distancia[i];
  }

  return ans;
}

int main() {
  cin >> n >> m;

  for(int i = 0; i < m; i++) {
    cin >> p >> q >> u;
    grafinho[p].push_back(pii(q,u));
    grafinho[q].push_back(pii(p,u));
  }

  cout << prim(0) << endl;

  return 0;
}
