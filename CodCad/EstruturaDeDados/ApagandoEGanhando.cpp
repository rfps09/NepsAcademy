#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN(1E5);

int main() {
    int n = 0, d = 0, index = 0, count = 0, maior = 0, del = 0;
    string num;
    vector<int> aux (MAXN);
    queue<int> fila;

    while(cin >> n >> d && n && d) {
        del = d;
        cin.get();

        getline(cin, num);
        
        for(int i = 0; i < n; i++) {
            aux[i] = num[i]-'0';
        }

        while(fila.size() != n-d) {
            for(int i = count; i <= del+count; i++) {
                if(aux[i] > maior) {
                    maior = aux[i];
                    index = i;
                }
            }

            fila.push(maior);
            del = del - (index - count);
            count = index + 1;
            maior = 0;
        }
        
        for(int i = 0; i < n-d; i++) {
            cout << fila.front();
            fila.pop();
        }
        
        cout << endl;

        index = 0, count = 0, maior = 0, del = 0;
    }

    return 0;
}
