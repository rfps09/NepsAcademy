#include <iostream>

using namespace std;

int mCount[100001][10];
int ans[10];

int main() {
    int n = 0, m = 0;
    int aux = 0, start = 0, end = 0;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        cin >> aux;
        for(int j = 0; j < 10; j++) {
            mCount[i][j] = mCount[i-1][j];
        }
        mCount[i][aux]++;
    }

    cin >> end;

    for(int i = 1; i < m; i++) {
        cin >> end;
        aux = end;
        
        if(start > end) {
            start--;
            end--;
        }
        
        for(int j = 0; j < 10; j++) {
            ans[j] += abs(mCount[end][j] - mCount[start][j]);
        }
        
        start = aux;
    }
    
    for(int i = 0; i < 10; i++) {
        cout << ans[i] << " ";
    }
    
    cout << endl;

    return 0;
}
