#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 250+1;
const int INF = INT_MAX/2;

int grafinho[MAXN][MAXN];

int main() {
  int s=0, c=0, a=0, b=0, d=0;
  int ansx=0, ansy=INF;

  cin>>s>>c;

  for(int i=1; i<=s; i++){
    for(int j=1; j<=s; j++){
      if(i==j) grafinho[i][j]=0;
      else grafinho[i][j] = INF;
    }
  }

  for(int i=0; i<c; i++){
    cin>>a>>b>>d;
    grafinho[a][b]=d;
    grafinho[b][a]=d;
  }

  for(int k=1; k<=s; k++)
  for(int i=1; i<=s; i++)
  for(int j=1; j<=s; j++)
  grafinho[i][j] = min(grafinho[i][j], grafinho[i][k]+grafinho[k][j]);

  for(int i=1; i<=s; i++){
    ansx = grafinho[i][0];
    for(int j=1; j<=s; j++){
      if(grafinho[i][j]>ansx)
      ansx = grafinho[i][j];
    }
    if(ansx < ansy) ansy = ansx;
  }

  cout << ansy << endl;

  return 0;
}
