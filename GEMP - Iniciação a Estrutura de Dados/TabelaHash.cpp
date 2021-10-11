#include <iostream>

using namespace std;

typedef struct {
    int valor = -1;
    int chave = -1;
}Hash;


int main () {
    int n = 0, m = 0, c = 0;
    int i = 0, j = 0, k = 0;
    Hash hs[200];

    cin >> n;

    for(i = 0; i < n; i++) {
        cin >> m >> c;
        for (j = 0; j < c; j++) {
            cin >> hs[j].valor;
            hs[j].chave = hs[j].valor%m;
        }
        for (j = 0; j < m; j++) {
            cout << j << " -> ";
            for (k = 0; k < c; k++) {
                if (hs[k].chave == j) {
                    cout << hs[k].valor << " -> " ;
                }
            }
            cout << "\\" << endl;
        }
        if(i<n-1)
            cout << endl;
    }

    return 0;
}
