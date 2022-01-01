#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100001;

int main() {
    int n = 0, m = 0, a = 0, b = 0, t = 0, v = 1;
    vector<int> grafinho[MAXN];
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> t >> a >> b;
        
        if(t == 1) {
            grafinho[a].push_back(b);
            grafinho[b].push_back(a);
        } else {
            for(int j = 0; j < grafinho[a].size(); j++) {
                if(grafinho[a].at(j) == b) {
                    v = 0;
                    break;
                }
            }
            if(v == 0) cout << 1 << endl;
            else cout << 0 << endl;
            v = 1;
        }
    }

    return 0;
}
